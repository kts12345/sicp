import Prime

---- The Fermat test : TOOD
--even n = mod n 2 == 0
--
---- (define (expmod base exp m)
----   (cond ((= exp 0) 1)
----         ((even? exp)
----          (remainder (square (expmod base (/ exp 2) m))
----                             m))
----         (else
----          (remainder (* base (expmod base (- exp 1) m))
----                      m)))) 
--expmod base exp m | exp == 0 = 1
--                  | even? exp = mod (square $ expmod base (div exp 2) m) m
--                  | otherwise = mod (base * (expmod base (exp - 1) m)) m
--
---- (define (fermat-test n)
----   (define (try-it a)
----     (= (expmod a n n) a))
----   (try-it (+ 1 (random (- n 1)))))
--fermat_test n = try_it (1 + random (n - 1))
--    where try_it a = (expmod a n n) == a
--
---- (define (fast-prime? n times)
----   (cond ((= times 0) true)
----         ((fermat-test n) (fast-prime? n (- times 1)))
----         (else false)))
--fast_prime n times | times == 0 = True
--                   | fermat_test n = fast_prime? n (times - 1)
--                   otherwise False

main = do
  print $ prime 3
  print $ prime 101
  print $ prime 36
--   print $ fast_prime 3
--   print $ fast_prime 101
--   print $ fast_prime 36
   
