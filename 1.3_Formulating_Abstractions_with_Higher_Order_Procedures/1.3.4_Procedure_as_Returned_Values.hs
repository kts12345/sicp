import FixedPoint 
import Newton 

square x = x * x
cube x = x * x * x

-- (define (average-damp f)
--   (lambda (x) (average x (f x))))
average_damp f = 
  (\ x -> average x (f x))

-- (define (sqrt x)
--   (fixed-point (average-damp (lambda (y) (/ x y)))
--                1.0))

sqrt2 x = 
  fixed_point (average_damp (\ y -> x / y))
              1.0

-- (define (cube-root x)
--   (fixed-point (average-damp (lambda (y) (/ x (square y))))
--                  1.0))
cube_root x = 
  fixed_point (average_damp (\ y -> x / square y))
              1.0


-- (define (sqrt x)
--   (newtons-method (lambda (y) (- (square y) x))
--                     1.0))
sqrt_newton x =
  newtons_method (\ y -> square y - x) 
                 1.0

--(define (sqrt x)
--  (fixed-point-of-transform (lambda (y) (/ x y))
--                            average-damp
--                            1.0))
sqrt3 x = 
  fixed_point_of_transform (\ y -> x / y)
                           average_damp
                           0.1

-- (define (sqrt x)
--   (fixed-point-of-transform (lambda (y) (- (square y) x))
--                             newton-transform
--                             1.0))
sqrt4 x =
  fixed_point_of_transform (\ y -> square y - x)
                           newton_transform
                           0.1
      
main = do
  print $ average_damp square 10
  print $ sqrt2 4
  print $ sqrt2 2
  print $ cube_root 4
  print $ cube_root 27
  print $ deriv cube 5
  print $ sqrt_newton 4
  print $ sqrt3 2
  print $ sqrt3 4
  print $ sqrt4 2
  print $ sqrt4 4
