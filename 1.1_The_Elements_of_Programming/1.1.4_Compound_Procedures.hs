-- sicp.1.1.4 Compound Procedures

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

 --     (square 21)
 print $ square 21

 --     (square (+ 2 5))
 print $ square $ (+) 2 5

 --      (square (square 3))
 print $ (square.square) 3

 --     (sum-of-squares 3 4)
 print $ sum_of_squares 3 4

 --     (f 5)
 print $ f 5