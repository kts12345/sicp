//  sicp.exercise.1.13
/* -------------------------------------------------------
 * Problem
  Prove that Fib(n) is the closest integer to P^n/ Root(5), where P = (1 + Root(5))/2. 
  Hint: Let K = (1-Root(5))/2. 
  Use induction and the definition of the Fibonacci numbers (see section 1.2.2) to prove that 
  Fib(n) = (P^n - K^n)/ Root(5).
*/

/*
 ========================================================
  * Answer
 --------------------------------------------------------
 1+P = P^2, 1+K = K^2

 Fib (0) = (P^0 - K^0)/ Root(5) = 0  .OK
 Fib (1) = (P^1 - K^1)/ Root(5) = 1  .OK
 
 Fib (n) + Fib(n+1)
         = (P^n - K^n)/ Root(5) + (P^(n+1) - K^(n+1))/ Root(5)
	 = (P^n)(1+P)/Root(5)  - (K^n)(1+K)/Root(5)
         = (P^n)(P^2)/Root(5)  - (K^n)(K^2)/Root(5)
         = P^(n+2)/Root(5)     - K^(n+2)/Root(5)
         = (P^(n+2) - K^(n+2))/Root(5)
         = Fib(n+2).  Good.
 */
