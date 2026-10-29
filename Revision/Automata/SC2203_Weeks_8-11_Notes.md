# SC2203 Weeks 8 to 11: Complexity Theory Notes

These notes cover Lectures 8 to 11 (Pranjal Dutta), the scope of the Week 12 in-class MCQ quiz. They run in the order of the course: measuring complexity (Week 8), the classes P and NP (Weeks 9 and 10), reductions (Week 10), and SAT with NP-completeness and Cook-Levin (Week 11). Priority tags mark how central each idea is: **[MAJOR]** ideas anchor multiple questions, **[MINOR]** ideas support them, and **[TERTIARY]** ideas are details that usually appear as distractors or one-off items.

---

# Week 8: Measuring Complexity

## 8.1 Why complexity theory exists **[MINOR]**

The **Church-Turing thesis** says anything effectively computable is computable by a Turing machine, but **feasibility** is a separate question: a computable problem may need astronomical time or space. **Complexity theory** (formalized in the 1960s) measures resources and separates efficient from inefficient computation. It unifies problems through **reductions** and leads to the **P vs. NP** question, a Millennium Prize Problem. This course measures **time** only, not space.

## 8.2 Decision problems and languages **[MAJOR]**

Most of complexity theory studies **decision problems**, which ask only for a YES or NO. An optimization problem is **reposed** as a decision problem by adding a threshold. For example, the shortest path problem SP asks for the length of a shortest s-t path, while SPdec asks whether there is an s-t path of total length at most k.

If the decision problem is hard, the associated optimization problem is also hard. Conversely, **self-reducibility** means an algorithm for the decision problem can solve the optimization problem: **binary search** on k finds the smallest k for which SPdec answers YES.

A **decision problem corresponds to a language**: instances are encoded as strings, and the YES instances form the language. For example, PATH = {⟨G, s, t⟩ : G has a path from s to t}. An **algorithm corresponds to a Turing machine**, and a TM accepting the language is an algorithm solving the problem.

## 8.3 Time complexity of Turing machines **[MAJOR]**

The model is a deterministic **k-tape TM**. The **input size** n is the length of the input string, and the **time** is the number of computation steps. Analysis is **worst case**: the maximum over all inputs of size n.

A TM M is **T(n) time-bounded** if for every input w of length n, M(w) halts within T(n) steps.

**DTIME(T(n))** is the set of languages decidable by a deterministic O(T(n)) time-bounded TM. For example, DTIME(n) is linear time, DTIME(n²) is quadratic time, and DTIME(2ⁿ) is exponential time.

## 8.4 Robustness theorems **[MAJOR]**

The **Linear Speedup Theorem** says that for any constant c > 0, a T(n)-time TM can be replaced by a T(n)/c-time TM accepting the same language, so DTIME(T(n)) = DTIME(cT(n)). Constants do not matter for complexity classes.

The **Tape Reduction Theorem** says a k-tape TM running in time T(n) can be simulated by a single-tape TM in time T(n)². The number of tapes costs at most a quadratic slowdown, so complexity theory is robust across reasonable models.

## 8.5 Time Hierarchy Theorem **[MAJOR]**

If lim (n→∞) T₁(n) log T₁(n) / T₂(n) = 0, then DTIME(T₁(n)) ⊊ DTIME(T₂(n)). The functions must be **time-constructible**, meaning a TM can compute T(n) within O(T(n)) time. More time gives more power: for any 0 < a < b, DTIME(nᵃ) ⊊ DTIME(nᵇ). The slides' chain is

DTIME(n) ⊊ DTIME(n^1.5) ⊊ DTIME(n²) ⊊ DTIME(n³) ⊊ DTIME(2ⁿ).

## 8.6 Big-O refresher **[MAJOR]**

Let T and f map ℕ to ℝ⁺.

**O (upper bound):** T(n) = O(f(n)) if there exist c > 0 and n₀ such that T(n) ≤ c·f(n) for all n ≥ n₀. Example: 1000n + 100 = O(n), using c = 1001 and n₀ = 100.

**Ω (lower bound):** T(n) = Ω(f(n)) if there exist ε > 0 and n₀ such that T(n) ≥ ε·f(n) for all n ≥ n₀.

**Θ (tight bound):** T(n) = Θ(f(n)) if T(n) is both O(f(n)) and Ω(f(n)).

