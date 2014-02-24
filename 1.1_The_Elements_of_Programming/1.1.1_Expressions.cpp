// sicp.1.1.1 Expressions


#include <iostream>
#include <functional>

#include <boost/phoenix.hpp>

#include <boost/fusion/container.hpp>
#include <boost/fusion/algorithm.hpp>

//-------------------------------------------------
template <typename V>
void print( V v ) { std::cout << v << std::endl; }

//-------------------------------------------------
int main()
{  
  using boost::fusion::fold;
  using boost::fusion::make_list;
  
  using boost::phoenix::arg_names::arg1;
  using boost::phoenix::arg_names::arg2;

  //------------------------------------------------- 
 
  auto add = arg1 + arg2;
  auto sub = arg1 - arg2;
  auto mul = arg1 * arg2;
  auto div = arg1 / arg2;

  //-------------------------------------------------

  print (486);        // 486
  print (add (137, 349));  // (+ 137 349)
  print (sub (1000, 334)); // (- 1000 334)
  print (mul (5, 99));     // (* 5 99)
  print (div (10, 5));     // (/ 10 5)
  print (add (2.7, 10));   // (+ 2.7 10)
  print (fold(make_list(21, 35, 12, 7), 0, add));   // (+ 21 35 12 7)
  print (fold(make_list(25, 4, 12), 1, mul));       // (* 25 4 12)
  print (add (mul (3,5), sub (10, 6)));             // (+ (* 3 5) (- 10 6))
  print (add (mul (3, add (mul (2, 4), add (3, 5))), add (sub (10, 7), 6))); // (+ (* 3 (+ (* 2 4) (+ 3 5))) (+ (- 10 7) 6))
}

