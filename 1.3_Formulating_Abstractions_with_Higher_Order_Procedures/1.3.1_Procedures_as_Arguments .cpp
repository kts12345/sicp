
#include <iostream>                        // cout, endl, << 
#include <boost/phoenix.hpp>               // _1, _2, +, *, >

using namespace boost::phoenix::arg_names; // _1, _2, +, *, >


//-------------------------------------------------------------
//  (define(cube x) (*x x x))
//
auto cube = _1 * _1 * _1;

//-------------------------------------------------------------
//  (define (sum-integers a b)
//    (if (> a b)
//    0
//    (+a(sum - integers(+a 1) b))))
//
auto sum_integers = [](auto a, auto b)
{
  if (a > b) return 0;
  else       return a + sum_integers(a + 1, b);
};

//-------------------------------------------------------------
//  (define(sum - cubes a b)
//    (if (> a b)
//    0
//    (+(cube a) (sum - cubes(+a 1) b))))
//
auto sum_cubes = [](auto a, auto b)
{
  if (a > b) return 0;
  else       return cube(a) + (sum_cubes(a + 1, b));
};

//-------------------------------------------------------------
//  (define(pi - sum a b)
//   (if (> a b)
//   0
//   (+(/ 1.0 (*a(+a 2))) (pi - sum(+a 4) b))))
//
auto pi_sum = [](auto a, auto b)
{
  if (a > b) return 0.0;
  else       return (1.0 / (a*(a + 2)) + pi_sum(a + 4, b));
};

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
//  (define(inc n) (+n 1))
//  (define(sum - cubes a b)
//    (sum cube a inc b))
//
auto inc = _1 + 1;
auto sum_cubes2 = [](auto a, auto b)
{
  return sum(cube, a, inc, b);
};

//-------------------------------------------------------------
//  (define(identity x) x)
//  (define(sum - integers a b)
//    (sum identity a inc b))
//
auto identity = _1 + 0;
auto sum_integers2 = [](auto a, auto b)
{
  return sum(identity, a, inc, b);
};

//-------------------------------------------------------------
//  (define(pi - sum a b)
//    (define(pi - term x)
//      (/ 1.0 (*x(+x 2))))
//    (define(pi - next x)
//      (+x 4))
//    (sum pi - term a pi - next b))
//
auto pi_sum2 = [](auto a, auto b)
{
  auto term = 1.0 / (_1*(_1 + 2));
  auto next = _1 + 4;
  return sum(term, a, next, b);
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


int main()
{
  auto print = [](auto v) { std::cout << v << std::endl; };

  print(sum_integers(1, 10));
  print(sum_integers2(1, 10));
  print(sum_cubes(1, 10));
  print(sum_cubes2(1, 10));
  print(8 * pi_sum(1, 1000));
  print(8 * pi_sum2(1, 1000l));
  print(integral(cube, 0, 1, 0.01)); // (integral cube 0 1 0.01)
  print(integral(cube, 0, 1, 0.001)); // (integral cube 0 1 0.001)
  return 0;
}
