-- (define (cons x y)
--   (lambda (m) (m x y)))
cons x y = (\m -> m x y) 

-- (define (car z)
--   (z (lambda (p q) p)))
car z = z (\p _ -> p)

-- (define (cdr z)
--   (z (lambda (p q) q)))
cdr z = z (\_ q -> q)

main = do
  -- car (cons 10 20)
  -- (cons 10 20) (\p _ -> p)
  -- (\m -> m 10 20) (\p _ -> p)
  -- (\p _ -> p) 10 20
  -- 10
  print $ car $ cons 10 20
  print $ cdr $ cons 10 20
