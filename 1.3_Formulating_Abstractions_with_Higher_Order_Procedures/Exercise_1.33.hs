identity x = x

square x = x * x

smallest_divisor n = find_divisor n 2

find_divisor n test_divisor | (square test_divisor) > n = n
                            | divides test_divisor n = test_divisor
                            | otherwise = find_divisor n (test_divisor + 1)

divides a b = (mod b a) == 0

prime n = (smallest_divisor n) == n && n /= 1

filtered_accumulate combiner filter null_value term a next b 
  | a > b         = null_value
  | not $ filter a  = filtered_accumulate combiner filter null_value term (next a) next b
  | otherwise     = combiner (term a) (filtered_accumulate combiner filter null_value term (next a) next b)

sum_of_square_of_prime_number a b = filtered_accumulate (+) prime 0 square a succ b
sum_of_relative_prime n = filtered_accumulate (+) (filter n) 0 identity 1 succ n
  where 
    filter a b = 1 == gcd a b

main = do
  print $ sum_of_square_of_prime_number 1 5
  print $ sum_of_relative_prime 7
