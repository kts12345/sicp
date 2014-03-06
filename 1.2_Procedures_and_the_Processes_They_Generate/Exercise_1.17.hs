-- Exercise 1.17.  
-- The exponentiation algorithms in this section are based on performing 
-- exponentiation by means of repeated multiplication. 
-- In a similar way, one can perform integer multiplication 
-- by means of repeated addition. 
-- The following multiplication procedure 
-- (in which it is assumed that our language can only add, 
-- not multiply) is analogous to the expt procedure:

import Prelude hiding ((*))
-- (define (* a b)
--   (if (= b 0)
--       0
--       (+ a (* a (- b 1)))))
-- (*) a b = if 0 == b then 0
--           else a + (a * (b - 1))

-- This algorithm takes a number of steps that is linear in b. 
-- Now suppose we include, together with addition, operations double, 
-- which doubles an integer, and halve, which divides an (even) integer by 2. 
-- Using these, design a multiplication procedure analogous to fast-expt 
-- that uses a logarithmic number of steps.

double x = x + x

even? n = 0 == mod n 2

(*) a b | 0 == b = 0
        | even? b = double $ a * (div b 2)
        | otherwise = a + (a * (b - 1))

main = do
  print $ 10 == 2 * 5
  print $ 15 == 3 * 5

