square x = x * x
-- (define (f g)
--   (g 2))
f g = g 2

-- (f square)
-- 4
 
-- (f (lambda (z) (* z (+ z 1))))
-- 6

main = do
  print $ f square
  print $ f (\ z -> z * (z + 1))
  print $ f f -- compile error
