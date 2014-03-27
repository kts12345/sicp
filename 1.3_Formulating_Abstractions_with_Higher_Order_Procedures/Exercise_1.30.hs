cube x = x * x * x

-- (define (sum term a next b)
--   (define (iter a result)
--     (if <??>
--         <??>
--         (iter <??> <??>)))
--   (iter <??> <??>))
--
-- int sum = 0;
-- for ( ; ; )
-- {
--   if (a > b)
--     break;
--   sum += term(a);
--   a = next(a);
-- }

sum2 term a next b =
  iter term a next b 0
  where
    iter term a next b sum | a > b = sum
                           | otherwise = iter term (next a) next b (sum + term a)

inc = succ
sum_cubes2 a b = sum2 cube a inc b

identity x = x

sum_integers2 a b = sum2 identity a inc b

pi_sum2 a b = sum2 pi_term a pi_next b
  where
    pi_term x = 1.0 / (x * (x + 2))
    pi_next x = x + 4

integral f a b dx = dx * sum2 f (a + (dx / 2.0)) add_dx b
  where
    add_dx = (+) dx

main = do
  print $ sum_cubes2 1 10
  print $ sum_integers2 1 10
  print $ 8 * pi_sum2 1 1000
  print $ integral cube 0 1 0.01
  print $ integral cube 0 1 0.001
