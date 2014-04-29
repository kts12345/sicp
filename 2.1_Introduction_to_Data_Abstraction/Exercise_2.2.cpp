#include <utility>
#include <iostream>
#include <cmath>
#include "boost/math/common_factor_rt.hpp"

//-----------------------------------------------------------------------------
const auto cons = [](auto x, auto y) 
{ 
  std::pair<decltype(x), decltype(y)> pair(x, y);
  return pair;
};

const auto car = [](auto x) { return x.first; };
const auto cdr = [](auto x) { return x.second; };

const auto make_point = cons;
const auto x_point    = car;
const auto y_point    = cdr; 


const auto make_segment  = cons;
const auto start_segment = car;
const auto end_segment   = cdr;

const auto midpoint_segment = [](auto s)
{
  return make_point((x_point(start_segment(s)) + x_point(end_segment(s)))/2, 
                    (y_point(start_segment(s)) + y_point(end_segment(s)))/2);

};


//-----------------------------------------------------------------------------
//(define(print-point p)
//  (newline)
//  (display "(")
//  (display(x-point p))
//  (display ",")
//  (display(y-point p))
//  (display ")"))
const auto print_point = [](auto p)
{
  std::cout << std::endl;
  std::cout << "(";
  std::cout << x_point(p);
  std::cout << ", ";
  std::cout << y_point(p);
  std::cout << ")";
};

int main()
{
  // test
  auto p1 = make_point(3.0, 14.0);
  auto p2 = make_point(5.0, 16.0);

  const auto s = make_segment(p1, p2);
  print_point(midpoint_segment(s));
}


//-----------------------------------------------------------------------------
// output
// (4, 15) 

