import FixedPoint

-- (fixed-point cos 1.0)
-- .7390822985224023

-- (fixed-point (lambda (y) (+ (sin y) (cos y)))
--              1.0)
-- 1.2587315962971173

-- (define (sqrt x)
--   (fixed-point (lambda (y) (/ x y))
--                1.0))
sqrt2 x = fixed_point (\ y -> x / y) 1.0                 

-- (define (sqrt x)
--   (fixed-point (lambda (y) (average y (/ x y)))
--                1.0))
sqrt3 x = fixed_point (\ y -> average y (x / y)) 1.0

main = do
  print $ half_interval_method sin 2.0 4.0
  print $ half_interval_method (\ x -> (x * x * x) - (x * 2) - 3) 1.0 2.0
  print $ fixed_point cos 1.0
  print $ fixed_point (\ y -> sin y + cos y) 1.0
  -- print $ sqrt2 2
  print $ sqrt3 2
                