For T(n) = pn² + qn + r with p, q, r > 0, we have T(n) = Θ(n²). It is also correct to write O(n³) and Ω(n), but it is neither Θ(n) nor Θ(n³). A degree-d polynomial is Θ(nᵈ), determined by its highest-degree term. An algorithm is **polynomial-time** if its running time is O(nᵈ) for some constant d.

**Logs versus powers:** log_a n = Θ(log_b n) because the bases differ by a constant factor, and log n = O(n^ε) for every ε > 0. **Exponentials dominate polynomials:** for every r > 1 and d > 0, nᵈ = O(rⁿ). For instance n⁶ = O(1.1ⁿ), since n⁶ < 1.1ⁿ for n ≥ 373.

| Notation | Name |
|---|---|
| O(1) | Constant |
| O(log n) | Logarithmic |
| O(n) | Linear |
| O(n log n) | Linearithmic |
| O(n²) | Quadratic |
| O(n³) | Cubic |
| O(nᵏ) | Polynomial |
| O(2ⁿ) | Exponential |

The hierarchy is 1 ≺ log n ≺ n ≺ n log n ≺ n² ≺ nᵏ ≺ 2ⁿ.

## 8.7 Algorithm analysis versus problem complexity **[TERTIARY]**

**Algorithm analysis** asks how efficient a specific algorithm is (quicksort runs in O(n log n) average time). **Problem complexity** asks for the best possible algorithm (comparison-based sorting needs Ω(n log n)). Upper bounds come from algorithms, and lower bounds are impossibility results.

---

# Week 9: The Class P and the Definition of NP

## 9.1 Definition of P **[MAJOR]**

**P = ⋃ₖ≥₀ DTIME(nᵏ)**, the class of languages decided by deterministic polynomial-time algorithms. Polynomial time is the standard formalization of "efficient" for four reasons. Polynomial growth is realistic compared with exponential growth (for n = 1000, n³ = 10⁹ but 2ⁿ ≈ 10³⁰¹). Polynomial bounds are **model independent**. P is **closed under composition**, since poly(poly(n)) = poly(n); for example, p₁(n) = n² composed with p₂(n) = n³ gives n⁶. Finally, most practical algorithms are polynomial.

The caveat is that not every polynomial algorithm is practical, such as one running in n¹⁰⁰.

## 9.2 Polynomial equivalence of models **[MINOR]**

Single-tape and multi-tape TMs differ by at most a quadratic slowdown, a TM and a RAM machine simulate each other in polynomial time, and different programming languages differ by polynomial compilation overhead. Hence **P does not depend on the model**, and we may design polynomial-time algorithms in high-level pseudocode.

## 9.3 Input length: bits versus value **[MAJOR]**

Time is measured against the **length** of the input. A number N in binary has length n = ⌈log₂(N+1)⌉, so N ≈ 2ⁿ can be exponentially larger than n. For example, 15 is 1111 and needs ⌈log₂ 16⌉ = 4 bits. Adding integers a and b takes O(log a + log b) bit operations, which is linear in the input length.

## 9.4 Examples in P **[MAJOR]**

**PATH** (is there a directed path from s to t?) is solved by **BFS or DFS** in O(V + E) = O(n²) for n = |V|, so PATH ∈ P.

**CONNECTED** (is an undirected graph connected?) is solved by running DFS from any vertex and checking that all vertices are visited, O(V + E). An alternative is to run PATH on all pairs (u, v), costing O(n² · T(PATH)), which is still polynomial.

**MODEXP** takes binary integers a, b, c, p and asks whether aᵇ ≡ c (mod p). The naive algorithm performs O(b) multiplications modulo p, and since b can be as large as p, which is exponential in the input length O(log p), it is **not polynomial**. **Exponentiation by squaring** uses

xⁿ = (xⁿ/²)² if n is even, and xⁿ = x · (x⁽ⁿ⁻¹⁾/²)² if n is odd.

This needs only **O(log b) multiplications**, each costing O(log² p) time, so MODEXP ∈ P. A worked chain from the slides: x²⁵ = x · (x¹²)², x¹² = (x⁶)², x⁶ = (x³)², x³ = x · (x¹)².

## 9.5 Recipe for showing L ∈ P **[MINOR]**

Describe a polynomial-time algorithm, analyze its time complexity, and verify the bound is polynomial in the **input size**.

## 9.6 Closure properties of P **[MINOR]**

P is closed under **union**, **concatenation**, **Kleene star**, and **complement**. For union, run A₁ on w and accept if it accepts, otherwise run A₂, with total time O(p₁(n) + p₂(n)). For complement, run the decider and flip its answer, with the same time.

