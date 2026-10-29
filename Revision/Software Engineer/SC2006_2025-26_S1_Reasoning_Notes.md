# SC2006 Sem 1 AY2025-26 — Reasoning and Things to Take Note Of

This file explains **why** each answer in `SC2006_2025-26_S1_Solutions.md` was built the way it was, what the examiner is probably rewarding, and which traps to avoid. Read it alongside the solutions.

---

## 0. Paper-level strategy

The paper has **four questions of equal marks (25 each)** and **2 hours**, so budget about **30 minutes per question** with a few minutes of slack. It is **open-book**, so the notes PDF is your reference for notation (include/extend arrows, Observer and Strategy structure, equivalence class and boundary rules, velocity formulas), but you will not have time to look things up repeatedly.

Everything is anchored to one case, the **Smart Home Control System**. The recurring tactic is to **quote the appendix**: "strict time window", "logs all activity", "administrators do not control devices", "may ask clarifying questions". Each of those phrases is a hook for a use case, a state, an alternative flow, a non-functional requirement or a pattern justification. Answers that reuse the case vocabulary score better than generic textbook answers.

The paper is diagram-heavy (use case, state machine, activity, class diagram twice, architecture). The Mermaid blocks in the solutions are for checking your understanding; by hand, focus on **correct notation first, completeness second, neatness third**.

---

## Question 1: Use case modelling (25 marks)

### 1(a) Use case diagram (18 marks, the single largest item)

**Finding actors.** Read the appendix paragraph by paragraph: one paragraph each for Homeowner, Guest and Administrator. Actors are people or external systems that interact with the system. I kept the **LLM assistant inside** the system boundary, because the appendix says the system is "powered by" it; it is a component, not an outside party. If you prefer, you could draw it as a secondary actor, but then explain why. The mobile app and the voice assistant are **interfaces**, not actors.

**Finding use cases.** Every verb phrase in the appendix is a candidate: dim lights, adjust AC, lock front door, grant and revoke guest access, unlock/lock doors, add/remove accounts, reset credentials, adjust access rights. Name use cases as **verb + noun** and keep them at user-goal level.

**Choosing `«include»` versus `«extend»`.** This is where most marks are won or lost.
- Use **`«include»`** when the sub-behaviour is **always** executed as part of the base: Access Door always includes authentication, time-window verification and logging; Process Voice Command always includes transcription and interpretation.
- Use **`«extend»`** when the behaviour is **optional or conditional**, triggered by a condition written on the arrow: Ask Clarifying Question extends Process Voice Command *only if the command is ambiguous*; Deny Access and Log Event extends Access Door *only if outside the time window*.
- Voice itself is modelled as an extension of the device-control and door-access use cases because the same goal can be reached through the app without voice.

**Arrow direction (frequent error).** `«include»`: from base **to** included. `«extend»`: from the extending use case **to** the base. Many students reverse the extend arrow.

**Generalization.** Dim Lights, Adjust AC and Lock/Unlock Door are specialisations of Control Home Device; the account-management use cases specialise Manage User Accounts. This reduces clutter and shows you know the hollow-triangle notation listed in your notes. Do not overdo it; 18 marks is a lot, but a diagram with 25 ovals and forty crossing lines is unreadable.

**Things to take note of:**
- Draw the **system boundary rectangle**; actors outside, use cases inside.
- The Administrator must **not** be linked to device control: the appendix explicitly says they do not control devices. Examiners test whether you read that sentence.
- Authentication is used by everything that needs identity. To avoid a wall of arrows, include it only from the main use cases and mention in a note that it applies to all.
- Quick sanity check: every use case should have an actor or be included/extended by one that does.

### 1(b) Use case description (7 marks)

The question lists the required elements: **Actors, Pre-conditions, Flow of events, Alternative flows**. Cover those four explicitly with those headings, because marks are allocated to them. Post-conditions are a bonus.

**Pre-conditions** are things that must already be true *before* the use case starts: a grant exists, the guest is registered and authenticated, the lock is online. They are not steps in the flow.

**Basic flow** is the happy path, numbered, one actor action or system response per step. Include the voice branch in step 2 so it is clearly "door access by a guest" in both app and voice form.

**Alternative flows** should each reference the **step where they branch** and say where they rejoin or end. The strongest and most case-specific alternative is the one the appendix gives you directly: outside the time window, deny the request **and log the event**. Add ambiguity (clarifying question), authentication failure and lock offline for completeness.

---

## Question 2: Behavioural diagrams and process (25 marks)

### 2(a) State machine (4 marks)

Only 4 marks, so do it quickly and cleanly. The object being modelled is the **temporary guest access controller**, so think about the lifecycle of a grant: not yet granted, granted but not started, active, expired, revoked. The key transitions come from the appendix: grant, start time, end time, revoke, and requests that are denied outside the window.

