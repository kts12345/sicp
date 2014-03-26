/* Exercise 1.29: Simpson¡¯s Rule is a more accurate method of numerical
integration than the method illustrated above.Using Simpson¡¯s
Rule, the integral of a function f between a and b is approximated
as
h/3 * (y0 + 4y1 + 2y2 + 4y3 + 2y4 + . . . + 2yn¢®2 + 4yn¢®1 + yn),
where h = (b - a) / n, for some even integer n, and yk = f(a + kh).
(Increasing n increases the accuracy of the approximation.) Define
a procedure that takes as arguments f, a, b, and n and returns the
value of the integral, computed using Simpson¡¯s Rule.Use your
procedure to integrate cube between 0 and 1 (with n = 100 and n =
1000), and compare the results to those of the integral procedure
shown above.
*/



/*
cube x = x * x * x

simpsons_rule f a b n =
let
h = (b - a) / n
in
(h / 3.0) * (sum $ g f h 0 n)
where
g f h k n | k == 0 = f(a + k * h) : g f h(k + 1) n
| k == n = f(a + k * h) : []
| mod k 2 == 0 = 2 * f(a + k * h) : g f h(k + 1) n
| otherwise = 4 * f(a + k * h) : g f h(k + 1) n


main = do
print $ simpsons_rule cube 0 1 100
print $ simpsons_rule cube 0 1 1000
*/

//-------------------------------------------------------------
//  (define(cube x) (*x x x))
//
auto cube = _1 * _1 * _1;

int main()
{
  auto print = [](auto v) { std::cout << v << std::endl; };
  return 0;
}