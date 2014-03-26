
inc :: Integral a => a -> a
inc = (+) 1
identity x = x

-- (define (product term a next b)
--   (if (> a b)
--       0
--       (+ (term a)
--          (product term (next a) next b))))
-- product term a next b =
-- 		if a > b then 0 
-- 		else term a + product term (next a) next b
-- aprox_pi :: (Integral a, Num b) => (a -> b) -> a -> (a -> a) -> a -> b
product2 term a next b = 
  product $ map term $ takeWhile (not.(<) b) $ iterate next a

product_iter term a next b =
  iter term a next b 1
  where
    iter term a next b mul | a > b = mul
                           | otherwise = iter term (next a) next b (mul * term a)

factorial n = product2 identity 1 inc n

factorial_iter n = product_iter identity 1 inc n

approx_pi :: Int -> Float
approx_pi n = 
  4 * product2 term 1 inc n
  where 
    term n | even n = fromIntegral (n + 2) / fromIntegral (n + 1)
           | otherwise = fromIntegral (n + 1) / fromIntegral (n + 2)

main = do
	print $ factorial 1
	print $ factorial 2
	print $ factorial 4
	print $ factorial 8
	print $ factorial_iter 1
	print $ factorial_iter 2
	print $ factorial_iter 4
	print $ factorial_iter 8
	print $ approx_pi 100
	print $ approx_pi 1000
