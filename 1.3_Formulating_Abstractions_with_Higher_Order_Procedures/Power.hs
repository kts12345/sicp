module Power (nth_power, square, cube) where

nth_power x n | n == 0 = 1
              | otherwise = x * nth_power x (n - 1)

square x = nth_power x 2
cube x = nth_power x 3
