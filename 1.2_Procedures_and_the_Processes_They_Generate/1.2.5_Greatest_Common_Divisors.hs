import Prelude hiding (gcd)

-- (define (gcd a b)
--   (if (= b 0)
--       a
--       (gcd b (remainder a b))))
gcd a b = if 0 == b then a
          else gcd b $ mod a b 


main = do
  print $ 5 == gcd 15 5
  print $ 12 == gcd 36 24
