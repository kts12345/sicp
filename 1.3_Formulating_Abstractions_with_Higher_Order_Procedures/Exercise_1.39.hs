
cont_frac n d k =
  f n d k 1
  where 
    f n d k i | i == k = n i / d i
              | otherwise = n i / (d i + f n d k (i + 1))

tan2 x k = cont_frac n d k
  where
    n = (\i -> if i == 1 then x
               else (-1) * x * x)
    d = (\i -> i * 2 - 1)

angle_to_radian x = x * 0.0175

main = do
  print $ tan2 (angle_to_radian 45) 1
  print $ tan2 (angle_to_radian 45) 10
  print $ tan2 (angle_to_radian 45) 100
  print $ tan2 (angle_to_radian 45) 1000
