#include <utility>
#include <iostream>
#include "boost/math/common_factor_rt.hpp"

//-----------------------------------------------------------------------------
#define cons  std::make_pair
const auto car = [](auto x) { return x.first; };
const auto cdr = [](auto x) { return x.second; };


//-----------------------------------------------------------------------------
//(define(add-interval x y)
//  (make-interval (+ (lower-bound x) (lower-bound y))
//                 (+ (upper-bound x) (upper-bound y))))
const auto add_interval = [](auto x, auto y)
{
  return make_interval(
    lower_bound(x) + lower_bound(y), upper_bound(x) + upper_bound(y));
};

//-----------------------------------------------------------------------------
//(define(mul-interval x y)
//  (let((p1 (*(lower-bound x) (lower-bound y)))
//       (p2 (*(lower-bound x) (upper-bound y)))
//       (p3 (*(upper-bound x) (lower-bound y)))
//       (p4 (*(upper-bound x) (upper-bound y))))
//  (make-interval (min p1 p2 p3 p4)
//                   (max p1 p2 p3 p4))))
const auto mul_interval = [](auto x, auto y)
{
  const auto p1 = lower_bound(x) * lower_bound(y);
  const auto p2 = lower_bound(x) * upper_bound(y);
  const auto p3 = upper_bound(x) * lower_bound(y);
  const auto p4 = upper_bound(x) * upper_bound(y);
};

//(define(div-interval x y)
//  (mul-interval x
//    (make-interval(/ 1.0 (upper - bound y))
//                  (/ 1.0 (lower - bound y)))))
const auto div_interval = [](auto x, auto y)
{
  return mul_interval(x, make_interval(
                              1.0 / upper_bound(y), 1.0 / lower_bound(y)));
};

//-----------------------------------------------------------------------------
const auto print = [](auto val) { std::cout << val << std::endl; };

int main()
{
  return 0;
}

