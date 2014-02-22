// sicp.1.1.5 The Substitution Model for Procedure Application

#include <iostream>
#include <functional>

#include <boost/phoenix.hpp>


template <typename V>
void print( V v )
{
  using std::cout;
  using std::endl;
  cout << v << endl;
}

int main()
{
  using boost::phoenix::arg_names::arg1;
  using boost::phoenix::arg_names::arg2;
  
  // (define (square x) (* x x))
  auto square = arg1*arg1;
  
  // (define (sum-of-squares x y)
  //         (+ (square x) (square y)))
  auto sum_of_squares = 
            square(arg1) + square(arg2);
            
  // (define (f a)
  //        (sum-of-squares (+ a 1) (* a 2)))
  auto f = 
            sum_of_squares(arg1 + 1, arg1 *2);

  print (f(5)); // (f 5)

}
