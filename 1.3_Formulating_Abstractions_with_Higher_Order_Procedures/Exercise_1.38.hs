
cont_frac n d k =
  f n d k 1
  where 
    f n d k i | i == k = n i / d i
              | otherwise = n i / (d i + f n d k (i + 1))

e k = 
  2 + cont_frac n d k
  where
    n = (\i -> 1.0)
    d = (\i -> if 0 == mod (i - 2) 3 then 2.0 * fromIntegral (div (i + 1) 3) 
               else 1.0)

main = do
  print $ e 1
  print $ e 10
  print $ e 100
  print $ e 1000