**Notation reminders from your notes:** rounded rectangles for states, labelled arrows for transitions (`event [guard] / action`), a **start dot** and an **end bullseye**, optional `entry /`, `do /`, `exit /` activities. A self-transition such as "request / deny and log" shows that the state does not change while the system still records the event. Both `Expired` and `Revoked` lead to the end state because nothing more can happen to that grant.

Do not mix this up with a state machine for the *door* (locked/unlocked). The question says guest access **controller**.

### 2(b) Activity diagram with swim lanes (8 marks)

Pick lanes from the **participants** in the process: Guest, Voice Assistant (LLM), Access Controller, Door Lock. Each action goes in the lane of whoever performs it. Cross-lane arrows show hand-offs.

What earns marks: a start and end node, correct **decision diamonds with guards** (ambiguous? authenticated? within window?), a **loop** for clarification, a **merge** before the final feedback to the guest, and both **success and failure paths**. The failure path (deny, log, announce) is the appendix requirement "denies the request and records the event in the log".

Common mistakes: drawing a sequence diagram (messages between lifelines) instead of an activity diagram (actions and control flow); omitting lanes after the question explicitly asked for them; forgetting that the denial path must also be logged.

### 2(c) Waterfall versus Agile (5 marks)

The question gives you the **three comparison criteria**: flexibility, customer involvement, delivery approach, plus **one advantage each**. A three-row table with one line for each model answers it exactly. Do not drift into listing every pro and con from your notes, since the brief is specific. Tie the advantages to something concrete (fixed regulatory requirements for Waterfall; early feedback for Agile).

### 2(d) Sprints (8 marks)

Four required items: **two advantages, two challenges, each with examples**. The word "examples" matters; an unexemplified answer will lose roughly half the marks. Use SHCS examples because they show application, not memorisation.

Choose advantages from: frequent working increments and feedback, adaptability via backlog re-prioritisation, predictability through velocity, continuous improvement through retrospectives. Choose challenges from: estimation difficulty and spillover, scope creep/mid-sprint changes, ceremony overhead, activities that do not fit a short time-box (hardware testing, integration), and dependence on a self-organising experienced team.

If the paper has an arithmetic twist (velocity, sprints needed), the formulas in your notes are: **Velocity = total points completed ÷ number of sprints**, and **Sprints needed = remaining points ÷ velocity**. They did not appear in this paper but are standard exam material.

---

## Question 3: Architecture and design (25 marks)

### 3(a)(i) Architecture and class diagram (8 marks)

**Why Three-Tier/Layered.** Your notes list candidates: Three-Tier, MVC, Layered, Client-Server, Pipe-and-Filter, SOA, Observer-based, Plugin. The case has two interchangeable clients (app and voice) needing the **same business rules**, and a clear Presentation / Application / Data split. Three-tier fits directly. MVC would also be defensible if you emphasised UI refresh, but the dominant concern in the case is shared, centrally enforced logic, so Layered/Three-tier is easier to justify.

**The class diagram must "reflect the architecture design".** That phrase is the grading hook. It means the classes must be visibly grouped by tier and dependencies must follow the layering: UI classes call controllers, controllers call repositories, never UI directly to data. I tagged each class with a tier stereotype for this reason. Also give **key attributes and methods** for every class (the question says "detailed"), not just class names.

Pitfalls: a class diagram that is just a bag of entity classes with no tiers; arrows from UI classes to the database; business rules such as time-window checking placed in the UI.

### 3(a)(ii) Non-functional requirement and alternative architecture (8 marks)

Two tasks: **identify one NFR** and **propose an alternative architecture** that addresses it. The word "one" is deliberate; naming three NFRs and not developing any is weaker than one NFR developed well.

**Why Security.** The system physically controls door locks, the appendix emphasises authentication, strict time windows and logs, and the LLM is a new attack surface (prompt injection, spoofed voice). Alternatives with some justification: availability/reliability (the lock must still work if the cloud is down), performance (LLM latency), privacy (voice recordings). If you pick one of these, adapt the architecture accordingly (e.g., a local hub with offline fallback for availability).

**The key design insight:** never let the LLM be the authority. It transforms speech into a structured intent; a **deterministic policy enforcement point** decides. This is the kind of reasoning that distinguishes a strong answer from a generic "add a firewall and encryption" answer.

**"Alternative" means different from your answer in (i).** Because (i) was a plain three-tier, the alternative adds a security gateway and splits the application tier into services with an isolated LLM service, which is a layered, service-oriented design. State the **trade-offs** (complexity, latency) because architecture questions always reward acknowledging cost.

### 3(b)(i) More than one design pattern together (6 marks)

The question demands a **scenario**, a **class diagram**, and **more than one pattern**. The scenario is a single story (guest unlocks door) in which three genuine problems appear: swappable rules per user type (**Strategy**), creating the right rule object (**Factory**), notifying several parties on state change (**Observer**).

