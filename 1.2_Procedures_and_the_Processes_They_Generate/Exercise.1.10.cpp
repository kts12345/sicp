//  sicp.exercise.1.10
/* -------------------------------------------------------
  * Problem
  The following procedure computes a mathematical function called Ackermann's function.
  (define (A x y)
    (cond  ((= y 0) 0)
           ((= x 0) (* 2 y))
           ((= y 1) 2)
           (else (A (- x 1)
                    (A x (- y 1)))))) 
                    
  What are the values of the following expressions?
  (A 1 10)
  (A 2 4)
  (A 3 3)
  
  Consider the following procedures, where A is the procedure defined above:
  (define (f n) (A 0 n))
  (define (g n) (A 1 n))
  (define (h n) (A 2 n))
  (define (k n) (* 5 n n))
  Give concise mathematical definitions for the functions computed by the procedures f, g, and h for
  positive integer values of n. For example, (k n) computes 5*n^2.
*/

#include <iostream>

/* ----------------------------------------
(define (A x y)
    (cond  ((= y 0) 0)
           ((= x 0) (* 2 y))
           ((= y 1) 2)
           (else (A (- x 1)
                    (A x (- y 1)))))) 
*/
template <typename T>
T A( T x, T y)
{
    if (y == 0) return 0;
    if (x == 0) return 2*y;
    if (y == 1) return 2;
    else return A(x-1, 
                  A (x, y-1));
}

/*----------------------------------------
  (A 1 10)
  (A 2 4)
  (A 3 3)
*/
auto A_1_10 = A(1,10);
auto A_2_4  = A(2,4);
auto A_3_3  = A(3,3);

/*----------------------------------------
  (define (f n) (A 0 n))
  (define (g n) (A 1 n))
  (define (h n) (A 2 n))
  (define (k n) (* 5 n n))
*/
auto f = [](auto n) { return A<decltype(n)>(0,n); };
auto g = [](auto n) { return A<decltype(n)>(1,n); };
auto h = [](auto n) { return A<decltype(n)>(2,n); };
auto k = [](auto n) { return decltype(n)(5)*n*n; };


// -------------------------------------------------------
// test
int main()
{
  auto print = [](auto v) {  std::cout << v << std::endl; };

  print (A_1_10);
  print (A_2_4);
  print (A_3_3);
  
  print (f (5));
  print (g (5));
  print (h (5.0));
  print (k (5));
}
/*
 ========================================================
  * Output
 --------------------------------------------------------
 1024
 65536
 65536
 10
 32
 inf
 125

  ========================================================
  * Answer
  --------------------------------------------------------
  A (1,1)  = 2                               = 2^1
  A (1,2)  = A (0, A (1,1))  = A(0, 2)       = 2^2
  A (1,3)  = A (0, A (1,2))  = A(0, 2^2)     = 2^3
  ...     ...                 ...           ...
  A (1,n)  = A (0, A (1,n-1) = A(0, 2^(n-1)) = 2^n
  so,
  g(n) = A(1,n) = 2^n
  A (1,10) = A (0, A (1,9)   = A(0, 2^9)     = 2^10 = 1024

  
  --------------------------------------------------------
  A (2,1) = 2                             = 2             = 2#1
  A (2,2) = A (1, A(2,1)) = A(1, 2#1)     = 2^2           = 2#2 
  A (2,3) = A (1, A(2,2)) = A(1, 2#2)     = 2^2^2         = 2#3
  ...     ...             ...             ...
  A (2,n) = A (1, A(2,n-1) = A(1,2#(n-1)) = 2^2^2^...^2   = 2#n
  so
  h(n) = A(2,n) = 2#n
  A (2,4) = 2#4 = 2^2^2^2 = 2^16 = 65536
  
  --------------------------------------------------------
  A (3,1) = 2
  A (3,2) = A(2, A(3,1)) = 2#2= 2^2 = 4
  A (3,3) = A(2, A(3,2)) = 2#(4) = 2^2^2^2 = 65536
  
 --------------------------------------------------------
  A (0, n) = 2*n
  so
  f(n) = A(0,n) = 2*n

*/
