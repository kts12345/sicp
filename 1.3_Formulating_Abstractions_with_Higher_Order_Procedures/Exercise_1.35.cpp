

#include <cmath>                           // isless, isgrate, sin, cos
#include <cstdlib>                         // abs
#include <iostream>                        // cout, endl, << 
#include <boost/phoenix.hpp>               // _1, _2, *, 
using namespace boost::phoenix::arg_names; // _1, _2, *, 

//-------------------------------------------------------------
auto is_positive = 0 < _1;
auto is_negative = _1 < 0;


//-------------------------------------------------------------
//(define tolerance 0.00001)
//(define (fixed-point f first-guess)
//  (define (close-enough? v1 v2)
//    (< (abs (- v1 v2))
//       tolerance))
//  (define (try guess)
//    (let ((next (f guess)))
//      (if (close-enough? guess next)
//          next
//          (try next))))
//  (try first-guess))
//
auto tolerance = 0.00001;

auto is_close_enough = [](auto v1, auto v2)
{ return std::abs(v1 - v2) < tolerance; };

template <typename Func, typename Num>
auto fixed_point(Func f, Num first_guess)
{
   auto try_f = [](auto f, auto try_f, auto guess)
  {
    auto next = f(guess);
    if (is_close_enough(guess, next)) return next;
    else                              return try_f(f, try_f, next);
  };

  return try_f(f, try_f, first_guess);
};

//(define golden_ratio
//          (fixed - point(lambda(y) (+1 (/ 1 x))) 1.0))
auto golden_ratio = fixed_point(1 + 1 / _1, 1.0); 

int main()
{
  auto print = [](auto v) { std::cout << v << std::endl; };

  print(golden_ratio);

  return 0;
}

//-------------------------------------------------------------
// output
//
// 1.61803
