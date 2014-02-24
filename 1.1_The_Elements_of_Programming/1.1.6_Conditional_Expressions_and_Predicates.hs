-- sicp.1.1.6 Conditional Expressions and Predicates

import Prelude hiding(abs)

---------------------------------------

-- (cond (<p1> <e1>)
--       (<p2> <e2>)
--       (<pn> <en>))

-- (define (abs x)
--   (cond ((> x 0) x)
--         ((= x 0) 0)
--         ((< x 0) (- x))))
abs x | (>) x 0  = x
      | (==) x 0 = 0
      | (<)  x 0 = -x

---------------------------------------

-- (cond (<p1> <e1>)
--       (<p2> <e2>)
--       (else <e>))

-- define (abs x)
--    (cond ((< x 0) (- x))
--           (else x)))
abs' x | (<) x 0  = -x
       | otherwise = x

---------------------------------------

--  (if <predicate> <consequent> <alternative>)
--  (define (abs x)
--     (if (< x 0)
--         (- x)
--          x
abs'' x = 
       if (<) x 0
       then -x
       else  x
---------------------------------------

-- (and <e1> ... <en>)

-- (and (> x 5) (< x 10))
foo x = 
    (&&) ((>) x 5) ((<) x 10)

---------------------------------------

-- (or <e1> ... <en>)

-- (define (>= x y)
--     (or (> x y) (= x y)))
bar x y =
   (||) (x > y) (x == y)


main = do
 print $ abs (-13)
 print $ abs' (-1)
 print $ abs'' (-14)
 print $ foo 74
 print $ bar 74 734
 