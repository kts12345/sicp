//sicp.1.3.2_Constructing_Procedures_Using_Lambda

#include <iostream>                        // cout, endl, << 
#include <boost/phoenix.hpp>               // arg1, arg2, +, *, >

using namespace boost::phoenix::arg_names; // arg1, arg2, +, *, >

auto square = arg1 * arg1;

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
//  (lambda (x) (+ x 4))
//
auto lambda_1 = [](auto x) { return x + 4; };
auto lambda_2 = arg1 + 4;



//-------------------------------------------------------------
//  (lambda (x) (/ 1.0 (* x (+ x 2))))
//
auto lambda_3 = [](auto x) { return 1.0 / (x * (x + 2)); };
auto lambda_4 = 1.0 / (arg1 * (arg1 + 2));



//-------------------------------------------------------------
//  (define(pi - sum a b)
//    (sum (lambda(x) (/ 1.0 (*x(+x 2))))
//         a
//         (lambda(x) (+x 4))
//         b))
template <typename Num>
auto pi_sum_1(Num a, Num b)
{
  return sum([](auto x){ return 1.0 / (x * (x + 2)); },
    a,
    [](auto x) { return x + 4; },
    b);
};
//    is equivalent to
auto pi_sum_2 = [](auto a, auto b)
{
  return sum(1.0 / (arg1 * (arg1 + 2)),
    a,
    arg1 + 4,
    b);
};

//------------------------------------------------------------
// (define(integral f a b dx)
//   (*(sum  f
//          (+a(/ dx 2.0))
//          (lambda(x) (+x dx))
//          b)
//     dx))
//
auto integral = [](auto f, auto a, auto b, auto dx)
{
  return sum(f, a + dx / 2.0, arg1 + dx, b) * dx;
};

//-------------------------------------------------------------
// (define (plus4 x) (+x 4))
//    is equivalent to
// (define plus4  (lambda(x) (+x 4)))
//
template <typename Num>
auto plus4_1(Num x) { return x + 4; };
// is equivalent to
auto plus4_2 = [](auto x) { return x + 4; };
// is equivalent to
auto plus4_3 = arg1 + 4;

//-------------------------------------------------------------
// ((lambda(x y z) (+x y(square z)))
//   1 2 3)
// 12
auto val_12_1 = ([](auto x, auto y, auto z){ return x + y + square(z); })(1, 2, 3);
// is equivalent to
auto val_12_2 = (arg1 + arg2 + square(arg3))(1, 2, 3);


//-------------------------------------------------------------
// (define(f x y)
//   (define(f-helper a b)
//      (+  (* x (square a))
//          (* y b)
//          (* a b)))
//   (f-helper (+ 1 (*x y))
//             (- 1 y)))
//
auto f_1 = [](auto x, auto y)
{
  auto f_helper = x*square(arg1) + y*arg2 + arg1*arg2;
  return f_helper(1 + x*y, 1 - y);
};

//-------------------------------------------------------------
//  (define(f x y)
//    ((lambda(a b)
//          (+ (* x (square a))
//             (* y b)
//             (* a b)))
//    (+1 (*x y))
//    (-1 y)))
//
auto f_2 = [](auto x, auto y)
{
  return (x * square(arg1) + y*arg2 + arg1*arg2)(1 + x*y, 1 - y);
};

//------------------------------------------------------------
//  (define(f x y)
//    (let ((a (+1 (*x y)))
//          (b (-1 y)))
//    (+ (* x (square a))
//       (* y b)
//       (* a b))))
//
auto f_3 = [](auto x, auto y)
{
  auto a = 1 + x*y;
  auto b = 1 - y;
  return
    x*square(a) + y*b + a*b;
};

//------------------------------------------------------------
// (define x 5)
// (+ (let ((x 3))
//      (+ x (* x 10)))
//    x)
// 38
auto val_38 = [x = 5]
{
  auto let_body = [x = 3] { return x + x * 10; }();
  return let_body + x;
}();

//------------------------------------------------------------
//  (define x 2)
//  (let((x 3)
//       (y (+ x 2)))
//    (* x y))
// 12 
auto val_12_3 = [x = 2]
{
  auto let_body = [x = 3, y = x + 2] { return x*y; }();
  return let_body;
}();

//------------------------------------------------------------
//  (define(f x y)
//    (define a (+1 (*x y)))
//    (define b (-1 y))
//    (+ (* x (square a))
//       (* y b)
//       (* a b)))
//
auto f_4 = [](auto x, auto y)
{
  auto a = 1 + x*y;
  auto b = 1 - y;
  return
    x*square(a) + y*b + a*b;
}

// test
int main()
{
  auto print = [](auto v) { std::cout << v << std::endl; };
  auto cube = arg1 * arg1 * arg1;

  print(8 * pi_sum_1(1, 1000));
  print(8 * pi_sum_2(1, 1000));
  print(integral(cube, 0, 1, 0.01)); // (integral cube 0 1 0.01)
  print(integral(cube, 0, 1, 0.001)); // (integral cube 0 1 0.001)
  print(val_12_1);
  print(val_12_2);
  print(f_1(3, 4));
  print(f_2(3, 4));
  print(f_3(3, 4));
  print(f_4(3, 4));
  print(val_38);
  print(val_12_3);

  return 0;
}
