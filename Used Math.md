#  Mathematical Implementation Details

To build this scientific calculator without relying on the standard `<math.h>` library,
the core challenge was bridging the gap between pure calculus theory and hardware constraints. 
Below is the breakdown of how the mathematics map directly to the program logic.

---

### 1. Maclaurin & Taylor Series Expansion
Trigonometric and transcendental functions ($\sin x$, $\cos x$, and $\ln x$) are approximated using Taylor series expansions.
Since a computer cannot compute an infinite series, the loop must terminate once the term value drops below a predefined precision threshold.

$$\sin x = \sum_{n=0}^{\infty} \frac{(-1)^n x^{2n+1}}{(2n+1)!} = x - \frac{x^3}{3!} + \frac{x^5}{5!} - \frac{x^7}{7!} + \dots$$

* **Code Implementation:** An iterative loop tracks the current term's value.
   When the absolute value of a term becomes less than $10^{-7}$,
   the loop breaks to preserve performance while maintaining core accuracy.

---

### 2. Manual Angle Reduction Logic
Taylor series approximations lose accuracy rapidly and suffer from floating-point overflow if the input variable $x$ is a massive number. 

* **Code Implementation:** Before processing any angle through the series,
trigonometric identity logic automatically scales the input back down into a tight, highly accurate domain between $0$ and $2\pi$.
$$\theta_{\text{reduced}} = \theta \pmod{2\pi}$$

---

### 3. Iterative Power & Factorial Engines
Because standard C lacks a built-in exponent operator, and because denominators scale aggressively in Taylor series, custom helper functions were required to feed the main engines.

* **Code Implementation:** Dedicated loops handle the rapidly growing numerators ($x^n$) and denominators ($n!$) concurrently within the expansion cycle to manage numerical stability as long as possible before encountering standard floating-point truncation limits.