## 9.7 What is not obviously in P **[TERTIARY]**

**Integer factoring** has sub-exponential but super-polynomial best known algorithms, and RSA-style cryptography relies on its hardness. **Linear programming** was first solved by the **simplex method**, which is exponential in the worst case but fast in practice, and was later shown to be in P by the **ellipsoid** and **interior-point** methods.

## 9.8 Motivation for NP **[MAJOR]**

For many hard problems (integer factorization, Sudoku), **finding** a solution seems very difficult while **verifying** a given solution is easy. This asymmetry motivates nondeterministic computation.

## 9.9 Nondeterministic TMs and NTIME **[MAJOR]**

A deterministic TM has δ(q, a) = (q′, b, D), a single next move. A **nondeterministic TM (NTM)** has δ(q, a) = {(q₁, b₁, D₁), (q₂, b₂, D₂), …}, a set of possible moves. An NTM **accepts** w if and only if there exists some sequence of choices leading to an accepting state, so it can "guess" the right path. The NTM is a **theoretical model**, and no physical implementation is known.

Every language accepted by an NTM is also accepted by a DTM. The DTM explores the computation tree breadth-first, and if the NTM runs in time T(n), the simulation takes **2^O(T(n))** time.

An NTM N is **T(n) time-bounded** if for every input of length n and every sequence of nondeterministic choices, N halts within T(n) steps. **NTIME(T(n))** is the set of languages accepted by an O(T(n)) time-bounded NTM, and the linear speedup theorem holds.

**NP = ⋃ₖ≥₀ NTIME(nᵏ)**, "nondeterministic polynomial time". P consists of decision problems with a deterministic polynomial-time algorithm, and NP of those with a nondeterministic polynomial-time algorithm. NP is a natural class because many important problems are in NP with no known polynomial algorithm.

---

# Week 10: Verifiers, Class Relations, and Reductions

## 10.1 Algorithm versus complexity **[TERTIARY]**

An algorithm is how you solve the problem, and complexity is how expensive that solution is.

## 10.2 Example: COMPOSITE **[MINOR]**

COMPOSITE takes a binary integer n and asks whether it is non-prime. A nondeterministic algorithm guesses an integer k with 1 < k < n, checks with polynomial-time division whether k divides n, and accepts if so. If n is composite some guess finds a factor, and if n is prime no guess does, so COMPOSITE ∈ NP.

## 10.3 The certificate/verifier definition **[MAJOR]**

A **verifier** for a language L is a deterministic algorithm V taking two inputs, with these properties.

- If w ∈ L, there **exists** a string c with |c| ≤ poly(|w|) such that V(w, c) accepts.
- If w ∉ L, for **all** strings c with |c| ≤ poly(|w|), V(w, c) rejects.

The string c is the **certificate**, also called a **witness** or **proof**, and is best thought of as a "hint". **L ∈ NP if and only if L has a polynomial-time verifier.**

The proof sketch has two directions. From NTM to verifier, use the accepting computation path as the certificate, and the verifier simulates the NTM deterministically along that path. From verifier to NTM, the NTM guesses a certificate and then runs the verifier, taking polynomial time for guessing plus polynomial time for verifying.

The **guess and verify** paradigm: nondeterminism guesses the solution, and deterministic computation checks it.

## 10.4 The three-question template for L ∈ NP **[MAJOR]**

To prove L ∈ NP, answer three questions. First, **what is the certificate** (a polynomial-size hint)? Second, **what does the verifier check** (polynomial-time checks)? Third, **why is the running time polynomial**?

## 10.5 Verifier examples **[MAJOR]**

**Longest-Path** (a simple path from s to t of length at least k): the certificate is a sequence of vertices v₁, …, v_r. The verifier checks v₁ = s and v_r = t, each consecutive pair is an edge, no vertex repeats (so the path is simple), and the length is at least k. The certificate has length at most |V|.

**Maximum Independent Set (decision)**: given G and k, is there a subset S with no edges inside S and |S| ≥ k? The certificate is the subset S, and the verifier checks |S| ≥ k and that no edge connects two vertices of S.

**Hamiltonian Cycle**: the certificate is a sequence of vertices, and the verifier checks that it is a valid cycle visiting every vertex exactly once.

**Subset Sum**: given integers x₁, …, x_n and k, the certificate is a subset, and the verifier sums it and compares with k.

**Sudoku**: the certificate is the completed grid (the slides left this as an exercise).

