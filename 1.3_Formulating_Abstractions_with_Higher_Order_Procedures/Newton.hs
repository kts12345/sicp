module Newton (newton_transform, newtons_method, deriv, fixed_point_of_transform) where

import FixedPoint

-- (define (deriv g)
--   (lambda (x)
--       (/ (- (g (+ x dx)) (g x))
--              dx)))
deriv g = (\ x -> (g (x + dx) - g x) / dx)

-- (define dx 0.00001)
dx = 0.00001

-- (define (newton-transform g)
--   (lambda (x)
--       (- x (/ (g x) ((deriv g) x)))))
newton_transform g = (\ x -> x - g x / deriv g x)

-- (define (newtons-method g guess)
--   (fixed-point (newton-transform g) guess))
newtons_method g guess = 
  fixed_point (newton_transform g) guess

-- (define (fixed-point-of-transform g transform guess)
--   (fixed-point (transform g) guess)) 
fixed_point_of_transform g transform guess =
  fixed_point (transform g) guess
