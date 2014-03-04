-- (define (fib n)
--   (cond ((= n 0) 0)
--         ((= n 1) 1)
--         (else (+ (fib (- n 1))
--                  (fib (- n 2))))))
fib n | n == 0 = 0
      | n == 1 = 1
      | otherwise = fib (n - 1) + fib (n - 2)

-- (define (fib n)
--   (fib-iter 1 0 n))
-- 
-- (define (fib-iter a b count)
--   (if (= count 0)
--       b
--       (fib-iter (+ a b) a (- count 1))))
fib_i n = fib_iter 1 0 n

fib_iter a b count = if count == 0 then b
                     else fib_iter (a + b) a (count - 1)

main = do
  print $ fib 6
  print $ fib_i 6
