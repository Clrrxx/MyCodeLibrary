# SC2203 Weeks 8 to 11 Flashcards (Separated by Week)

Cards are grouped by lecture week, and within each week by priority. **Major** cards are the likeliest quiz material, **minor** cards support them, **tertiary** cards are details that tend to appear as distractors, and **trap** cards target common wrong beliefs. Cover the answer, say it aloud or write it by hand (the quiz is closed book and handwritten), then check yourself.

Contents: [Week 8](#week-8-measuring-complexity-and-asymptotics) | [Week 9](#week-9-the-class-p-and-nondeterminism) | [Week 10](#week-10-np-verifiers-and-reductions) | [Week 11](#week-11-sat-np-completeness-and-cook-levin)

---

# Week 8: Measuring Complexity and Asymptotics

## Major

**Q: What does it mean that complexity is measured against input length?**
A: Time is a function of the length n of the input string, measured in the worst case over all inputs of that length.

**Q: Define DTIME(T(n)).**
A: The set of languages decidable by a deterministic TM that is O(T(n)) time-bounded, measured in the worst case over inputs of length n.

**Q: State the Linear Speedup Theorem.**
A: For any constant c > 0, a T(n)-time TM can be replaced by a T(n)/c-time TM for the same language, so DTIME(T(n)) = DTIME(cT(n)). Constants do not matter.

**Q: State the Tape Reduction Theorem.**
A: A k-tape TM running in time T(n) can be simulated by a single-tape TM in time T(n)². The slowdown from extra tapes is at most quadratic.

**Q: State the Time Hierarchy Theorem and its side condition.**
A: If lim T₁(n) log T₁(n) / T₂(n) = 0, then DTIME(T₁(n)) ⊊ DTIME(T₂(n)). Both functions must be time-constructible. Consequence: DTIME(nᵃ) ⊊ DTIME(nᵇ) for 0 < a < b.

**Q: How is an optimization problem turned into a decision problem, and how do we get the optimum back?**
A: Add a threshold k (for shortest path, "is there a path of length ≤ k?"). Binary search on k with a decision oracle recovers the optimum. This is **self-reducibility**.

**Q: If the decision problem is hard, what about the optimization problem?**
A: It is also hard, since the optimization problem would solve the decision problem.

**Q: Define O, Ω, and Θ.**
A: T = O(f) if T(n) ≤ c·f(n) for all n ≥ n₀ with c > 0. T = Ω(f) if T(n) ≥ ε·f(n) for all n ≥ n₀ with ε > 0. T = Θ(f) if both hold.

**Q: For T(n) = pn² + qn + r with positive constants, which of O(n²), O(n³), Θ(n²), Θ(n³), Ω(n) are true?**
A: All except Θ(n³). It is Θ(n²), hence also O(n³) and Ω(n).

**Q: Order these growth rates: 2ⁿ, n log n, n², log n, n, nᵏ, 1.**
A: 1 ≺ log n ≺ n ≺ n log n ≺ n² ≺ nᵏ ≺ 2ⁿ.

## Minor

**Q: Why does complexity theory exist given the Church-Turing thesis?**
A: Computable does not mean feasible. Complexity theory measures time and space to separate efficient from inefficient computation, unifies problems by reductions, and leads to P vs. NP.

**Q: How does a decision problem relate to a language, and an algorithm to a TM?**
A: Instances are encoded as strings and the YES instances form the language. A TM accepting the language is an algorithm solving the problem.

**Q: Which model of computation is used in this complexity part, and what is measured?**
A: A deterministic k-tape TM, measuring time (steps) in the worst case over inputs of length n. Space is not covered.

**Q: When is a TM T(n) time-bounded?**
A: When for every input w of length n, M(w) halts within T(n) steps.

**Q: What is the polynomial-time criterion in Big-O terms?**
A: An algorithm is polynomial-time if its running time is O(nᵈ) for some constant d. A degree-d polynomial is Θ(nᵈ), determined by its highest-degree term.

## Tertiary

**Q: Difference between algorithm analysis and problem complexity?**
A: Algorithm analysis bounds a specific algorithm (quicksort O(n log n) average). Problem complexity asks about the best possible algorithm (comparison sorting needs Ω(n log n)). Upper bounds come from algorithms, lower bounds from impossibility.

**Q: Example showing n⁶ = O(1.1ⁿ)?**
A: n⁶ < 1.1ⁿ for n ≥ 373, so exponentials eventually dominate any polynomial.

**Q: Why are logarithm bases irrelevant in Big-O?**
A: log_a n = log_a b · log_b n, so they differ by a constant factor.

**Q: What is the Big-O witness for 1000n + 100 = O(n)?**
A: c = 1001 and n₀ = 100, since 1000n + 100 ≤ 1001n for n ≥ 100.

## Trap

**Q: True or false: the Time Hierarchy Theorem says DTIME(n) = DTIME(2n).**
A: False. DTIME(n) = DTIME(2n) holds by linear speedup (constants do not matter), while the hierarchy theorem gives strictness for genuinely larger bounds, such as DTIME(n) ⊊ DTIME(n²).

---

# Week 9: The Class P and Nondeterminism

## Major

**Q: Define P.**
A: P = ⋃ₖ DTIME(nᵏ), the languages decidable in deterministic polynomial time.

**Q: Why is polynomial time the standard notion of "efficient"?**
A: Polynomial growth is realistic compared with exponential growth, it is independent of the reasonable computational model, it is closed under composition (poly of poly is poly), and most practical algorithms are polynomial. The caveat is that a polynomial like n¹⁰⁰ is not practical.

**Q: Why does input length matter for numbers (bits versus value)?**
A: A number N in binary has length ⌈log₂(N+1)⌉, so N is about 2ⁿ. An algorithm taking O(N) steps is therefore exponential in the input length.

**Q: Why is the naive MODEXP algorithm not polynomial?**
A: It performs O(b) multiplications mod p, and b can be about p, which is exponential in the input length O(log p).

**Q: How does exponentiation by squaring solve MODEXP in polynomial time?**
A: Use xⁿ = (xⁿ/²)² for even n and xⁿ = x·(x⁽ⁿ⁻¹⁾/²)² for odd n. This needs O(log b) multiplications, each O(log² p), so MODEXP ∈ P.

**Q: Which algorithms show PATH and CONNECTED are in P, and what is the time?**
A: BFS or DFS, in O(V + E) = O(n²) for n vertices. For CONNECTED, run DFS from one vertex and check that every vertex was visited.

**Q: What is a nondeterministic TM and when does it accept?**
A: An NTM has δ(q, a) = a set of possible moves. It accepts w if and only if **some** sequence of choices leads to an accepting state.

**Q: Define NP in terms of NTIME.**
A: NP = ⋃ₖ NTIME(nᵏ), the languages accepted by nondeterministic polynomial-time TMs.

**Q: How long does a DTM take to simulate an NTM running in time T(n)?**
A: 2^O(T(n)), because the simulation explores the computation tree of exponentially many paths.

## Minor

**Q: Why is P robust across models?**
A: Single versus multi-tape TMs differ by at most a quadratic factor, TM and RAM simulate each other in polynomial time, and programming languages differ by polynomial overhead.

**Q: Name the closure properties of P.**
A: Union, concatenation, Kleene star, and complement.

**Q: How do you show P is closed under complement and union?**
A: Complement: run the decider and flip its answer. Union: run A₁, accept if it accepts, otherwise run A₂, with time O(p₁(n) + p₂(n)).

**Q: What is the recipe for showing L ∈ P?**
A: Give a polynomial-time algorithm, analyze its running time, and check the bound is polynomial in the input size.

**Q: What asymmetry motivates NP?**
A: Finding a solution seems hard while verifying a given solution is easy (factoring, Sudoku).

**Q: Is the NTM a physically realizable machine?**
A: No. It is a theoretical model with no known physical implementation.

**Q: Define NTIME(T(n)) and an NTM being T(n) time-bounded.**
A: An NTM is T(n) time-bounded if for every input of length n and every sequence of choices it halts within T(n) steps. NTIME(T(n)) is the set of languages accepted by an O(T(n)) time-bounded NTM.

**Q: How does a DTM simulate an NTM, in outline?**
A: It views the computation as a tree of configurations and explores all paths breadth-first, accepting if any path reaches acceptance.

## Tertiary

**Q: What is the length of 15 in binary and what does it show?**
A: 1111, which is 4 = ⌈log₂ 16⌉ bits. Input length is logarithmic in the value.

**Q: Why is factoring not known to be in P, and what relies on it?**
A: Best known algorithms are sub-exponential but super-polynomial. RSA cryptography relies on its hardness.

**Q: Linear programming: simplex versus ellipsoid?**
A: The simplex method is exponential in the worst case but fast in practice. The ellipsoid and interior-point methods show linear programming is in P.

**Q: What is the worked squaring chain for x²⁵?**
A: x²⁵ = x·(x¹²)², x¹² = (x⁶)², x⁶ = (x³)², x³ = x·(x¹)².

## Trap

**Q: True or false: an algorithm that runs in O(N) for numeric value N is polynomial.**
A: False. Polynomial is measured in the bit length n ≈ log N, so O(N) is exponential in n.

**Q: True or false: an NTM can recognize more languages than a DTM, so it is a physical speedup.**
A: False on both counts in this setting. A DTM can simulate any NTM (at exponential cost), and the NTM is a theoretical model only.

---

# Week 10: NP, Verifiers, and Reductions

## Major

**Q: Define a verifier and the conditions it must meet.**
A: A verifier for L is a deterministic algorithm V(w, c). If w ∈ L, some certificate c with |c| ≤ poly(|w|) makes V accept. If w ∉ L, every certificate with |c| ≤ poly(|w|) makes V reject.

**Q: State the equivalence of the two definitions of NP.**
A: L ∈ NP if and only if L has a polynomial-time verifier. The NTM guesses the certificate then verifies; conversely, the accepting path of an NTM serves as the certificate.

**Q: What are the three questions for proving L ∈ NP?**
A: What is the certificate (a polynomial-size hint)? What does the verifier check (the polynomial-time checks)? Why is the running time polynomial?

**Q: Give the certificate and checks for Longest-Path.**
A: Certificate: a sequence of vertices v₁, …, v_r. Checks: v₁ = s and v_r = t, each consecutive pair is an edge, no vertex repeats, and the length is at least k. The certificate has size at most |V|.

**Q: Give the certificate and checks for Independent Set (size ≥ k).**
A: Certificate: a subset S ⊆ V. Checks: |S| ≥ k and no edge joins two vertices of S.

**Q: Give the certificate and checks for COMPOSITE, Hamiltonian Cycle, and Subset Sum.**
A: COMPOSITE: a factor k with 1 < k < n, check that k divides n. Hamiltonian Cycle: a vertex sequence, check it is a cycle visiting every vertex once. Subset Sum: a subset, check that it sums to k.

**Q: State the relationships among P, NP, and EXP.**
A: P ⊆ NP ⊆ EXP, and P ≠ EXP by the time hierarchy theorem. So at least one of the two inclusions is strict. Whether P = NP is open.

**Q: Why is P ⊆ NP, and why is NP ⊆ EXP?**
A: A deterministic TM is a special case of an NTM. And NTIME(f(n)) ⊆ DTIME(2^O(f(n))) because a DTM can simulate all exponentially many branches.

**Q: What would follow from P = NP, and what from P ≠ NP?**
A: P = NP gives efficient algorithms for 3-SAT, Longest-Path, Sudoku and collapses cryptography. P ≠ NP means no efficient algorithms exist for those problems.

**Q: Define a polynomial-time (Karp) reduction X ≤ᴾ Y.**
A: A polynomial-time algorithm mapping an instance I_X of X to an instance I_Y of Y such that I_X is a YES instance if and only if I_Y is a YES instance.

**Q: What does X ≤ᴾ Y tell you about relative hardness?**
A: X is no harder than Y, equivalently Y is at least as hard as X. A polynomial algorithm for Y gives one for X.

**Q: If X ≤ᴾ Y and Y ∈ P, what follows? If X ≤ᴾ Y and X is hard?**
A: X ∈ P. And Y is also hard (at least as hard as X).

**Q: Is X ≤ᴾ Y the same as Y ≤ᴾ X?**
A: No. The implication does not hold in general, so the FROM and TO of a reduction matter.

**Q: State transitivity of reductions.**
A: X ≤ᴾ Y and Y ≤ᴾ Z imply X ≤ᴾ Z.

**Q: What are the three questions for proving A ≤ᴾ B?**
A: What is the transformation? Why is it correct (w ∈ A ⇔ f(w) ∈ B, both directions)? Why is it polynomial time (size of f(w) and construction time are polynomial in |w|)?

**Q: Describe the reduction Independent Set ≤ᴾ Clique and why it is correct.**
A: Map ⟨G, k⟩ to ⟨Ḡ, k⟩ where Ḡ is the complement graph (edge uv iff uv is not an edge of G). A set S is independent in G if and only if S is a clique in Ḡ.

## Minor

**Q: Why is COMPOSITE in NP via a nondeterministic algorithm?**
A: Guess k with 1 < k < n and check divisibility in polynomial time. A composite n has some accepting guess; a prime n has none.

**Q: What does the guess-and-verify paradigm say?**
A: Nondeterminism guesses a certificate, and a deterministic polynomial-time check validates it.

**Q: Define an independent set and a clique.**
A: An independent set is a vertex set with no edge between any two of its vertices. A clique is a vertex set in which every pair is joined by an edge.

**Q: Define EXP and what is known about it relative to P.**
A: EXP is the class of decision problems solvable in deterministic exponential time. P ≠ EXP by the time hierarchy theorem.

**Q: What does Independent Set ≤ᴾ Clique mean practically?**
A: A polynomial-time algorithm for Clique would give one for Independent Set, so Clique is at least as hard. The same argument gives Clique ≤ᴾ Independent Set.

**Q: What are the Karp reduction naming conventions?**
A: A polynomial-time many-one reduction of decision problems, the standard kind used in this course.

## Tertiary

**Q: What is the difference between an algorithm and its complexity?**
A: An algorithm is how you solve the problem; complexity is how expensive that solution is.

**Q: What prize is attached to P vs. NP and who awards it?**
A: A US$1 million prize from the Clay Mathematics Institute, one of seven Millennium Prize Problems selected in 2000.

**Q: Name some problem families listed as being in NP.**
A: Graph problems (Independent Set, Clique, Vertex Cover, Hamiltonian Path), logic (SAT, 3-SAT), number theory (factorization, discrete log), optimization (Knapsack, Bin Packing, Job Scheduling), games (Sudoku, Minesweeper, Tetris).

**Q: What is the common pattern among classical NP problems?**
A: Easy to verify solutions, hard to find them.

**Q: What does the slide say most researchers believe about P vs. NP?**
A: Most believe P ≠ NP, but there is no proof.

## Trap

**Q: True or false: if X ≤ᴾ Y then Y ≤ᴾ X.**
A: False. Direction matters.

**Q: True or false: NP means "not polynomial".**
A: False. NP is **nondeterministic** polynomial time, and P ⊆ NP.

**Q: True or false: to show a verifier works for a NO instance, one bad certificate must be rejected.**
A: False. For w ∉ L, **every** polynomial-size certificate must be rejected.

---

# Week 11: SAT, NP-Completeness, and Cook-Levin

## Major

**Q: Define literal, clause, CNF, and 3CNF.**
A: A literal is a variable or its negation. A clause is a disjunction of literals. CNF is a conjunction of clauses. 3CNF requires every clause to have exactly 3 distinct literals.

**Q: Is (x₁ ∧ x₂) ∨ (x₃ ∧ x₄) in CNF?**
A: No. It is a disjunction of conjunctions, the opposite shape.

**Q: Define SAT and 3SAT.**
A: SAT: given a CNF formula, is there a truth assignment making it true? 3SAT is the same for 3CNF formulas.

**Q: Which direction between SAT and 3SAT is trivial, and which needs a construction?**
A: 3SAT ≤ᴾ SAT is trivial since every 3CNF formula is CNF. SAT ≤ᴾ 3SAT needs the clause-padding and clause-splitting construction.

**Q: How is a 2-literal clause (ℓ₁ ∨ ℓ₂) converted to 3CNF?**
A: With a fresh u: (ℓ₁ ∨ ℓ₂ ∨ u) ∧ (ℓ₁ ∨ ℓ₂ ∨ ¬u).

**Q: How is a 1-literal clause ℓ converted to 3CNF?**
A: With fresh u and v: (ℓ ∨ u ∨ v) ∧ (ℓ ∨ u ∨ ¬v) ∧ (ℓ ∨ ¬u ∨ v) ∧ (ℓ ∨ ¬u ∨ ¬v). That is 4 clauses and 2 new variables.

**Q: How is a k-literal clause with k > 3 converted, and how many new variables and clauses result?**
A: Chain it: (ℓ₁ ∨ ℓ₂ ∨ u₁) ∧ (ℓ₃ ∨ ¬u₁ ∨ u₂) ∧ … ∧ (ℓ_{k−1} ∨ ℓ_k ∨ ¬u_{k−3}). It uses k − 3 new variables and k − 2 clauses. A 6-literal clause gives 3 new variables and 4 clauses.

**Q: Why is the whole SAT ≤ᴾ 3SAT reduction polynomial and correct?**
A: Each clause is replaced independently by a gadget that is satisfiable exactly when the clause is, using fresh variables private to that clause. Each gadget has polynomial size, so φ′ = T(c₁) ∧ … ∧ T(c_m) is polynomial in size and satisfiable iff φ is.

**Q: Define NP-complete.**
A: X is NP-complete if X ∈ NP and every Y ∈ NP satisfies Y ≤ᴾ X.

**Q: Define NP-hard, and how it differs from NP-complete.**
A: X is NP-hard if every Y ∈ NP reduces to X. An NP-hard problem need not be in NP. The Halting problem is NP-hard but not NP-complete.

**Q: When can an NP-complete problem X be solved in polynomial time?**
A: If and only if P = NP.

**Q: How do you prove a new problem X is NP-complete, and why does it work?**
A: Show X ∈ NP and reduce **from** a known NP-complete problem S to X. By transitivity, every Y ∈ NP satisfies Y ≤ᴾ S ≤ᴾ X.

**Q: State the Cook-Levin theorem and its two parts.**
A: SAT is NP-complete. Part 1: SAT ∈ NP, the satisfying assignment is the certificate (easy). Part 2: every NP language reduces to SAT via a generic reduction (hard).

**Q: What is the proof idea of Cook-Levin?**
A: For L ∈ NP decided by an NTM N in time p(n), map x to a formula φ that encodes the computation tableau of N on x, so φ is satisfiable if and only if N accepts x. A satisfying assignment corresponds to an accepting computation.

**Q: How large is the computation tableau, and how many variables and clauses does the formula have?**
A: The tableau is p(|x|) × p(|x|), and the formula has O(p(|x|)²) variables and O(p(|x|)²) clauses, each of constant size.

**Q: Why is 3SAT NP-complete?**
A: 3SAT ∈ NP (the assignment is a certificate), SAT is NP-complete by Cook-Levin, and SAT ≤ᴾ 3SAT.

## Minor

**Q: Why is the SAT satisfying assignment a certificate in the NP sense?**
A: It has linear size in the formula, and checking that every clause has a true literal takes polynomial time.

**Q: Why does 3SAT ≤ᴾ Independent Set matter for the web of NP-complete problems?**
A: It feeds the chain 3SAT ≤ᴾ Independent Set, then Independent Set ≤ᴾ Clique and Independent Set ≤ᴾ Vertex Cover, showing hardness spreads along reductions.

**Q: What are the four variable families in the Cook-Levin formula?**
A: T(b, h, i) for cell h holding b at time i, H(h, i) for head position, S(q, i) for state, and I(j, i) for the instruction executed.

**Q: How is "exactly one of x₁, …, x_m" written in CNF?**
A: (x₁ ∨ … ∨ x_m) ∧ ⋀_{i<j}(¬xᵢ ∨ ¬xⱼ): at least one, and no two together.

**Q: What do φ₁ through φ₄ enforce?**
A: φ₁: the initial configuration (state q₀, input then blanks, head at 1). φ₂: exactly one state per time. φ₃: exactly one symbol per cell per time. φ₄: exactly one head position per time.

**Q: What do φ₅ through φ₈ enforce?**
A: φ₅: the accept state occurs at some time. φ₆: exactly one instruction per time. φ₇: cells not under the head do not change. φ₈: changes follow the transition function.

**Q: Which Cook-Levin group has a top-level OR, and why?**
A: φ₅, acceptance: ⋁ᵢ S(q_a, i), because the machine only needs to reach the accept state at some time.

**Q: What are the forward and backward directions of Cook-Levin correctness?**
A: Forward: an accepting computation gives a satisfying assignment by filling in the tableau. Backward: a satisfying assignment encodes a valid accepting computation, so M accepts x.

**Q: Why is SAT important?**
A: It is a basic constraint satisfaction problem, logical constraints are simple but expressive so many problems reduce to it, it arises in hardware and software verification, and it is fundamental to the theory of computing.

## Tertiary

**Q: Who proved what, and when, for the first NP-complete problem?**
A: Cook (1971) and Levin (1973) proved SAT is NP-complete. Cook won the Turing Award for it.

**Q: Which problems appear in the slide's list of reductions after SAT ≤ᴾ 3SAT?**
A: 3SAT ≤ᴾ Independent Set, Independent Set ≤ᴾ Clique, Independent Set ≤ᴾ Vertex Cover, 3SAT ≤ᴾ Hamiltonian Cycle, Hamiltonian Cycle ≤ᴾ TSP, 3SAT ≤ᴾ Subset Sum.

**Q: What is the benefit of believing P ≠ NP for an NP-complete X?**
A: X is unlikely to be efficiently solvable, and many smart people have failed to find an efficient algorithm for it.

**Q: What is the 4-literal clause example?**
A: (ℓ₁ ∨ ℓ₂ ∨ ℓ₃ ∨ ℓ₄) becomes (ℓ₁ ∨ ℓ₂ ∨ u) ∧ (ℓ₃ ∨ ℓ₄ ∨ ¬u).

## Trap

**Q: True or false: an NP-hard problem must be in NP.**
A: False. NP-hardness has no membership requirement.

**Q: True or false: to prove X NP-hard, reduce X to a known NP-hard problem.**
A: False. Reduce **from** a known NP-hard problem **to** X.

**Q: True or false: it suffices to give a satisfying assignment to prove a formula is unsatisfiable.**
A: False. To show unsatisfiability, every assignment must fail, and an assignment certifies only satisfiability.

**Q: True or false: 3SAT clauses may have fewer than 3 literals.**
A: False. A 3CNF clause has exactly 3 distinct literals.
