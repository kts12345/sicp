
inc = succ
identity x = x

-- (accumulate combiner null-value term a next b)
accumulate combiner null_value term a next b =
  if a > b then null_value
 	else combiner (term a) (accumulate combiner null_value term (next a) next b)

accumulate_iter combiner null_value term a next b =
  iter combiner term a next b null_value
  where
    iter combiner term a next b result 
      | a > b = result
      | otherwise = iter combiner term (next a) next b (combiner result (term a))

product2 term a next b = accumulate (*) 1 term a next b
sum2 term a next b = accumulate (+) 0 term a next b

factorial n = product2 identity 1 inc n
sum_integers2 a b = sum2 identity a inc b

main = do
	print $ factorial 1
	print $ factorial 2
	print $ factorial 4
	print $ factorial 8
	print $ sum_integers2 1 5
	print $ sum_integers2 1 10
	print $ sum_integers2 1 100
	print $ sum_integers2 1 1000

