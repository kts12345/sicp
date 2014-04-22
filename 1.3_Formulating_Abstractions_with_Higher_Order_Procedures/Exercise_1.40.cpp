#include <cstdlib>                         // abs
#include <iostream>                        // cout, endl, << 

//-------------------------------------------------------------
auto tolerance = 0.00001;

auto is_close_enough = [](auto v1, auto v2)
{ return std::abs(v1 - v2) < tolerance; };

template <typename Func, typename Num>
auto fixed_point(Func f, Num first_guess)
{
  auto try_f = [](auto f, auto try_f, auto guess)
  {
    auto next = f(guess);
    if (is_close_enough(guess, next)) return next;
    else                              return try_f(f, try_f, next);
  };

  return try_f(f, try_f, first_guess);
};

// (define dx 0.00001)
auto dx = 0.00001;

// (define(deriv g)
//  (lambda(x) (/ (-(g(+x dx)) (g x)) dx)))
auto deriv = [](auto g)
{ 
  return [g](auto x){ return  (g(x + dx) - g(x)) / dx; };
};

//define(newton - transform g)
// (lambda(x) (- x (/ (g x) ((deriv g) x)))))
auto newton_transform = [](auto g)
{
  return [g](auto x){ return x - (g(x) / ((deriv(g)) (x))); };
};

// (define(newtons - method g guess)
//   (fixed - point(newton - transform g) guess))
auto newtons_method = [](auto g, auto guess)
{
  return fixed_point((newton_transform(g)), guess);
};

// Define a procedure cubic that can be used together
// with the newtons - method procedure in expressions of the form
// (newtons - method(cubic a b c) 1)
// to approximate zeros of the cubic x3 + ax2 + bx + c.
auto cubic = [](auto a, auto b, auto c)
{
  return newtons_method([a, b, c](auto x){return x*x*x + a*x*x + b*x + c; }, 1);
};


int main()
{
  auto print = [](auto v) { std::cout << v << std::endl; };

  print(cubic(1, 1, 1));
  print(cubic(1, 1, 6));
  return 0;
}

//-------------------------------------------------------------
// output
// -1
// -2