Other classical NP problems named in the slides: Clique, Vertex Cover, Hamiltonian Path, SAT, 3-SAT, integer factorization, discrete log, Knapsack, Bin Packing, Job Scheduling, Minesweeper, Tetris. The common pattern is easy to verify, hard to find.

## 10.6 Relating P, NP, and EXP **[MAJOR]**

**EXP** is the class of decision problems solvable in deterministic exponential time.

DTIME(f(n)) ⊆ NTIME(f(n)) because every deterministic TM is a special case of a nondeterministic one, so **P ⊆ NP**. NTIME(f(n)) ⊆ DTIME(2^O(f(n))) because a DTM simulation explores exponentially many paths, so **NP ⊆ EXP**. By the time hierarchy theorem **P ≠ EXP**, so **at least one of the two inclusions is strict**. Whether P = NP is open.

## 10.7 P versus NP **[MAJOR]**

If P = NP, there are efficient algorithms for 3-SAT, Longest-Path, and Sudoku. If P ≠ NP, no efficient algorithms exist for them. The problem is called "the most important open problem in computer science" and is one of the seven **Millennium Prize Problems** selected by the Clay Mathematics Institute in 2000, with a US$1 million prize. Most researchers believe P ≠ NP, but there is no proof. If P = NP, cryptography would collapse, many optimization problems would become tractable, and automated theorem proving would become efficient.

## 10.8 Reductions **[MAJOR]**

Informally, a reduction from A to B means that an algorithm for B yields an algorithm for A. For decision problems, a reduction is an algorithm that takes an instance I_A and outputs an instance I_B such that **I_B is a YES instance of B if and only if I_A is a YES instance of A**.

Write **A ≤ B** to say A is no harder than B, equivalently B is at least as hard as A. Reductions find algorithms and also show problems are hard.

A **polynomial-time reduction X ≤ᴾ Y** (also called a **Karp reduction**) is a reduction that runs in polynomial time. If X ≤ᴾ Y and Y ∈ P then X ∈ P. Reductions are **transitive**: X ≤ᴾ Y and Y ≤ᴾ Z imply X ≤ᴾ Z. Importantly, X ≤ᴾ Y does **not** imply Y ≤ᴾ X, so the FROM and TO directions matter. To prove X ≤ᴾ Y you reduce FROM X TO Y, showing that an algorithm for Y gives one for X.

**The three-question template for A ≤ᴾ B:** What is the transformation? Why is it correct, proving w ∈ A ⇔ f(w) ∈ B in both directions? Why is it polynomial time, arguing that the size of f(w) and the construction time are polynomial in |w|?

## 10.9 Independent Set ≤ᴾ Clique **[MAJOR]**

An **independent set** is a vertex set with no edge between any two of its vertices, and a **clique** is a vertex set in which every pair is joined by an edge. Given ⟨G, k⟩, the reduction outputs ⟨Ḡ, k⟩, where Ḡ is the **complement graph** with an edge (u, v) if and only if (u, v) is not an edge of G.

**Correctness lemma:** G has an independent set of size at least k if and only if Ḡ has a clique of size at least k, because S is independent in G if and only if S is a clique in Ḡ. The same argument gives Clique ≤ᴾ Independent Set. The meaning of Independent Set ≤ᴾ Clique is that a polynomial algorithm for Clique gives one for Independent Set, and Clique is at least as hard.

---

# Week 11: SAT, NP-Completeness, and Cook-Levin

## 11.1 Boolean formulas **[MAJOR]**

**Boolean variables** x₁, …, x_n take TRUE or FALSE (1 or 0), with operations AND (∧), OR (∨), and NOT (¬). A **literal** is a variable xᵢ or its negation ¬xᵢ. A **clause** is a disjunction (∨) of literals. A formula is in **conjunctive normal form (CNF)** if it is a conjunction (∧) of clauses. A formula is a **3CNF** formula if every clause has **exactly 3 distinct literals**.

For example, (x₁ ∨ x₂) ∧ (x₁ ∨ x₃ ∨ x₄) ∧ (x₂ ∨ x₄) is CNF, while (x₁ ∧ x₂) ∨ (x₃ ∧ x₄) is **not** CNF, and (x₁ ∨ x₂ ∨ x₄) ∧ (x₂ ∨ x₃) ∧ x₅ is CNF but not 3CNF.

## 11.2 SAT and 3SAT **[MAJOR]**

