module Prime (prime, smallest_divisor) where

square x = x * x

-- (define (smallest-divisor n)
--   (find-divisor n 2))
smallest_divisor n = find_divisor n 2

-- (define (find-divisor n test-divisor)
--   (cond ((> (square test-divisor) n) n)
--         ((divides? test-divisor n) test-divisor)
--         (else (find-divisor n (+ test-divisor 1)))))
find_divisor n test_divisor | (square test_divisor) > n = n
                            | divides test_divisor n = test_divisor
                            | otherwise = find_divisor n (test_divisor + 1)

-- (define (divides? a b)
--   (= (remainder b a) 0))
divides a b = (mod b a) == 0

-- (define (prime? n)
--   (= n (smallest-divisor n)))
prime n = (smallest_divisor n) == n
