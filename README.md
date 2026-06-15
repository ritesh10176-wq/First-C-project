
---

#  Custom Scientific Calculator
> **A Semester-1/First Project** > *Translating calculus lectures directly into native C code—approximating functions from scratch without `<math.h>`*`

---

## 📂 Project Structure

```text
📂 C-PROJECTS/
└── 📂 Custom_scientific_calculator/
    ├── 📂 devlepment_history/
    │   ├── Scientific_cal_prototype1.c    # Phase 1: Pure integer/basic looping structures
    │   ├── Scientific_cal_prototype2.c    # Phase 2: Introduction of basic float tracking
    │   └── Scientific_cal_prototype3.c    # Phase 3: Taylor series convergence approximations
    ├── 📂 Testing_&_ChallengesFaced/
    │   ├── cal_performance_Vs_benchmark_test.c  # Comparative validation harness vs <math.h>
    │   └── Error_and_bug_incal.c                # Isolated debugging environment for domain limits
    └── Final_scientific_calculater.c            # Final-ready, structural master program

```

---

##  Evolution & Implementation Notes

# 1. Early Prototypes (`/devlepment_history/`)

* `Scientific_cal_prototype1.c`Focus: Pure integer structures.
* Notes: Built the core looping blocks to run fundamental calculations and understand initial program flow.


* `Scientific_cal_prototype2.c`Focus: Basic floating-point tracking.
* Notes: Introduced float logic to handle decimals, breaking away from pure integer constraints and expanding the calculator's range.


* `Scientific_cal_prototype3.c`Focus: Taylor & Maclaurin series approximation.
* Notes:The first structural leap. Implemented infinite expansion loops and manual angle reduction logic to approximate complex mathematical functions from scratch.



# 2. Testing & Debugging (`/Testing_&_ChallengesFaced/`)

* `cal_performance_Vs_benchmark_test.c`Focus: Comparative validation harness.
* Notes: A testing suite designed to run custom approximation algorithms side-by-side against the standard C library `<math.h>` to monitor precision drift.


* `Error_and_bug_incal.c`Focus: Isolated debugging environment.
* Notes: A dedicated sandbox used to reproduce, isolate, and safely fix boundary errors, such as handling fractional exponents on negative bases.



# 3. Final pase Program 1 (`Final_scientific_calculater.c`)

* The Production Build Focus: Structural optimization and defensive coding.
* Notes: The final, assignment-ready master file. It integrates all validated mathematical engines with strict domain-limit gates and terminal stream cleaning (`clearBuffer()`) to prevent input-induced runtime crashes.



---
