/*Exercise 1.34:
Suppose we define the procedure
(define (f g) (g 2))
Then we have
(f square)
4

(f (lambda(z) (* z (+ z 1))))
6

What happens if we(perversely) ask the interpreter to evaluate the combination(f f) ? Explain.
*/

// answer
// application (f 2): 2 is not a procedure;
// expected a procedure that can be applied to arguments

#include <iostream>                        // cout, endl, << 
#include <boost/phoenix.hpp>               // _1, _2, *, 
using namespace boost::phoenix::arg_names; // _1, _2, *, 

auto square = _1 * _1;

auto f = [](auto g)
{
  return g(2);
};

int main()
{
  auto print = [](auto v) { std::cout << v << std::endl; };

  auto val_4 = f(square);
  auto val_6 = f(_1*(_1 + 1));

  print(val_4); // 4
  print(val_6); // 6
  print(f(f)); // error C2064: term does not evaluate to a function taking 1 arguments
}
