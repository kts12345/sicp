// sicp.1.1.1 Expressions

#include <iostream>                        // cout, endl, << 
#include <boost/phoenix.hpp>               // arg1, arg2, +, -, *, /
#include <boost/fusion/container.hpp>      // make_list
#include <boost/fusion/algorithm.hpp>      // fold
  
using namespace boost::phoenix::arg_names; // for arg1, arg2, +, -, *, /
using namespace boost::fusion;             // for make_list, fold

//-----------------------------------------------------------------------------

template<typename T0, typename... TN>
auto add (T0 t0, TN... tn) { return fold(make_list(tn...), t0, arg1 + arg2); }
  
template<typename T0, typename... TN>
auto mul (T0 t0, TN... tn) { return fold(make_list(tn...), t0, arg1 * arg2); }
  
auto print = [](auto v) {  std::cout << v << std::endl; };

//------------------------------------------------------------------------------

int main()
{ 
  auto sub = arg1 - arg2;
  auto div = arg1 / arg2;

  //     486
  print (486);                   

  //    (+ 137 349)
  print (add (137, 349));        

  //    (- 1000 334)
  print (sub (1000, 334));       

  //    (* 5 99)
  print (mul (5, 99));           

  //    (/ 10 5)
  print (div (10, 5));           

  //    (+ 2.7 10)
  print (add (2.7, 10));         

  //    (+ 21 35 12 7)
  print (add (21, 35, 12, 7));   

  //    (* 25 4 12)
  print (mul (25, 4, 12));       

  //    (+ (* 3 5) (- 10 6))
  print (add (mul (3,5), sub (10, 6)));                                      

  //    (+ (* 3 (+ (* 2 4) (+ 3 5))) (+ (- 10 7) 6))
  print (add (mul (3, add (mul (2, 4), add (3, 5))), add (sub (10, 7), 6)));
}
