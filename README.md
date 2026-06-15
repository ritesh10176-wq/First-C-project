# Custom Scientific Calculator from Scratch (C Language)

A lightweight, high-performance scientific calculator built entirely in native C without relying on the standard mathematical library (`<math.h>`). This repository serves as a complete documentation of the engineering lifecycle—from raw prototyping to validation benchmarking and error tracking.

---

## 📂 Project Architecture

The workspace is organized into modular phases reflecting progressive implementation and testing:

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