**SAT**: given a CNF formula φ, is there a truth assignment to its variables making φ true? **3SAT** is the same question restricted to 3CNF formulas. A formula is **satisfiable** if such an assignment exists. SAT is important because it is a basic constraint satisfaction problem, logical constraints are simple but expressive so many problems reduce to it, it arises in hardware and software verification, and it is fundamental to the theory of computing.

## 11.3 SAT versus 3SAT **[MAJOR]**

**3SAT ≤ᴾ SAT** is trivial because every 3CNF formula is a CNF formula, so SAT is at least as hard. The reverse **SAT ≤ᴾ 3SAT** also holds. Given φ, construct φ′ that is 3CNF, satisfiable if and only if φ is, and computable in polynomial time. The idea is to pad short clauses and break long ones.

**Two-literal clause** c = (ℓ₁ ∨ ℓ₂) with a fresh variable u:
T(c) = (ℓ₁ ∨ ℓ₂ ∨ u) ∧ (ℓ₁ ∨ ℓ₂ ∨ ¬u).

**One-literal clause** c = ℓ with fresh variables u, v:
T(c) = (ℓ ∨ u ∨ v) ∧ (ℓ ∨ u ∨ ¬v) ∧ (ℓ ∨ ¬u ∨ v) ∧ (ℓ ∨ ¬u ∨ ¬v).

**Clause with k > 3 literals** c = ℓ₁ ∨ … ∨ ℓ_k with fresh variables u₁, …, u_{k−3}:
T(c) = (ℓ₁ ∨ ℓ₂ ∨ u₁) ∧ (ℓ₃ ∨ ¬u₁ ∨ u₂) ∧ (ℓ₄ ∨ ¬u₂ ∨ u₃) ∧ … ∧ (ℓ_{k−2} ∨ ¬u_{k−4} ∨ u_{k−3}) ∧ (ℓ_{k−1} ∨ ℓ_k ∨ ¬u_{k−3}).

For k = 4 this is (ℓ₁ ∨ ℓ₂ ∨ u) ∧ (ℓ₃ ∨ ℓ₄ ∨ ¬u). Correctness for the 4-literal case: if c is satisfied, one of the pairs (ℓ₁ ∨ ℓ₂) or (ℓ₃ ∨ ℓ₄) holds, and u is set to satisfy the other clause. If T(c) is satisfied, each clause has a true literal, and u makes only one of the two clauses true by itself, so some ℓᵢ is true. Counting: a k-literal clause with k > 3 yields **k − 2 clauses** and **k − 3 new variables**.

The whole reduction sets φ′ = T(c₁) ∧ … ∧ T(c_m). A clause already having exactly 3 literals is kept unchanged, and fresh variables are used for one clause only. Since each clause is satisfiable exactly when its image is, φ is satisfiable if and only if φ′ is. The construction processes each clause separately and produces polynomial size, so it is polynomial-time.

## 11.4 NP-completeness and NP-hardness **[MAJOR]**

A problem X is **NP-complete** if (1) X ∈ NP and (2) **hardness**: for every Y ∈ NP, Y ≤ᴾ X. A problem X is **NP-hard** if condition (2) holds, with **no requirement that X ∈ NP**. The **Halting problem** is NP-hard but not NP-complete.

**Proposition:** if X is NP-complete, then X is solvable in polynomial time **if and only if P = NP**. (⇒) If X ∈ P, every Y ∈ NP reduces to X, so Y ∈ P, hence NP ⊆ P, and with P ⊆ NP we get P = NP. (⇐) If P = NP then X ∈ NP = P.

**Implications:** since we believe P ≠ NP, an NP-complete problem is unlikely to be efficiently solvable, and at the very least many smart people have failed to find an efficient algorithm.

## 11.5 The Cook-Levin theorem **[MAJOR]**

**Theorem (Cook 1971, Levin 1973): SAT is NP-complete.** Two things must be shown. **SAT ∈ NP** is easy, since the satisfying assignment is the certificate. **Every language in NP reduces to SAT** is hard, because there are infinitely many NP languages and a **generic reduction** is needed. Stephen Cook won the Turing Award for this theorem, and it established the first NP-complete problem.

**Setup.** If L ∈ NP then there is an NTM M and a polynomial p(·) such that L = {x : M accepts x in at most p(|x|) steps}. The reduction f_M takes x and outputs a SAT formula f_M(x) in polynomial time such that **x ∈ L ⇔ f_M(x) is satisfiable**. The formula encodes the computation of M on x, and a satisfying assignment reveals the accepting computation: state, tape contents, head position, and the nondeterministic choice at each step.

