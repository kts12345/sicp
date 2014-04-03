
cont_frac n d k =
  f n d k 1
  where 
    f n d k i | i == k = n i / d i
              | otherwise = n i / (d i + f n d k (i + 1))

cont_frac_iter n d k = 
  f n d k k 0
  where 
    f n d k i v | i == 1 = n i / (d i + v)
                | otherwise = f n d k (i - 1) (n i / (d i + v))

golden_ratio k = 1 / cont_frac (\ i -> 1.0) (\ i -> 1.0) k
golden_ratio_iter k = 1 / cont_frac (\ i -> 1.0) (\ i -> 1.0) k

main = do
  print $ golden_ratio 1
  print $ golden_ratio 10
  print $ golden_ratio 100
  print $ golden_ratio 1000
  print $ golden_ratio_iter 1
  print $ golden_ratio_iter 10
  print $ golden_ratio_iter 100
  print $ golden_ratio_iter 1000
