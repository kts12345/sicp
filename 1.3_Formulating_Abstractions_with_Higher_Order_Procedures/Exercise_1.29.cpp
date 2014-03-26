/* Exercise 1.29: Simpson¡¯s Rule is a more accurate method of numerical
integration than the method illustrated above.Using Simpson¡¯s
Rule, the integral of a function f between a and b is approximated
as
h/3 * (y0 + 4y1 + 2y2 + 4y3 + 2y4 + . . . + 2yn¢®2 + 4yn¢®1 + yn),
where h = (b - a) / n, for some even integer n, and yk = f(a + kh).
(Increasing n increases the accuracy of the approximation.) Define
a procedure that takes as arguments f, a, b, and n and returns the
value of the integral, computed using Simpson¡¯s Rule.Use your
procedure to integrate cube between 0 and 1 (with n = 100 and n =
1000), and compare the results to those of the integral procedure
shown above.
*/

#include <iostream>                        // cout, endl, << 
#include <boost/phoenix.hpp>               // _1, _2, +, *, >

using namespace boost::phoenix::arg_names; // _1, _2, +, *, >


//-------------------------------------------------------------
//  (define(cube x) (*x x x))
//
auto cube = _1 * _1 * _1;


//  (define(inc n) (+n 1)
//
auto inc = _1 + 1;

//-------------------------------------------------------------
//  (define(sum term a next b)
//    (if (> a b)
//    0
//    (+(term a)
//      (sum term(next a) next b))))
//
auto sum = [](auto term, auto a, auto next, auto b)
{
  if (a > b) return decltype(term(a))(0);
  else       return term(a) + sum(term, next(a), next, b);
};

//-------------------------------------------------------------
//  (define(integral f a b dx)
//    (define(add - dx x)
//      (+x dx))
//    (*(sum f (+a(/ dx 2.0)) add - dx b)
//      dx))
auto integral = [](auto f, auto a, auto b, auto dx)
{
  auto add_dx = _1 + dx;
  return sum(f, a + dx / 2.0, add_dx, b) * dx;
};


//-------------------------------------------------------------
/*
(define simpson_integral f a b n)
(define h (/ (- b a) n)
(define (y_k k) (f (+ a (* k h))))
(define y_0 (y_k(0)))
(define y_n (y_k(n)))
(define (term k)
(if (= 0 (k %2))
(* 4 (y_k(k)))
(* 2 (y_k(k))))

(* (/ h 3) (+ y_0 (sum term 1 inc (- n 1)) y_n)))

*/
auto simpson_integral = [](auto f, auto a, auto b, auto n)
{
  auto h = (b - a) / n;
  auto y_k = f(a + _1*h);
  auto y_0 = y_k(0);
  auto y_n = y_k(n);
  auto term = [&y_k](auto k)
  {
    return k % 2 == 1 ? 4 * y_k(k) : 2 * y_k(k);
  };

  return h / 3 * (y_0 + sum(term, 1, inc, n - 1) + y_n);
};

int main()
{
  auto print = [](auto v) { std::cout << v << std::endl; };
  print(simpson_integral(cube, 0.0, 1.0, 100));
  print(simpson_integral(cube, 0.0, 1.0, 1000));
  print(integral(cube, 0, 1, 0.01)); // (integral cube 0 1 0.01)
  print(integral(cube, 0, 1, 0.001)); // (integral cube 0 1 0.001)
  return 0;
}