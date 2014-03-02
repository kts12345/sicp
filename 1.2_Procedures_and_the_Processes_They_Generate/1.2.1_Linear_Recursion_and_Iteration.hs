--sicp.1.2.1 Linear Recursion and Iteration

--(define (factorial_r n)
--  (if (= n 1)
--       1
--      (* n (factorial_r (- n 1)))))

factorial_r n 
   | n == 1     = 1
   | otherwise  = (*) n (factorial_r ((-) n 1))



-- (define (factorial n)
--    (fact-iter 1 1 n))
factorial = fact_iter 1 1

-- (define (fact-iter product counter max-count)
--    (if (> counter max-count)
--         product
--        (fact-iter (* counter product)
--                   (+ counter 1)
--                   max-count)))
fact_iter product counter max_count
    | (>) counter max_count = product
    | otherwise             = fact_iter ((*) counter product)
                                        ((+) counter 1) 
                                        max_count


main = do
  print $ factorial_r 6
  print $ factorial   6