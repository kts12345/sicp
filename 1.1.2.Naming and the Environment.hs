import Prelude hiding(pi)

size = 2      -- (define size 2)
pi = 3.14159  -- (define pi 3.14159)
radius = 10   -- (define radius 10)
circumference = foldl (*) 1 [2, pi, radius]-- (define circumference (* 2 pi radius))

main = do
 print size -- size
 print $ (*) 5 size -- (* 5 size)
 print $ (*) pi $ (*) radius radius --(* pi (* radius radius))
 print circumference  -- circumference  
 