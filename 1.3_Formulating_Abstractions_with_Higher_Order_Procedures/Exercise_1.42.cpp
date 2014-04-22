#include <iostream>                        // cout, endl, << 

template<typename... FnN> struct compose_fn;

template <typename Fn1, typename... FnN>
struct compose_fn <Fn1, FnN...>
{
  explicit compose_fn(Fn1 f1, FnN... fn) : fn1(f1), fnN(fn...) {}

  Fn1 fn1;
  compose_fn<FnN...> fnN;

  template <typename T>
  auto operator() (T x) const { return fn1(fnN(x)); }
};

template <> struct compose_fn<>
{
  template <typename T>
  auto operator() (T x) const { return x; }
};

template <typename Fn1, typename... FnN>
auto compose(Fn1 f1, FnN... fn) { return compose_fn<Fn1, FnN...>(f1, fn...); };

int main()
{
  auto print = [](auto v) { std::cout << v << std::endl; };

  auto square = [](auto x) { return x*x; };
  auto inc    = [](auto x) { return ++x; };

  // ((compose square inc) 6)
  print(compose(square, inc)(6));

  // test
  print(compose(square, inc, inc, inc, square)(2));
}
//-------------------------------------------------------------
// output
// 49 

