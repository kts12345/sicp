// sicp.exercise.1.4
//-------------------------------------------------------
// * Problem : 
//   Observe that our model of evaluation allows for combinations whose operators are
//   compound expressions. Use this observation to describe the behavior of the following procedure:

#include <iostream>                        // cout, endl, << 
#include <boost/phoenix.hpp>               // arg1, arg2, +, *, >
  
using namespace boost::phoenix::arg_names; // arg1, arg2, +, *, >


auto gt  = arg1 > arg2;
auto add = arg1 + arg2;
auto sub = arg1 - arg2;

//  (define (a-plus-abs-b a b)
//      ((if (> b 0) + -) a b))
auto a_plus_abs_b = 
         if_else(gt (arg2, 0), add, sub);


auto print = [](auto v) {  std::cout << v << std::endl; };

//-------------------------------------------------------
// * Test
//(a-plus-abs-b 10 -4)
//(a-plus-abs-b 10 +4)
int main()
{
  print (a_plus_abs_b (10, -4));
  print (a_plus_abs_b (10, +4));
  
}
//========================================================
// * Output
//--------------------------------------------------------
//14
//14

//-------------------------------------------------------
// * Answer

// a_plus_abs_b                  (10, -4)
// if_else(gt (-4, 0), add, sub) (10, -4)
// if_else(false     , add, sub) (10, -4)
//                          sub  (10, -4)
//                          14

// a_plus_abs_b                  (10, +4)
// if_else(gt (+4, 0), add, sub) (10, +4)
// if_else(true      , add, sub) (10, +4)
//                     add       (10, +4)
//                     14
