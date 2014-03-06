-- Exercise 1.10.  
-- The following procedure computes a mathematical function called 
-- Ackermann's function.
--
-- (define (A x y)
--   (cond ((= y 0) 0)
--         ((= x 0) (* 2 y))
--         ((= y 1) 2)
--         (else (A (- x 1) 
--                  (A x (- y 1))))))
a x y | y == 0 = 0
      | x == 0 = (2 * y)
      | y == 1 = 2
      | otherwise = a (x - 1) (a x (y - 1))

-- (define (f n) (A 0 n))
f n = a 0 n 

-- (define (g n) (A 1 n))
g n = a 1 n

-- (define (h n) (A 2 n))
h n = a 2 n

-- What are the values of the following expressions?
--
-- (a 1 10)
-- 
-- (a 2 4)
-- 
-- (a 3 3)
main = do
  print $ a 1 10
  print $ a 2 4
  print $ a 3 3 
  print $ f 3 -- 2 * 3
  print $ f 4 -- 2 * 4
  print $ g 3 -- 2 ^ 3
  print $ g 4 -- 2 ^ 4
  print $ h 3 -- 2 ^ (2 ^ 2)
  print $ h 4 -- 2 ^ (2 ^ (2 ^ 2)) 

-- Consider the following procedures, where A is the procedure defined above:
-- 
-- (define (f n) (A 0 n))
-- => compute 2n
-- 
-- (define (g n) (A 1 n))
-- => compute 2^n 
--
-- (define (h n) (A 2 n))
-- => compute 2 ^ (2 ^ (2...))
--
-- (define (k n) (* 5 n n))
--
-- Give concise mathematical definitions for the functions computed by 
-- the procedures f, g, and h for positive integer values of n. 
-- For example, (k n) computes 5n^2.
