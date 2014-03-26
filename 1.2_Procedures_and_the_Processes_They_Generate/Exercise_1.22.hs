import System.CPUTime
import Text.Printf
import Prime

fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = fib (n-1) + fib (n-2)

next n | n == 2 = n + 1
       | n `mod` 2 == 0 = n + 1
       | n `mod` 2 == 1 = n + 2

search_for_primes start n 
    | n == 0 = []
    | prime start = start : search_for_primes (next start) (n - 1)
    | otherwise = search_for_primes (next start) n

time :: IO t -> IO t
time a = do
  start <- getCPUTime
  v <- a
  end <- getCPUTime
  let diff = (fromIntegral (end-start)) / (10^12)
  printf "Computation time: %0.6f sec\n" (diff :: Double)
  return v 

timed_prime_test start n = do
  time $ print $ search_for_primes start n

main = do
  putStrLn "Test 1000 3"
  timed_prime_test 1000 3
  putStrLn "Test 10000 3"
  timed_prime_test 10000 3
  putStrLn "Test 100000 3"
  timed_prime_test 100000 3
  putStrLn "Test 1000000 3"
  timed_prime_test 1000000 3
  putStrLn "Test 10000000 3"
  timed_prime_test 10000000 3
  putStrLn "Done.."
