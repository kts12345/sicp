sum2 term a next b = sum $ map term $ takeWhile (not.(<) b) $ iterate next a

cube x = x * x * x

simpsons_rule :: (Float -> Float) -> Int -> Int -> Int -> Float
simpsons_rule f a b n =
  let 
    h = fromIntegral (b - a) / fromIntegral n
  in
    (h / 3.0) * (sum2 (term f h a n) 0 succ n)
  where
    term f h a n k 
      | k == 0 || k == n  = f (fromIntegral a + fromIntegral k * h) 
      | mod k 2 == 0      = 2.0 * f (fromIntegral a + fromIntegral k * h) 
      | otherwise         = 4.0 * f (fromIntegral a + fromIntegral k * h) 

main = do
  print $ simpsons_rule cube 0 1 100
  print $ simpsons_rule cube 0 1 1000
