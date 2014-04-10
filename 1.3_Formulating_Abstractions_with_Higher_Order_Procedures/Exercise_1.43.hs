import Repeated

square x = x * x

repeated x n | n <= 0 = error "invalid input" 
             | n == 1 = x
             | otherwise = compose x $ repeated x (n - 1)

-- ((repeated square 2) 5)
-- 625
main = do
  print $ repeated square 2 5
  print $ repeated square 0 5
