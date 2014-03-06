-- Exercise 1.16.  
-- Design a procedure that evolves an iterative exponentiation process that 
-- uses successive squaring and uses a logarithmic number of steps, 
-- as does fast-expt. 

square x = x * x

even? n = 0 == mod n 2

expt_iter a b n | 0 == n = a
                | even? n = expt_iter a (square b) (div n 2)
                | otherwise = expt_iter (a * b) b (n - 1)

expt b n = expt_iter 1 b n
                  
main = do
  print $ expt 2 8
  print $ expt 2 16
  print $ expt 2 32
