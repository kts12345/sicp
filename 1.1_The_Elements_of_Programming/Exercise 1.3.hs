-- sicp.exercise.1.3
-------------------------------------------------------
-- * Problem : 
--   Define a procedure that takes three numbers as arguments and returns the sum of the
--   squares of the two larger numbers.

---------------------------------------------------------
-- * Answer

--(define (square x) (* x x))
square x = x * x

--(define (sum-of-squares x y)
--  (+ (square x) (square y)))
sum_of_squares x y = 
    (+) (square x) (square y)

--(define (sum-of-squares-without-min x y z)
--    (cond ((and (< x y)(< x z)) (sum-of-squares y z))
--          ((< y z)              (sum-of-squares z x))
--          (else                 (sum-of-squares x y))))
sum_of_squares_without_min x y z 
    | (&&) ((<) x y) ((<) x z) = sum_of_squares y z
    | (<) y z                  = sum_of_squares z x
    | otherwise                = sum_of_squares x y

-------------------------------------------------------
-- * Test
--(sum-of-squares-without-min 1 2 3)
--(sum-of-squares-without-min 3 4 2)
--(sum-of-squares-without-min 5 4 3)  
main = do
  print $ sum_of_squares_without_min 1 2 3
  print $ sum_of_squares_without_min 3 4 2
  print $ sum_of_squares_without_min 5 4 3   

-- ========================================================
-- Output
----------------------------------------------------------
-- 13
-- 25
-- 41
