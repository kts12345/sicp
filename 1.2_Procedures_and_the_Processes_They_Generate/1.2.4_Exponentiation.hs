square x = x * x

remainder = mod

-- (define (expt b n)
--   (if (= n 0)
--       1
--       (* b (expt b (- n 1)))))
expt b n = if 0 == n then 1
           else b * expt b (n - 1)

-- (define (expt b n)
--   (expt-iter b n 1))
expt_i b n = expt_iter b n 1
 
-- (define (expt-iter b counter product)
--   (if (= counter 0)
--       product
--       (expt-iter b
--                  (- counter 1)
--                  (* b product)))) 
expt_iter b counter product = if 0 == counter then product
                              else expt_iter b (counter - 1) (b * product)
 
-- (define (fast-expt b n)
--   (cond ((= n 0) 1)
--         ((even? n) (square (fast-expt b (/ n 2))))
--         (else (* b (fast-expt b (- n 1))))))
fast_expt b n | 0 == n = 1
              | even? n = square $ fast_expt b (div n 2)
              | otherwise = b * fast_expt b (n - 1) 

-- (define (even? n)
--   (= (remainder n 2) 0))
even? n = 0 == remainder n 2

main = do
  print $ expt 2 8
  print $ expt 2 16
  print $ expt 2 32
  print $ expt_i 2 8
  print $ expt_i 2 16
  print $ expt_i 2 32
  print $ fast_expt 2 8
  print $ fast_expt 2 16
  print $ fast_expt 2 32
