import FixedPoint
import Repeated
import Power

average_damp f = 
  (\ x -> average x (f x))

forth_root x =
  fixed_point ((average_damp.average_damp) (\ y -> x / nth_power y 3))
              1.0

nth_root x n =
  fixed_point (repeated_average_damp f) 1.0
  where
    repeated_average_damp = repeated average_damp (n - 1) 
    f = (\y -> x / nth_power y (n - 1))

main = do
  print $ nth_power 3 4
  print $ forth_root 81
  print $ nth_root 256 8
  print $ nth_root 1024 10 
