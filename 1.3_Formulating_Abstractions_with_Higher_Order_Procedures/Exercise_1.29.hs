
cube x = x * x * x

simpsons_rule f a b n =
	let 
		h = (b - a) / n
	in
		(h / 3.0) * (sum $ g f h 0 n)
	where
		g f h k n | k == 0 				= f (a + k * h) : g f h (k + 1) n
							| k == n 				= f (a + k * h) : []
					  	| mod k 2 == 0 	= 2 * f (a + k * h) : g f h (k + 1) n
							| otherwise 		= 4 * f (a + k * h) : g f h (k + 1) n


main = do
	print $ simpsons_rule cube 0 1 100
	print $ simpsons_rule cube 0 1 1000
