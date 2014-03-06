-- Exercise 1.11.  
-- A function f is defined by the rule that 
-- f(n) = n if n<3 and f(n) = f(n - 1) + 2f(n - 2) + 3f(n - 3) if n >= 3. 
--
-- Write a procedure that computes f by means of a recursive process. 
f_r n | n < 3 = n
      | otherwise = (f_r (n - 1)) + (2 * f_r (n - 2)) + (3 * f_r (n - 3))

-- Write a procedure that computes f by means of an iterative process.
f_i n = f_iter 1 2 3 (n - 1)

f_iter a b c count = if 2 == count then (a * 2) + (b * 1)
                     else f_iter (b + a) (c + 2 * a) (a * 3) (count - 1)

-- f(0) = 0
-- f(1) = 1
-- f(2) = 2
-- f(3) = f(2) + 2*f(1) + 3*f(0)
-- f(4) = f(3) + 2*f(2) + 3*f(1)
-- f(5) = f(4) + 2*f(3) + 3*f(2)
-- f(6) = f(5) + 2*f(4) + 3*f(3) = 3*f(4) + 5*f(3) + 3*f(2) = 8*f(3) + 9*f(2) + 9*f(1)

main = do
  print $ (f_r 10 == f_i 10)
  print $ (f_r 11 == f_i 11)
  print $ (f_r 12 == f_i 12)
  print $ (f_r 13 == f_i 13)
  print $ (f_r 14 == f_i 14)
  print $ (f_r 15 == f_i 15)
  print $ (f_r 16 == f_i 16)
  print $ (f_r 17 == f_i 17)

