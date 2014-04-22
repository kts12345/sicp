#include <iostream>                        // cout, endl, << 
#include <functional>

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

//-----------------------------------------------------------------------------

template <typename T, typename N>
auto repeated(std::function<T(T)> f, N n) -> decltype(f)
{
  decltype(f) c = f;
  for (N i = 1; i < n; i++)
    c = (decltype(f))(compose(f, c));

  return c;
};

std::function<int(int)> square = [](int x) { return x*x; };

int main()
{
  auto print = [](auto v) { std::cout << v << std::endl; };

  // ((repeated square 2) 5)
  print(  repeated(square, 2)(5)   );

}
//-------------------------------------------------------------
// output
// 625

