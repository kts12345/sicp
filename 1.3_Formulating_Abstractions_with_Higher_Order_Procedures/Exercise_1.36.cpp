#include <cmath>                           // isless, isgrate, sin, cos
#include <cstdlib>                         // abs
#include <iostream>                        // cout, endl, << 
#include <cmath>                           // log
#include <string>                          // string, to_string
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

auto average = [](auto v1, auto v2) { return (v1 + v2) / 2; };


auto print = [](auto v) { std::cout << v << std::endl; };

template <typename Func, typename Num>
auto fixed_point(Func f, Num first_guess)
{
  auto guess_count_init = 0;
  auto try_f = [](auto f, auto try_f, auto guess, auto guess_count)
  {
    guess_count++;
    print(std::string("guess_") + std::to_string(guess_count) + ": " + std::to_string(guess));
    auto next = f(guess);
    if (is_close_enough(guess, next)) return next;
    else                              return try_f(f, try_f, next, guess_count);
  };

  return try_f(f, try_f, first_guess, guess_count_init);
};

int main()
{
  using namespace std;
  //(define x_pow_x_equal_1000
  //        (fixed - point(lambda(x) (/ (log 1000) (log x)))
  //        2.0))
  auto x_pow_x_equal_1000 = fixed_point(
  [](auto x) { return log(1000) / log(x); },
  2.0);
  print("x_pow_x_equal_1000. x=" + to_string(x_pow_x_equal_1000));


  //(define x_pow_x_equal_1000_adamp
  //  (fixed - point(lambda(x) (average x (/ (log 1000) (log x))))
  //  2.0)
  auto x_pow_x_equal_1000_adamp = fixed_point(
  [](auto x) { return average(x, log(1000)/log(x)); },
  2.0);
  print("x_pow_x_equal_1000. x=" + to_string(x_pow_x_equal_1000));
  return 0;
}

//-------------------------------------------------------------
// output
//
//guess_1: 2.000000
//guess_2: 9.965784
//guess_3: 3.004472
//guess_4: 6.279196
//guess_5: 3.759851
//guess_6: 5.215844
//guess_7: 4.182207
//guess_8: 4.827765
//guess_9: 4.387593
//guess_10: 4.671250
//guess_11: 4.481404
//guess_12: 4.605366
//guess_13: 4.523085
//guess_14: 4.577115
//guess_15: 4.541382
//guess_16: 4.564903
//guess_17: 4.549373
//guess_18: 4.559606
//guess_19: 4.552854
//guess_20: 4.557306
//guess_21: 4.554369
//guess_22: 4.556305
//guess_23: 4.555028
//guess_24: 4.555870
//guess_25: 4.555315
//guess_26: 4.555681
//guess_27: 4.555440
//guess_28: 4.555599
//guess_29: 4.555494
//guess_30: 4.555563
//guess_31: 4.555518
//guess_32: 4.555548
//guess_33: 4.555528
//guess_34: 4.555541
//x_pow_x_equal_1000. x=4.555532
//guess_1: 2.000000
//guess_2: 5.982892
//guess_3: 4.922169
//guess_4: 4.628224
//guess_5: 4.568347
//guess_6: 4.557731
//guess_7: 4.555910
//guess_8: 4.555599
//guess_9: 4.555547
//x_pow_x_equal_1000. x=4.555532