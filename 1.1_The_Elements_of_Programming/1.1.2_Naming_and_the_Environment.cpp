// sicp.1.1.2 Naming and the Environments

#include <iostream>                        // cout, endl, << 
#include <boost/phoenix.hpp>               // arg1, arg2, *
#include <boost/fusion/container.hpp>      // make_list
#include <boost/fusion/algorithm.hpp>      // fold
  
using namespace boost::phoenix::arg_names; // arg1, arg2, *
using namespace boost::fusion;             // make_list, fold


template<typename T0, typename... TN>
auto mul (T0 t0, TN... tn) { return fold(make_list(tn...), t0, arg1 * arg2); }

auto print = [](auto v) {  std::cout << v << std::endl; };


int main()
{  
  // (define size 2)
  auto size = 2;  
  
  // (define pi 3.14159)
  auto pi = 3.14159; 
  
  // (define radius 10)
  auto radius = 10;   
  
  // (define circumference (* 2 pi radius))
  auto circumference = mul (2, pi, radius); 

  //     size
  print (size); 
  
  //    (* 5 size)
  print (mul (5, size)); 
  
  //    (* pi (* radius radius))
  print (mul (pi, mul (radius, radius))); 
  
  // circumference
  print (circumference);   
}