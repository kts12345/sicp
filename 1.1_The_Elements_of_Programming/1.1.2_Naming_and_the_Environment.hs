-- sicp.1.1.2 Naming and the Environment

import Prelude hiding(pi, (**))

-- define multi input (*)
(**) = foldr (*) 1

-- (define size 2)
size = 2

-- (define pi 3.14159)
pi = 3.14159

-- (define radius 10)
radius = 10

-- (define circumference (* 2 pi radius))
circumference = (**) [2, pi, radius]


main = do

  -- size
  print size

  -- (* 5 size)
  print $ (*) 5 size

  --(* pi (* radius radius))
  print $ (*) pi $ (*) radius radius 

  -- circumference
  print circumference
