import FixedPoint

iterative_improve good_enough improve_guess =
  (\x -> if good_enough x then x
         else iterative_improve good_enough improve_guess (improve_guess x))

average_damp f = 
  (\ x -> average x (f x))

tolerance = 0.00001

sqrt_new x = 
  iterative_improve good_enough improve_guess x
  where
    good_enough   = (\y -> abs (y * y - x) < tolerance)
    improve_guess = average_damp (\y -> x / y)

main = do
  print $ sqrt_new 4
  print $ sqrt_new 9
  print $ sqrt_new 16
  print $ sqrt_new 256



