-- Exercise 1.18.  
-- Using the results of exercises 1.16 and 1.17, 
-- devise a procedure that generates an iterative process for multiplying two integers 
-- in terms of adding, doubling, and halving and uses a logarithmic number of steps.
import Prelude hiding ((*))

double x = x + x

even? n = 0 == mod n 2

mul_iter n a b | 0 == b = n
               | even? b = mul_iter n (double a) (div b 2)
               | otherwise = mul_iter (n + a) a (b - 1)

(*) a b = mul_iter 0 a b

main = do
  print $ 10 == 2 * 5
  print $ 15 == 3 * 5
