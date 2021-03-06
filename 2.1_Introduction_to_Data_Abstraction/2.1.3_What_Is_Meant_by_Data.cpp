#include <utility>
#include <iostream>
#include "boost/math/common_factor_rt.hpp"

//-----------------------------------------------------------------------------
//(define(cons x y)
//  (define(dispatch m)
//    (cond((= m 0) x)
//    ((= m 1) y)
//    (else (error "Argument not 0 or 1 -- CONS" m))))
//  dispatch)
//
//  (define(car z) (z 0))
//
//  (define(cdr z) (z 1))
//
const auto cons = [](auto x, auto y)
{
  const auto dispatch = [x, y](const auto m)
  {
    if (m == 0) return x;
    else if (m == 1) return y;
    else throw "Argument not 0 or 1 --CONS";
  };
  return dispatch;
};

const auto car = [](auto z) { return z(0); };
const auto cdr = [](auto z) { return z(1); };

//-----------------------------------------------------------------------------
// (define(add - rat x y)
//    (make-rat (+ (*(numer x) (denom y))
//                 (*(numer y) (denom x)))
//              (* (denom x) (denom y))))
const auto add_rat = [](auto x, auto y)
{
  return make_rat( (numer(x) * denom(y)) + (numer(y) * denom(x)),
                   denom(x) * denom(y));
};

//-----------------------------------------------------------------------------
// (define(sub - rat x y)
//    (make-rat (- (*(numer x) (denom y))
//                 (*(numer y) (denom x)))
//              (* (denom x) (denom y))))
const auto sub_rat = [](auto x, auto y)
{
  return make_rat( (numer(x) * denom(y)) - (numer(y) * denom(x)),
                   denom(x) * denom(y));
};

//-----------------------------------------------------------------------------
// (define(mul - rat x y)
//   (make-rat (* (numer x) (numer y))
//             (* (denom x) (denom y))))
const auto mul_rat = [](auto x, auto y)
{
  return make_rat( numer(x) * numer(y),
                   denom(x) * denom(y));
};

//-----------------------------------------------------------------------------
// (define(div - rat x y)
//    (make-rat(* (numer x) (denom y))
//             (* (denom x) (numer y))))
//
const auto div_rat = [](auto x, auto y)
{
  return make_rat( numer(x) * denom(y),
                   denom(x) * numer(y));
};

//-----------------------------------------------------------------------------
// (define (equal-rat? x y)
//   (= (* (numer x) (denom y))
//      (* (numer y) (denom x))))
const auto equal_rat = [](auto x, auto y)
{
  return (numer(x) * denom(y)) == (numer(y) * denom(x));
};

//=============================================================================
// Representing rational numbers
//-----------------------------------------------------------------------------


const auto make_rat = [](auto n, auto d)  { return cons(n, d); };

const auto numer    = [](auto x)          
{ 
  const auto g = boost::math::gcd_evaluator<decltype(car(x))>()(car(x), cdr(x));
  return car(x)/g; 
};

const auto denom    = [](auto x)          
{ 
  const auto g = boost::math::gcd_evaluator<decltype(car(x))>()(car(x), cdr(x));
  return cdr(x)/g; 
};

//-----------------------------------------------------------------------------
// (define(print - rat x)
//   (newline)
//   (display(numer x))
//   (display "/")
//   (display(denom x)))
const auto print_rat = [](auto x)
{
  std::cout << std::endl;
  std::cout << numer(x);
  std::cout << "/";
  std::cout << denom(x);
};


//(define(cons x y)
//  (define(dispatch m)
//  (cond((= m 0) x)
//  ((= m 1) y)
//  (else (error "Argument not 0 or 1 -- CONS" m))))
//  dispatch)
//
//  (define(car z) (z 0))
//
//  (define(cdr z) (z 1))
//
//-----------------------------------------------------------------------------
const auto print = [](auto val) { std::cout << val << std::endl; };

int main()
{
  
  // test
  {
    auto x = cons(1, 2); // (define x (cons 1 2))
    print(car(x));       // (car x) 
    print(cdr(x));       // (cdr x)
  }

  // test
  {
    auto x = cons(1, 2); // (define x(cons 1 2))
    auto y = cons(3, 4); // (define y(cons 3 4))
    auto z = cons(x, y); // (define z (cons x y))
    print(car(car(z)));  // (car (car z))
    print(car(cdr(z)));  // (car (cdr z))
  }

  //test
  {
    // (define one-half (make-rat 1 2))
    // (print-rat one-half)
    auto one_half = make_rat(1, 2);
    print_rat(one_half);

    // (define one-third (make-rat 1 3))
    // (print-rat (add-rat one-half one-third))
    // (print-rat (mul-rat one-half one-third))
    // (print-rat (add-rat one-third one-third))
    auto one_third = make_rat(1, 3);
    print_rat(add_rat(one_half, one_third));
    print_rat(mul_rat(one_half, one_third));
    print_rat(add_rat(one_third, one_third));
  }

  // test
  {
    auto one_half = make_rat(1, 2);
    auto one_third = make_rat(1, 3);

    // (define(make - rat n d)
    //  (let((g(gcd n d)))
    //  (cons(/ n g) (/ d g))))
    const auto make_rat = [](auto n, auto d)
    {
      const auto g = boost::math::gcd_evaluator<decltype(n)>()(n, d);
      return cons(n / g, d / g);
    };

    const auto add_rat = [make_rat](auto x, auto y)
    {
      return make_rat((numer(x) * denom(y)) + (numer(y) * denom(x)),
        denom(x) * denom(y));
    };

    print_rat(add_rat(one_third, one_third));
  }


  return 0;
}


//-----------------------------------------------------------------------------
// output
// 1
// 2
// 1
// 3
// 1 / 2
// 5 / 6
// 1 / 6
// 2 / 3
// 2 / 3

