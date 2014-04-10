module Repeated (repeated) where

compose f g = f.g

repeated x n | n <= 0 = error "invalid input" 
             | n == 1 = x
             | otherwise = compose x $ repeated x (n - 1)
