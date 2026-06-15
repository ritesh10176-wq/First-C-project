# Custom Scientific Calculator (C)
A scientific calculator built entirely in C as my first-semester programming project.

## What Makes It Different?
Instead of relying on `<math.h>` for advanced calculations, I explored how mathematical functions can be approximated from scratch using:
* Taylor Series
* Maclaurin Series
* Angle Reduction Techniques
* Custom Power & Factorial Logic

This project was built while I was learning both C programming and introductory calculus.

---

## Project Structure
```text
C-PROJECTS/
└── Custom_scientific_calculator/
    ├── development_history/
    │   ├── Scientific_cal_prototype1.c
    │   ├── Scientific_cal_prototype2.c
    │   └── Scientific_cal_prototype3.c
    │
    ├── Testing_&_ChallengesFaced/
    │   ├── cal_performance_Vs_benchmark_test.c
    │   └── Error_and_bug_incal.c
    │
    └── Final_scientific_calculater.c
```markdown
# Custom Scientific Calculator (C)
A scientific calculator built entirely in C as my first-semester programming project.

## What Makes It Different?
Instead of relying on `<math.h>` for advanced calculations, I explored how mathematical functions can be approximated from scratch using:
* Taylor Series
* Maclaurin Series
* Angle Reduction Techniques
* Custom Power & Factorial Logic

This project was built while I was learning both C programming and introductory calculus.

---

## Project Structure
```text
C-PROJECTS/
└── Custom_scientific_calculator/
    ├── development_history/
    │   ├── Scientific_cal_prototype1.c
    │   ├── Scientific_cal_prototype2.c
    │   └── Scientific_cal_prototype3.c
    │
    ├── Testing_&_ChallengesFaced/
    │   ├── cal_performance_Vs_benchmark_test.c
    │   └── Error_and_bug_incal.c
    │
    └── Final_scientific_calculater.c

```

---

## Development Journey

### Prototype 1

**Focus:** Core calculator logic

* Built fundamental arithmetic operations
* Practiced loops, conditions, and program flow
* Worked entirely with integer-based calculations

### Prototype 2

**Focus:** Floating-point support

* Added decimal number handling
* Expanded calculator capabilities beyond integers
* Introduced basic precision tracking

### Prototype 3

**Focus:** Mathematical approximations

* Implemented Taylor and Maclaurin series
* Built custom trigonometric approximations
* Added angle reduction techniques
* Explored convergence behavior of infinite series

```

```markdown
## Testing & Debugging

### Performance Validation
* **File:** `cal_performance_Vs_benchmark_test.c`
* Compared custom implementations against `<math.h>`
* Measured approximation accuracy
* Tracked precision drift across calculations

### Bug Isolation Sandbox
* **File:** `Error_and_bug_incal.c`
* Dedicated environment for reproducing bugs
* Tested boundary conditions
* Investigated domain-related mathematical errors

---

## Final Version
* **File:** `Final_scientific_calculater.c`

The final assignment-ready version combines all validated components into a single program. 

**Features include:**
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

Most importantly, it showed me how mathematical concepts are translated into actual software.

---

## Known Limitations
As this was my first major programming project, several issues remain intentionally preserved.

* **Performance:** Power and factorial calculations are recalculated repeatedly; some operations are slower than necessary.
* **Precision:** Floating-point arithmetic introduces small accuracy losses; long calculations may accumulate rounding errors.
* **Edge Cases:** Some extreme mathematical inputs are not fully handled; error handling can be improved further.

---

## Future Version (V2)
Rather than continuously patching this repository, I plan to rebuild the calculator from scratch with a cleaner architecture.

**Planned improvements:**
1. Faster mathematical algorithms
2. Better numerical accuracy
3. Stronger edge-case handling
4. Modular file structure
5. Improved maintainability

---

## Developer Note
> This was my first C project, created during Semester 1 after roughly 2–3 months of learning programming.
> 
> While the code is far from perfect, it represents the beginning of my journey into low-level programming, mathematical computing, and software engineering. Instead of hiding early mistakes, I have chosen to keep this repository as a record of my learning process and growth as a developer.

```
