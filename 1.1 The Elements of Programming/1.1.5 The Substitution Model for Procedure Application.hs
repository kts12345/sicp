-- sicp.1.1.5 The Substitution Model for Procedure Application

-- (define (square x) (* x x))
square x = (*) x x

-- (define (sum-of-squares x y)
--         (+ (square x) (square y)))
sum_of_squares x y  = 
    (+) (square x) (square y)

-- (define (f a)
--         (sum-of-squares (+ a 1) (* a 2)))
f a = 
    sum_of_squares ((+) a 1) ((*) a 2)

main = do
 print $ f 5  -- (f 5)