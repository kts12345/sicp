//  sicp.exercise.1.16
/* -------------------------------------------------------
 * Problem
  Design a procedure that evolves an iterative exponentiation process that uses successive
  squaring and uses a logarithmic number of steps, as does fast-expt.
*/

// -------------------------------------------------------
// Answer


#include <iostream>           // cout, endl, <<
#include <boost/phoenix.hpp>  // arg1, arg2, +, *

using namespace boost::phoenix::arg_names; // arg1, arg2, +, *

/*------------------------------------------------------------
(define (is_even n) (= (remainder n 2) 0))
(define (halve   n) (if (is_even n) (/ n 2) (/ (- n 1) 2)))
(define (square a)  (* a a))
*/
auto is_even = arg1 % 2 == 0;
auto halve   = arg1 >> 1;
auto square  = arg1 * arg1;


/*------------------------------------------------------------
(define (stepanov a n result)
    (cond ((= n 0)                                         result)
          ((is_even n) (stepanov (square a) (halve n)      result))   
          (else        (stepanov (square a) (halve n) (* a result))) ))
*/
template <typename A, typename N, typename R>
auto stepanov (A a, N n, R result)
{
    if (n == 0)     return result;
    if (is_even(n)) return stepanov(square(a), halve(n),   result);
    else            return stepanov(square(a), halve(n), a*result);
};

/*
(define (fast-expt a n)
    (stepanov a n 1))
*/
template <typename A, typename N>
auto  fast_expt (A a, N n)
{
    return stepanov(a, n, 1);
}

// -------------------------------------------------------
// test
int main()
{
  auto print = [](auto v) {  std::cout << v << std::endl; };

/*
(fast-expt 2 0)
(fast-expt 2 1)
(fast-expt 2 2)
(fast-expt 2 3)
(fast-expt 2 4)
(fast-expt 2 5)
(fast-expt 2 6)
(fast-expt 2 7)
(fast-expt 2 8)
(fast-expt 2 9)
(fast-expt 2 10)
*/
  print (fast_expt(2, 0)); 
  print (fast_expt(2, 1));
  print (fast_expt(2, 2));
  print (fast_expt(2, 3));
  print (fast_expt(2, 4));
  print (fast_expt(2, 5));
  print (fast_expt(2, 6));
  print (fast_expt(2, 7));
  print (fast_expt(2, 8));
  print (fast_expt(2, 9));
  print (fast_expt(2, 10));
}
/*
 ========================================================
  * Output
 --------------------------------------------------------
1
2
4
8
16
32
64
128
256
512
1024
*/