Check your structures against your notes:
- **Observer:** Subject maintains observers (`attach`, `detach`, `notifyObservers`); Observer interface defines `update()`; concrete observers implement it. Aggregation from Subject to Observer.
- **Strategy:** Context (`AccessController`) holds a reference to the Strategy interface (`AccessPolicy`); concrete strategies implement it.
- **Factory:** a creator class returns the interface type, hiding concrete classes.

The user types given in Q4 (Administrator, Owner, Guest, One Time User) were reused to make the Strategy classes realistic and to keep the whole paper consistent. A one-sentence explanation of *which problem each pattern solves* is what makes the diagram "explain the scenario".

### 3(b)(ii) Critical evaluation (3 marks)

"Critically evaluate" means a **balanced argument with a position**, not a one-sided statement. The structure used: state agreement, give concrete costs of overuse (more classes, indirection, harder tracing, Facade turning into a god class), then qualify that the problem is overuse and not patterns, and give a decision rule (apply a pattern when a real variation or coupling problem exists). For 3 marks, 4 to 6 sentences is enough.

---

## Question 4: Testing and AI (25 marks)

### 4(a)(i) Equivalence classes (4 marks)

For each input, split the input space into **valid classes** and **invalid classes** according to the specification.

- **Name (ASCII):** valid = all characters in ASCII; invalid = contains non-ASCII. I added the empty string as an extra invalid class and said so as an assumption; stating assumptions is how you protect marks on ambiguous specifications.
- **Phone (8-digit integer in a range):** this is a **range input**, so three numeric classes (below, within, above) plus a **type** class (non-integer).
- **Expiry date:** a range input again, plus an "invalid date" class (e.g., 30 February).
- **User type:** a **discrete input** with four valid values and an "anything else" invalid class.

### 4(a)(ii) Boundaries (4 marks)

Your notes say boundary value testing applies to **range** inputs only. Per boundary, the question asks for **on, just below, just above**.
- Phone: boundaries 10000000 and 99999999.
- Date: boundaries 01-Jan-2025 and 31-Dec-2030 (inclusive interpretation; I gave the year-only alternative as a note).
- Name: the character-code boundary 127/128 is the natural one.
- User type: **no boundaries**, because it is discrete. Say this explicitly; it is probably a deliberate trap to see whether you know the discrete/range distinction in your notes.

Interpretation trap: "between 2025 and 2030" is ambiguous. Choose one, state it, and optionally give the other.

### 4(a)(iii) Defensive test cases (5 marks)

**Defensive testing** means deliberately sending invalid input to check that the system rejects it safely. The paper's phrase "order information" is a copy-paste slip from another exam; it means the user information. Mention that in one line so the marker sees you noticed.

The rule in your notes that decides the structure: **only one invalid input per test case**. Every invalid test therefore keeps the other three fields at valid baseline values. Valid test cases are allowed to combine several valid values (several boundaries in one row), which keeps the table short. A good table has columns for test ID, all four inputs, the class or boundary being covered and the expected result; the "covered" column shows the marker how the table traces back to (i) and (ii).

Check coverage: every valid class appears at least once; every invalid class has its own case; every boundary value appears at least once.

### 4(b) LLMs for testing (4 marks)

Four marks suggests about four distinct points with one explanation each. Strong points: generating test cases from requirements (equivalence classes, boundaries, alternative flows), generating unit tests with a coverage feedback loop, generating test data and expected outputs including adversarial voice commands, and UI/end-to-end scripting plus failure triage. A short **limitations** sentence (hallucinated oracles, non-determinism, need for human review) turns a good answer into a critical one.

### 4(c) Fully automated software development (8 marks)

"At least four challenges" with 8 marks: aim for **four to six, each with a one or two line explanation** rather than just titles. Cover distinct dimensions: requirements ambiguity, verification and hallucination, large-scale design and maintainability, security and safety, accountability and legal issues, non-determinism and integration. Tie at least one challenge back to the SHCS (for example the ambiguous "strict time window") to show application.

---

## Recurring mistakes checklist

- Reversing `«extend»` arrows, or using `«include»` for optional behaviour.
- Drawing the wrong diagram type (sequence instead of activity; state machine of the wrong object).
- Class diagram that ignores the architecture it is supposed to reflect.
- Giving class names without attributes and methods when "detailed" is requested.
- Multiple invalid inputs in a single test case.
- Applying boundary value testing to a discrete input.
- Skipping the stated assumptions when the specification is ambiguous.
- Answering "examples"/"critically evaluate" questions without examples or a balanced position.
- Spending too long on Q1(a) at the expense of Q4 (Q4 has the quickest marks).

---

## Suggested time plan (120 minutes)

| Question | Marks | Time |
|---|---|---|
| Q1 | 25 | 30 min |
| Q2 | 25 | 28 min |
| Q3 | 25 | 30 min |
| Q4 | 25 | 25 min |
| Review | – | 7 min |

*Hint for self-study:* redraw the use case diagram and the swim-lane activity diagram **from memory by hand** once, then compare with the Mermaid versions; the notation habits (arrow directions, guards, start and end nodes) are what you are really training.
