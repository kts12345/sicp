//  sicp.exercise.1.9
/* -------------------------------------------------------
  * Problem
  Each of the following two procedures defines a method for adding two positive integers in
  terms of the procedures inc, which increments its argument by 1, and dec, which decrements its
  argument by 1.
  Using the substitution model, illustrate the process generated by each procedure in evaluating (+ 4 5).
  Are these processes iterative or recursive?
*/

#include <iostream>
#include <boost/phoenix.hpp>               // arg1, arg2, +, *
  
using namespace boost::phoenix::arg_names; // arg1, arg2, +, *


/* ----------------------------------------
(define (inc n) (+ n 1))
(define (dec n) (- n 1)) 
*/
auto inc = arg1 + 1;
auto dec = arg1 - 1;

/* ----------------------------------------
(define (plus1 a b)
  (if (= a 0)
      b
     (inc (plus1 (dec a) b))))
*/
template <typename T> 
T plus1(T const& a, T const& b)
{
  return  a == T(0) ?
          b :
          inc (plus1 (dec (a), b));
};


/* ----------------------------------------
(define (plus2 a b)
   (if (= a 0)
        b
       (plus2 (dec a) (inc b))))
*/
template <typename T> 
T plus2(T const& a, T const& b)
{
  return  a == T(0) ?
          b :
          plus2 (dec (a), inc (b));
};

// -------------------------------------------------------
// test
int main()
{
  auto print = [](auto v) {  std::cout << v << std::endl; };

  print (plus1 (4,5));
  print (plus2 (4,5));
}

/*
 ========================================================
  * Output
 --------------------------------------------------------
 9
 9

  -------------------------------------------------------
  * Answer
 
  (plus1 4 5)
  (inc (plus1 3 5))
  (inc (inc (plus1 2 5)))
  (inc (inc (inc (plus1 1 5))))
  (inc (inc (inc (inc (plus1 0 5 )))))
  (inc (inc (inc (inc 5))))
  (inc (inc (inc 6)))
  (inc (inc 7))
  (inc 8)
  9
  plus1 is recursive 
 
  (plus2 4 5)
  (plus2 3 6)
  (plus2 2 7)
  (plus2 1 8)
  (plus2 0 9)
  9
  plus2 is iterative

*/


