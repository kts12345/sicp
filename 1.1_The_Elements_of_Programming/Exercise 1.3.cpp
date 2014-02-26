// sicp.exercise.1.3
//-------------------------------------------------------
// * Problem : 
//   Define a procedure that takes three numbers as arguments and returns the sum of the
//   squares of the two larger numbers.

//---------------------------------------------------------
// * Answer
#include <iostream>                        // cout, endl, << 
#include <boost/phoenix.hpp>               // arg1, arg2, +, *
  
using namespace boost::phoenix::arg_names; // arg1, arg2, +, *

//-----------------------------------------------------------------------------

auto add   = arg1 + arg2;
auto mul   = arg1 * arg2;
auto lt    = arg1 < arg2;
auto and_  = arg1 && arg2;

auto print = [](auto v) {  std::cout << v << std::endl; };

//------------------------------------------------------------------------------

int main()
{
  // (define (square x) (* x x))
  auto        square =  mul (arg1, arg1);
  
  // (define (sum-of-squares x y)
  //         (+ (square x) (square y)))
  auto sum_of_squares = 
              add (square (arg1), square (arg2)); 

  //(define (sum-of-squares-without-min x y z)
  //    (cond ((and (< x y)(< x z)) (sum-of-squares y z))
  //          ((< y z)              (sum-of-squares z x))
  //          (else                 (sum-of-squares x y))))
  
  auto sum_of_squares_without_min = [&](auto x, auto y, auto z)
  {
      if (and_ (lt (x,y), lt (x,z))) return sum_of_squares(y, z);
      if (lt (y, z))                 return sum_of_squares(z, x);
      else                           return sum_of_squares(x, y);
  };
   

  //-------------------------------------------------------
  // * Test
  //(sum-of-squares-without-min 1 2 3)
  //(sum-of-squares-without-min 4 2 3)
  //(sum-of-squares-without-min 4 5 3) 
  print (sum_of_squares_without_min (1, 2, 3));
  print (sum_of_squares_without_min (4, 2, 3));
  print (sum_of_squares_without_min (4, 5, 3));
}

// ========================================================
// Output
//----------------------------------------------------------
// 13
// 25
// 41
