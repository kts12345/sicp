// sicp.1.1.4 Compound Procedures

#include <iostream>                        // cout, endl, << 
#include <boost/phoenix.hpp>               // arg1, arg2, +, *
  
using namespace boost::phoenix::arg_names; // arg1, arg2, +, *

//-----------------------------------------------------------------------------

auto add = arg1 + arg2;
auto mul = arg1 * arg2;

auto print = [](auto v) {  std::cout << v << std::endl; };

//------------------------------------------------------------------------------

int main()
{
  // (define (square x) (* x x))
  auto square = mul (arg1, arg1);
  
  // (define (sum-of-squares x y)
  //         (+ (square x) (square y)))
  auto sum_of_squares = 
              add (square (arg1), square (arg2));
            
  // (define (f a)
  //         (sum-of-squares (+ a 1) (* a 2)))
  auto f = 
              sum_of_squares (add (arg1, 1), mul (arg1, 2));
 
  //    (square 21)
  print (square (21));
  
  //    (square (+ 2 5))
  print (square (add (2, 5)));
  
  //    (square (square 3))
  print (square (square (3)));
  
  //    (sum-of-squares 3 4)
  print (sum_of_squares (3, 4));
  
  //    (f 5)
  print (f (5)); 
}
