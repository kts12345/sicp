// sicp.1.1.3 Evaluating Combinations

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

  const auto plus_i   = std::plus<int>();
  const auto mul_i   = std::multiplies<int>();
 
  // (* (+ 2 (* 4 6))
  //    (+ 3 5 7)) 
  print (mul_i (plus_i (2, (mul_i (4, 6))),
                fold(make_list(3,5,7), 0, plus_i))); 
}