**Computation tableau.** Row i gives the contents of all cells at time i. At time 0 the tape holds x followed by blanks. The table has size **p(|x|) × p(|x|)**.

**Four variable families.**

- **T(b, h, i)** is true iff tape cell h holds symbol b at time i.
- **H(h, i)** is true iff the head is at position h at time i.
- **S(q, i)** is true iff the state is q at time i.
- **I(j, i)** is true iff transition (instruction) number j is executed at time i, where the j-th transition is ⟨q_j, b_j, q′_j, b′_j, d_j⟩ with d_j ∈ {−1, 0, 1}.

The total number of variables is **O(p(|x|)²)**.

**Notation.** The abbreviation **L(x₁, …, x_m)** means "exactly one of x₁, …, x_m is true" and converts to CNF as (x₁ ∨ … ∨ x_m) ∧ ⋀_{i<j}(¬xᵢ ∨ ¬xⱼ).

**Eight clause groups**, f_M(x) = φ₁ ∧ φ₂ ∧ … ∧ φ₈:

| Group | Meaning |
|---|---|
| φ₁ | **Initial configuration**: state q₀ at time 0, tape holds x then blanks, head at position 1 |
| φ₂ | **Unique state** at each time (exactly one S(q, i)) |
| φ₃ | **Unique symbol** in each cell at each time |
| φ₄ | **Unique head position** at each time |
| φ₅ | **Acceptance**: the accept state appears at some time, φ₅ = ⋁ᵢ S(q_a, i). It is **the only group with a top-level OR** |
| φ₆ | **Unique instruction** executed at each time (handles nondeterminism) |
| φ₇ | **Cells away from the head do not change** |
| φ₈ | **Valid transitions**: if instruction j runs at time i then the state, scanned symbol, written symbol, next state, and head movement all agree with the j-th transition |

The two-part formulation of φ₇ is that if the head is not at h at time i, the symbol at h at time i + 1 equals the one at time i. The five parts of φ₈ enforce the current state, the next state, the symbol read, the symbol written, and the head move.

**Correctness and size.** The formula has O(p(|x|)²) variables and clauses, each of constant size, and is built in O(p(|x|)²) time. Forward direction: if M accepts x, set the variables from the accepting computation tableau, which satisfies every φᵢ. Backward direction: a satisfying assignment specifies a complete valid computation that accepts, so M accepts x.

## 11.6 Proving a new problem NP-complete **[MAJOR]**

To prove X is NP-complete, show **X ∈ NP** and give a polynomial-time reduction **from** a known NP-complete problem S (such as SAT) **to** X, so S ≤ᴾ X. The reason this suffices is **transitivity**: for any Y ∈ NP we have Y ≤ᴾ S and S ≤ᴾ X, so Y ≤ᴾ X.

## 11.7 3SAT is NP-complete **[MAJOR]**

3SAT ∈ NP because a satisfying assignment is the certificate. We showed SAT ≤ᴾ 3SAT, and SAT is NP-complete by Cook-Levin, so 3SAT is NP-complete.

## 11.8 The web of NP-complete problems **[MINOR]**

The slides list this chain of reductions, each starting from a known NP-complete problem:

SAT is NP-complete (Cook-Levin); SAT ≤ᴾ 3SAT; 3SAT ≤ᴾ Independent Set; Independent Set ≤ᴾ Clique; Independent Set ≤ᴾ Vertex Cover; 3SAT ≤ᴾ Hamiltonian Cycle; Hamiltonian Cycle ≤ᴾ Traveling Salesman Problem; 3SAT ≤ᴾ Subset Sum.

The Week 12 slide notes that many more NP-complete problems and reductions follow next week.

---

# One-Page Summary of the Big Ideas

Complexity is measured as a function of **input length** over worst-case inputs. **P** is deterministic polynomial time and **NP** is nondeterministic polynomial time, equivalently the languages with polynomial-size, polynomial-time **verifiable certificates**. The inclusions are **P ⊆ NP ⊆ EXP**, with P ≠ EXP. A **polynomial-time reduction** X ≤ᴾ Y makes Y at least as hard as X. A problem is **NP-complete** if it is in NP and every NP problem reduces to it, so a polynomial algorithm for any NP-complete problem collapses NP to P. **Cook-Levin** proves SAT is NP-complete by encoding an NTM's polynomial-size computation tableau as a CNF formula, and reductions from SAT then give 3SAT and hundreds of other NP-complete problems.
