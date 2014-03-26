-- import Prelude hiding (sum)

-- (define (cube x) (* x x x))
cube x = x * x * x

-- (define (sum-integers a b)
--   (if (> a b)
--       0
--       (+ a (sum-integers (+ a 1) b))))
sum_integers a b = if a > b then 0
									 else a + sum_integers (a + 1) b

-- (define (sum-cubes a b)
--   (if (> a b)
--       0
--       (+ (cube a) (sum-cubes (+ a 1) b))))
sum_cubes a b = if a > b then 0
							  else cube a + sum_cubes (a + 1) b


-- (define (pi-sum a b)
--   (if (> a b)
--       0
--       (+ (/ 1.0 (* a (+ a 2))) (pi-sum (+ a 4) b))))
pi_sum a b = if a > b then 0
						 else (1.0 / (a * (a + 2))) + (pi_sum (a + 4) b)

-- (define (<name> a b)
--   (if (> a b)
--       0
--       (+ (<term> a)
--          (<name> (<next> a) b))))

-- (define (sum term a next b)
--   (if (> a b)
--       0
--       (+ (term a)
--          (sum term (next a) next b))))
-- sum term a next b =
-- 		if a > b then 0 
-- 		else term a + sum term (next a) next b
sum2 term a next b = sum $ map term $ takeWhile (not.(<) b) $ iterate next a

-- (define (inc n) (+ n 1))
-- (define (sum-cubes a b)
--   (sum cube a inc b))
-- inc n = n + 1
inc = (+) 1
sum_cubes2 a b = sum2 cube a inc b

-- (define (identity x) x)
identity x = x

-- (define (sum-integers a b)
--   (sum identity a inc b))
sum_integers2 a b = sum2 identity a inc b

-- (define (pi-sum a b)
--   (define (pi-term x)
--     (/ 1.0 (* x (+ x 2))))
--   (define (pi-next x)
--     (+ x 4))
--   (sum pi-term a pi-next b))
pi_sum2 a b = sum2 pi_term a pi_next b
	where
		pi_term x = 1.0 / (x * (x + 2))
		pi_next x = x + 4

-- (define (integral f a b dx)
--   (define (add-dx x) (+ x dx))
-- 	 (* (sum f (+ a (/ dx 2.0)) add-dx b)
-- 		  dx))
integral f a b dx = dx * sum2 f (a + (dx / 2.0)) add_dx b
	where
		add_dx = (+) dx

-- (sum-cubes 1 10)
-- 3025

-- (sum-integers 1 10)
-- 55

-- (* 8 (pi-sum 1 1000))
-- 3.139592655589783

-- (integral cube 0 1 0.01)
-- .24998750000000042

-- (integral cube 0 1 0.001)
-- .249999875000001


main = do
	print $ sum_cubes 1 10
	print $ sum_cubes2 1 10
	print $ sum_integers 1 10
	print $ sum_integers2 1 10
	print $ 8 * pi_sum 1 1000
	print $ 8 * pi_sum2 1 1000
	print $ integral cube 0 1 0.01
	print $ integral cube 0 1 0.001
