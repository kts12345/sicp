
test_func :: Int -> Int -> Float
test_func a b =
  let 
    h = fromIntegral (a - b) / fromIntegral b
  in
    h * g a
  where 
    g n | mod n 2 == 0 = 1.0
        | otherwise = 2.0

main = do
  print $ test_func 1 2


