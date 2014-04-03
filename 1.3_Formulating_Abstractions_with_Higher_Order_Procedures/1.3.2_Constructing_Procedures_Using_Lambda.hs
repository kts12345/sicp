square x = x * x
cube x = x * x * x

sum2 term a next b = sum $ map term $ takeWhile (not.(<) b) $ iterate next a

-- (define (pi-sum a b)
--   (sum2 (lambda (x) (/ 1.0 (* x (+ x 2))))
--         a
--         (lambda (x) (+ x 4))
--         b))
pi_sum a b = 
  sum2 (\ x -> 1.0 / (x * (x + 2)))
       a
       (\ x -> x + 4)
       b
 
-- (define (integral f a b dx)
--   (* (sum2 f
--            (+ a (/ dx 2.0))
--            (lambda (x) (+ x dx))
--            b)
--       dx))
integral f a b dx =
  dx * sum2 f (a + dx / 2.0) (\ x -> x + dx) b

-- (define (f x y)
--   (define (f-helper a b)
--     (+ (* x (square a))
--        (* y b)
--        (* a b)))
--     (f-helper (+ 1 (* x y)) 
--               (- 1 y)))
f1 x y =
  f_helper (1 + (x * y)) (1 - y)
  where
    f_helper a b =
      (x * square a) + (y * b) + (a * b)

-- (define (f x y)
--   ((lambda (a b)
--     (+ (* x (square a))
--        (* y b)
--        (* a b)))
--    (+ 1 (* x y))
--    (- 1 y)))
f2 x y =
  (\ a b -> (x * square a) + (y * b) + (a * b))
  (1 + (x * y)) (1 - y)

-- (define (f x y)
--   (let ((a (+ 1 (* x y)))
--        (b (- 1 y)))
--     (+ (* x (square a))
--        (* y b)
--        (* a b))))
f3 x y = 
  let 
    a = 1 + (x * y)
    b = 1 - y
  in
    (x * square a) + (y * b) + (a * b)
    

main = do
  print $ 8 * pi_sum 1 1000
  print $ integral cube 0 1 0.001
  print $ f1 3 5
  print $ f2 3 5
  print $ f3 3 5
