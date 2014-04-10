#include <cmath>                           // isless, isgrate, sin, cos
#include <cstdlib>                         // abs
#include <iostream>                        // cout, endl, << 
#include <cmath>                           // log
#include <string>                          // string, to_string
#include <boost/phoenix.hpp>               // _1, _2, *, 
#include <boost/math/constants/constants.hpp>
using namespace boost::phoenix::arg_names; // _1, _2, *, 
using namespace boost::phoenix;            // val 



auto print = [](auto v) { std::cout << v << std::endl; };

auto cf_r = [](auto cf_r, auto N, auto D, auto i, auto last_k)
{
  if (i == last_k) return N(i) / D(i);
  else             return N(i) / (D(i) + cf_r(cf_r, N, D, i + 1, last_k));

};

auto cf_i = [](auto cf_i, auto N, auto D, auto i, auto ret)
{
  if (i == 0)     return ret;
  else            return cf_i(cf_i, N, D, i - 1, N(i) / (D(i) + ret));
};

auto gr = [](auto last_k)
{
  return cf_r(cf_r, val(1.0), val(1.0), 1, last_k);
};

auto gi = [](auto last_k)
{
  return cf_i(cf_i, val(1.0), val(1.0), last_k, 0.0);
};

auto is_close_enough = [](auto x, auto y) { return std::abs(x - y) < 0.0001; };
int main()
{
  using namespace std;

  auto one_div_phi = 1.0 / boost::math::constants::phi<double>();
  print(one_div_phi);

  print(gr(10));
  print(gi(10));

  int i = 1;
  while (!is_close_enough(one_div_phi, gi(i++)));
  auto result = "gi(" + to_string(i) + ") =" + to_string(gi(i));
  print(result);

  return 0;
}

//-------------------------------------------------------------
// output
// 0.618034
// 0.617978
// 0.617978
// gi(11) = 0.618056
