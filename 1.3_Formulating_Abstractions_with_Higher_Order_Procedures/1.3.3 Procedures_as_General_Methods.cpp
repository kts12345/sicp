

#include <cmath>                           // isless, isgrate, sin, cos
#include <cstdlib>                         // abs
#include <iostream>                        // cout, endl, << 
#include <boost/phoenix.hpp>               // _1, _2, *, 
using namespace boost::phoenix::arg_names; // _1, _2, *, 

//-------------------------------------------------------------
auto is_positive = 0 < _1;
auto is_negative = _1 < 0;

//-------------------------------------------------------------
// (define (average x y) (/ (+ x y) 2))
auto average = (arg1 + arg2) / 2;

//-------------------------------------------------------------
//  (define (close-enough? x y) (< (abs (- x y)) 0.001))
auto is_close_enough = [](auto x, auto y) { return std::abs(x - y) < 0.001; };

//-------------------------------------------------------------
//  (define (search f neg-point pos-point)
//     (let ((midpoint (average neg-point pos-point)))
//       (if (close-enough? neg-point pos-point)
//           midpoint
//           (let ((test-value (f midpoint)))
//             (cond ((positive? test-value)
//                    (search f neg-point midpoint))
//                   ((negative? test-value)
//                    (search f midpoint pos-point))
//                   (else midpoint))))))
//
template <typename Func, typename Num>
auto search(Func f, Num neg_point, Num pos_point)
{
  auto mid_point = average(neg_point, pos_point);
  if (is_close_enough(neg_point, pos_point))
    return mid_point;
  else
  {
    auto test_value = f(mid_point);
    if (is_positive(test_value)) return search(f, neg_point, mid_point);
    if (is_negative(test_value)) return search(f, mid_point, pos_point);
    else                            return mid_point;
  }
};

//-------------------------------------------------------------
//  (define (half-interval-method f a b)
//   (let ((a-value (f a))
//         (b-value (f b)))
//     (cond ((and (negative? a-value) (positive? b-value))
//            (search f a b))
//           ((and (negative? b-value) (positive? a-value))
//            (search f b a))
//           (else (error "Values are not of opposite sign" a b)))))
//
template <typename Func, typename Num>
auto half_interval_method(Func f, Num a, Num b)
{
  auto a_value = f(a);
  auto b_value = f(b);
  if (is_negative(a_value) && is_positive(b_value)) return search(f, a, b);
  if (is_negative(b_value) && is_positive(a_value)) return search(f, b, a);
  //else return a;
  else  throw "Values are not of opposite sign";
};

//-------------------------------------------------------------
// (half-interval-method sin 2.0 4.0)
// 3.14111328125
// 
auto val_3_14 = half_interval_method<double(double)>(std::sin, 2.0, 4.0);

//-------------------------------------------------------------
// (half-interval-method (lambda (x) (- (* x x x) (* 2 x) 3))
//                      1.0
//                      2.0)
// 1.89306640625
auto val_1_89 = half_interval_method((_1*_1*_1) - (2 * _1) - 3, 1.0, 2.0);


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
template <typename Func, typename Num>
auto fixed_point(Func f, Num first_guess)
{
  auto is_close_enough = [](auto v1, auto v2)
  { 
    return std::abs(v1 - v2) < tolerance; 
  };

  auto try_f = [](auto f, auto try_f, auto guess)
  {
    auto next = f(guess);
    if (is_close_enough(guess, next)) return next;
    else                              return try_f(f, try_f, next);
  };

  return try_f(f, try_f, first_guess);
};

//-------------------------------------------------------------
// (fixed - point cos 1.0)
// .7390822985224023
// 
auto val_0_73 = fixed_point<double(double)>(std::cos, 1.0);

//-------------------------------------------------------------
// (fixed - point(lambda(y) (+(sin y) (cos y))) 1.0)
// 1.2587315962971173
auto val_1_25 = fixed_point<double(double)>([](auto y) { return std::sin(y) + std::cos(y)}, 1.0);

//-------------------------------------------------------------
//(define(sqrt x)
//  (fixed - point(lambda(y) (/ x y)) 1.0))
//
template <typename Num>
auto sqrt_1(Num x)
{
  auto lambda = [x](Num y) { return x / y; };
  return fixed_point(lambda, 1.0);
};
//auto val_infinite = sqrt_1(2.0);

//-------------------------------------------------------------
//(define(sqrt x)
//  (fixed - point(lambda(y) (average y(/ x y))) 1.0))
// infinte roop
//
template <typename Num>
auto sqrt_2(Num x)
{
  auto lambda = [x](Num y) { return average(y, x / y); };
  return fixed_point(lambda, 1.0);
};
auto val_1_41 = sqrt_2(2.0);


int main()
{
  auto print = [](auto v) { std::cout << v << std::endl; };
  print(val_3_14);
  print(val_1_89);
  print(val_0_73);
  print(val_1_25);
  print(val_1_41);
  //print(val_infinite);

  return 0;
}

//-------------------------------------------------------------
// output
//
// 3.14111
// 1.89307 
