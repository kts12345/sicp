
square x = x * x

next n = if n == 2 then 3 
         else n + 2

smallest_divisor n = find_divisor n 2

find_divisor n test_divisor | (square test_divisor) > n = n
                            | divides test_divisor n = test_divisor
                            | otherwise = find_divisor n $ next test_divisor 

divides a b = (mod b a) == 0

prime n = (smallest_divisor n) == n

main = do
  print $ prime 3
  print $ prime 18
  print $ prime 101
