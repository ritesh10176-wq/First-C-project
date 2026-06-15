
```markdown
# Custom Scientific Calculator

> **A Semester-1 / First Project**
> *Translating calculus lectures directly into native C code—approximating functions from scratch without `<math.h>`*

---

## Project Structure

```text
📂 C-PROJECTS/
└── 📂 Custom_scientific_calculator/
    ├── 📂 devlepment_history/
    │   ├── 📄 Scientific_cal_prototype1.c
    │   ├── 📄 Scientific_cal_prototype2.c
    │   └── 📄 Scientific_cal_prototype3.c
    ├── 📂 Testing_&_ChallengesFaced/
    │   ├── 📄 cal_performance_Vs_benchmark_test.c
    │   └── 📄 Error_and_bug_incal.c
    └── 📄 Final_scientific_calculater.c

```

---

## Development Journey

### 1. Early Prototypes (`/devlepment_history/`)

####  `Scientific_cal_prototype1.c`

* **Focus:** Core calculator logic.
* **Notes:** Built fundamental arithmetic operations; practiced loops, conditions, and program flow; worked entirely with integer-based calculations.

####  `Scientific_cal_prototype2.c`

* **Focus:** Floating-point support.
* **Notes:** Added decimal number handling; expanded calculator capabilities beyond integers; introduced basic precision tracking.

####  `Scientific_cal_prototype3.c`

* **Focus:** Mathematical approximations.
* **Notes:** Implemented Taylor and Maclaurin series; built custom trigonometric approximations; added angle reduction techniques; explored convergence behavior of infinite series.

---

### 2. Testing & Debugging (`/Testing_&_ChallengesFaced/`)

####  `cal_performance_Vs_benchmark_test.c`

* **Focus:** Performance validation.
* **Notes:** Compared custom implementations against `<math.h>`; measured approximation accuracy; tracked precision drift across calculations.

####  `Error_and_bug_incal.c`

* **Focus:** Bug isolation sandbox.
* **Notes:** Dedicated environment for reproducing bugs; tested boundary conditions; investigated domain-related mathematical errors.

---

### 3. Final Version (`Final_scientific_calculater.c`)

The final assignment-ready version combines all validated components into a single program. Features include:

* Scientific calculations
* Domain validation checks
* Input stream cleanup using `clearBuffer()`
* Basic protection against invalid user input
* Improved program stability

---

## Technical Lessons Learned

This project taught me:

* Numerical approximation methods
* Floating-point limitations
* Algorithmic efficiency
* Debugging strategies
* Input validation
* Memory-aware programming
* **Most importantly:** How mathematical concepts are translated into actual software.

---

## Known Limitations

As this was my first major programming project, several issues remain intentionally preserved:

* **Performance:** Power and factorial calculations are recalculated repeatedly; some operations are slower than necessary.
* **Precision:** Floating-point arithmetic introduces small accuracy losses; long calculations may accumulate rounding errors.
* **Edge Cases:** Some extreme mathematical inputs are not fully handled; error handling can be improved further.

---

## Future Version (V2)

Rather than continuously patching this repository, I plan to rebuild the calculator from scratch with a cleaner architecture. Planned improvements:

1. Faster mathematical algorithms.
2. Better numerical accuracy.
3. Stronger edge-case handling.
4. Modular file structure.
5. Improved maintainability.

---

## Author's Story & Developer Notes

> This was my very first C project, made for a Semester 1 assignment. At the time, I had only been learning C programming and college calculus simultaneously for about 2-3 months. I wanted to do something different, so I decided to integrate the core math concepts I was learning in my lectures directly into my code.
> 
> Using what I learned during those sessions, I implemented Taylor series, Maclaurin series, and angle reduction models to see how infinite series actually behave in a real program.
> Looking back, the code has classic first-semester constraints—like algorithmic complexity issues in the power loops and basic floating-point truncation limits. However, debugging these early bottlenecks is exactly how I learned about numerical stability, memory safety, and input stream handling.
> 
> It might not be a flawless technical masterpiece, but it was my first real stepping stone into understanding how computers implement the language of mathematics. I am naturally drawn to these kinds of low-level, logic-heavy projects, and this is exactly where my software engineering journey started.
> Instead of hiding early mistakes, I have chosen to keep this repository as a record of my learning process and growth as a developer.

```

```
