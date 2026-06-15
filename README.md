

# Custom Scientific Calculator

### **Translating calculus lectures directly into native C code—approximating functions from scratch without `<math.h>**`

> **A Semester-1 / First Project**

---

## Project Structure

```text
📂 C-PROJECTS/
└── 📂 Custom_scientific_calculator/
    ├── 📂 devlepment_history/
    │   ├── Scientific_cal_prototype1.c    # Phase 1: Pure integer/basic looping structures
    │   ├── Scientific_cal_prototype2.c    # Phase 2: Introduction of basic float tracking
    │   └── Scientific_cal_prototype3.c    # Phase 3: Taylor series convergence approximations
    ├── 📂 Testing_&_ChallengesFaced/
    │   ├── cal_performance_Vs_benchmark_test.c  # Comparative validation harness vs <math.h>
    │   └── Error_and_bug_incal.c                # Isolated debugging environment for domain limits
    └── Final_scientific_calculater.c            # Final-ready, structural master program

```

---

## Evolution & Implementation Notes

### 1. Early Prototypes (`/devlepment_history/`)

* **`Scientific_cal_prototype1.c`**
Pure integer structures. Built the core looping blocks to run fundamental calculations and understand initial program flow.
* **`Scientific_cal_prototype2.c`**
Basic floating-point tracking. Introduced float logic to handle decimals, breaking away from pure integer constraints and expanding the calculator's range.
* **`Scientific_cal_prototype3.c`**
Taylor & Maclaurin series approximation. The first structural leap. Implemented infinite expansion loops and manual angle reduction logic to approximate complex mathematical functions from scratch.



### 2. Testing & Debugging (`/Testing_&_ChallengesFaced/`)

* **`cal_performance_Vs_benchmark_test.c`**
 *  Focus: Comparative validation harness :  A testing suite designed to run custom approximation algorithms side-by-side against the standard C library `<math.h>` to monitor precision drift.


* **`Error_and_bug_incal.c`**
* Focus: Isolated debugging environment : A dedicated sandbox used to reproduce, isolate, and safely fix boundary errors, such as handling fractional exponents on negative bases.



### 3. Final Phase Program (`Final_scientific_calculater.c`)

* **The Production Build**
* **Focus:** Structural optimization and defensive coding.
* **Notes:** The final version 1, assignment-ready master file. It integrates all validated mathematical engines(functions) with strict domain-limit gates and terminal stream cleaning (`clearBuffer()`) to prevent input-induced runtime crashes.



---

## Current Issues & What's Next (The Honest Truth)

Let’s be completely real: this is a first-semester student project. It is far from perfect, it still contains bugs, and I haven't fixed them in this repository because I want to preserve my actual learning journey.

Here are the known issues currently sitting in this code:

* **Inefficient Loops:** The loops calculating powers and factorials inside the Taylor series are slow. They recalculate everything from scratch on every turn, which is bad for performance.
* **Precision Drift:** Because of how standard decimals (`double`) work in C, the numbers start drifting slightly and losing accuracy if you push the calculations too far.
* **Basic Error Handling:** While `clearBuffer()` stops basic terminal crashes, extreme mathematical edge cases can still break the logic.
---

### The Next Journey

Instead of patching this repository up and hiding my mistakes, I am leaving this project exactly as it was during my first semester to show my roots.

My next step is to build **Version 2** from scratch in a brand-new repository. In that version, I will be focusing entirely on:

1. Rewriting the math loops to be faster and more memory-efficient.
2. Tightening up accuracy to completely eliminate precision drift.
3. Crushing the remaining edge-case bugs using a clean, professional file structure.
   

---

### Author's Story & Developer Notes

---
This was my very first C project, made for a Semester 1 assignment. At the time, I had only been learning C programming and college calculus simultaneously for about 2-3 months. I wanted to do something different, so I decided to integrate the core math concepts I was learning in my lectures directly into my code.

Using what I learned during those sessions, I implemented Taylor series, Maclaurin series, and angle reduction models to see how infinite series actually behave in a real program.

Looking back, the code has classic first-semester constraints—like an $O(N^2)$ algorithmic complexity in the power loops and basic floating-point truncation limits. However, debugging these early bottlenecks is exactly how I learned about numerical stability, memory safety, and input stream handling.

It might not be a flawless technical masterpiece, but it was my first real stepping stone into understanding how computers implement the language of mathematics. I am naturally drawn to these kinds of low-level, logic-heavy projects, and this is exactly where my software engineering journey started.

```

```
