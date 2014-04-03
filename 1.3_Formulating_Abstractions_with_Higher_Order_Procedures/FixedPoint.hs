module FixedPoint (fixed_point, half_interval_method, average) where

-- (define (search f neg-point pos-point)
--   (let ((midpoint (average neg-point pos-point)))
--       (if (close-enough? neg-point pos-point)
--           midpoint
--           (let ((test-value (f midpoint)))
--             (cond ((positive? test-value)
--                    (search f neg-point midpoint))
--                   ((negative? test-value)
--                    (search f midpoint pos-point))
--                   (else midpoint))))))

search f neg_point pos_point =
  let 
    midpoint = average neg_point pos_point
  in
    if close_enough neg_point pos_point then
      midpoint
    else
      let 
        test_value = f midpoint
      in
        if positive test_value then
          search f neg_point midpoint
        else
          if negative test_value then
            search f midpoint pos_point
          else
            midpoint
             
-- (define (close-enough? )
--   (< (abs (- x y)) 0.001))
close_enough x y = abs (x - y) < 0.001


-- (define (half-interval-method f a b)
--   (let ((a-value (f a))
--         (b-value (f b)))
--   (cond ((and (negative? a-value) (positive? b-value))
--          (search f a b))
--         ((and (negative? b-value) (positive? a-value))
--          (search f b a))
--         (else
--          (error "Values are not of opposite sign" a b)))))
half_interval_method f a b = 
  let 
    a_value = f a
    b_value = f b
  in
    if negative a_value && positive b_value then
      search f a b
    else
      if negative b_value && positive a_value then
        search f b a
      else
        error $ "Values are not of opposite sign" ++ show a ++ show b

-- (half-interval-method sin 2.0 4.0)
-- 3.14111328125

-- (half-interval-method (lambda (x) (- (* x x x) (* 2 x) 3))
--                        1.0
--                        2.0)
-- 1.89306640625
-- average :: [Float] -> Float
average x y = (x + y) / 2

positive x = x > 0
negative x = x < 0

-- (define tolerance 0.00001)
tolerance = 0.00001

-- (define (fixed-point f first-guess)
--   (define (close-enough? v1 v2)
--     (< (abs (- v1 v2)) tolerance))
--   (define (try guess)
--     (let ((next (f guess)))
--       (if (close-enough? guess next)
--           next
--           (try next))))
--   (try first-guess))
fixed_point f first_guess =
  try first_guess
  where
    close_enough v1 v2 = abs (v1 - v2) < tolerance
    try guess = let 
                  next = f guess
                in
                  if close_enough guess next then
                    next
                  else
                    try next

