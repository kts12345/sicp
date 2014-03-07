//  sicp.exercise.1.11
/* -------------------------------------------------------
 * Problem
  A function f is defined by the rule that f(n) = n if n<3 and f(n) = f(n - 1) + 2f(n - 2) + 3f(n
  - 3) if n> 3. Write a procedure that computes f by means of a recursive process. Write a procedure that
   computes f by means of an iterative process.
*/

#include <iostream>    // cout, endl, <<

/*------------------------------------------------------------
(define (f-r n)
   (if (< n 3) 
      n
     (+ (f-r (- n 1)) (* 2 (f-r (- n 2)))(* 3 (f-r (- n 3))))))
*/
template < typename N >
N f_r (N n)
{
    return n < 3 ? n :
           f_r(n-1) + 2*f_r(n-2) + 3*f_r(n-3);
}

/*------------------------------------------------------------
(define (f-i n)
   (define target n)
   (define f_0 0)
   (define f_1 1)
   (define f_2 2)
   (define n_3 3)
   (f-iter n_3 f_2 f_1 f_0 target))
*/
template < typename N > 
N f_iter (N n, N f_n_minus_1, N f_n_minus_2, N f_n_minus_3, N target); // forward-declare

template < typename N > N f_i (N n)
{  
    auto const& target = n;
    auto const& f_0    = N(0);
    auto const& f_1    = N(1);
    auto const& f_2    = N(2);
    auto const& n_3    = N(3);
    
    return f_iter(n_3, f_2, f_1, f_0, target); };

/*------------------------------------------------------------
(define (f-iter n f_n-1 f_n-2 f_n-3 target)
     (define f_n (+ f_n-1 (* 2 f_n-2)(* 3 f_n-3)))
     (cond ((< target 3) target)
           ((= target n) f_n)
           (else (f-iter (+ n 1) f_n f_n-1 f_n-2 target))))
*/
template < typename N > 
N f_iter (N n, N f_n_minus_1, N f_n_minus_2, N f_n_minus_3, N target)
{
    const auto f_n = f_n_minus_1 + 2*f_n_minus_2 + 3*f_n_minus_3;
    return
        target <  3 ? target :
        target == n ? f_n :
        f_iter(n+1, f_n, f_n_minus_1, f_n_minus_2, target);
};


// -------------------------------------------------------
// test
int main()
{
  auto print = [](auto v) {  std::cout << v << std::endl; };

  print (f_r (-1)); // (f-r -1)
  print (f_r (0));  // (f-r  0)
  print (f_r (1));  // (f-r  1)
  print (f_r (2));  // (f-r  2)
  print (f_r (3));  // (f-r  3)
  print (f_r (4));  // (f-r  4)
  print (f_r (5));  // (f-r  5)
  print ("");
  print (f_i (-1)); // (f-i -1)
  print (f_i (0));  // (f-i  0)
  print (f_i (1));  // (f-i  1)
  print (f_i (2));  // (f-i  2)
  print (f_i (3));  // (f-i  3)
  print (f_i (4));  // (f-i  4)
  print (f_i (5));  // (f-i  5)  
}
/*
 ========================================================
  * Output
 --------------------------------------------------------
 -1
 0
 1
 2
 4
 11
 25
 
 -1
 0
 1
 2
 4
 11
 25

  ========================================================
  * Answer
  --------------------------------------------------------
  f_i (5)
  f_iter (3, f_2, f_1, f_0, 5)
  f_iter (4, f_3, f_2, f_1, 5)
  f_iter (5, f_4, f_3, f_2, 5)
  f_5
*/
