module FastPrime (fast_prime) where

import Prime

square x = x * x

-- The Fermat test : TOOD

-- (define (expmod base exp m)
--   (cond ((= exp 0) 1)
--         ((even? exp)
--          (remainder (square (expmod base (/ exp 2) m))
--                             m))
--         (else
--          (remainder (* base (expmod base (- exp 1) m))
--                      m)))) 
expmod base exp m | exp == 0 = 1
                  | even exp = mod (square $ expmod base (div exp 2) m) m
                  | otherwise = mod (base * (expmod base (exp - 1) m)) m

---- (define (fermat-test n)
----   (define (try-it a)
----     (= (expmod a n n) a))
----   (try-it (+ 1 (random (- n 1)))))
-- fermat_test n r = try_it r
--   where try_it a = (expmod a n n) == a
fermat_test n r = (expmod r n n) == r

-- (define (fast-prime? n times)
--   (cond ((= times 0) true)
--         ((fermat-test n) (fast-prime? n (- times 1)))
--         (else false)))
fast_prime n times (x : xs) | times == 0 = True
                            | fermat_test n x = fast_prime n (times - 1) xs
                            | otherwise = False

