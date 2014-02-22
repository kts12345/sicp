// sicp.1.1.2 Naming and the Environments

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

  const auto mul_f   = std::multiplies<float>();
  const auto mul_i   = std::multiplies<int>();
  
  auto size = 2;      // (define size 2)
  auto pi = 3.14159;  // (define pi 3.14159)
  auto radius = 10;   // (define radius 10)
  auto circumference = fold(make_list(2, pi, radius), 1, mul_f); // (define circumference (* 2 pi radius))

  print (size);            // size
  print (mul_i (5, size)); // (* 5 size)
  print (mul_f (pi, mul_i (radius, radius))); // (* pi (* radius radius))
  print (circumference);   // circumference
}
