// sicp.1.1.1 expressions

#include <iostream>
#include <functional>

#include <boost/fusion/container.hpp>
#include <boost/fusion/algorithm.hpp>

template <typename V>
void print( V v )
{
  using std::cout;
  using std::endl;
  cout << v << endl;
}

int main()
{  
  using boost::fusion::fold;
  using boost::fusion::make_list;
  
  const auto plus_i = std::plus<int>();
  const auto plus_f = std::plus<float>();
  const auto minus_i = std::minus<int>();
  const auto mul_i   = std::multiplies<int>();
  const auto div_i   = std::divides<int>();
  
  print (486);        // 486
  print (plus_i (137, 349));  // (+ 137 349)
  print (minus_i (1000, 334)); // (- 1000 334)
  print (mul_i (5, 99));     // (* 5 99)
  print (div_i (10, 5));     // (/ 10 5)
  print (plus_f (2.7, 10));   // (+ 2.7 10)
  print (fold(make_list(21, 35, 12, 7), 0, plus_i)); // (+ 21 35 12 7)
  print (fold(make_list(25, 4, 12), 1, mul_i));     // (* 25 4 12)
  print (plus_i (mul_i (3,5), minus_i (10, 6))); //--(+ (* 3 5) (- 10 6))
  print (plus_i (mul_i (3, (plus_i (mul_i (2, 4), plus_i (3, 5)))), 
                 plus_i (minus_i (10, 7), 6))); // (+ (* 3 (+ (* 2 4) (+ 3 5))) (+ (- 10 7) 6))
}