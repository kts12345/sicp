import Newton
import Power

cubic a b c x = nth_power x 4 + a * cube x + b * square x + c

main = do
  print $ newtons_method (cubic (-1) 1 (-1)) 1
