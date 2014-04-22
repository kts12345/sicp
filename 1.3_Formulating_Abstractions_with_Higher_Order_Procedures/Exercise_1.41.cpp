#include <iostream>                        // cout, endl, << 

//-------------------------------------------------------------
auto double_f = [](auto f){ return [f](auto x) { return f(f(x)); }; };

auto inc = [](auto x) { return ++x; };

int main()
{
  auto print = [](auto v) { std::cout << v << std::endl; };

  // test
  print(double_f(inc)(10));

  //(((double(double double)) inc) 5)
  auto val = double_f(double_f(double_f))(inc)(5);
  print(val);
  return 0;
}

//-------------------------------------------------------------
// output
// 12 
// 21 

