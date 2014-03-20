import System.CPUTime
import Text.Printf
import System.Random
import FastPrime

fp_next n | n == 2 = n + 1
          | n `mod` 2 == 0 = n + 1
          | n `mod` 2 == 1 = n + 2

search_for_primes start n xs
    | n == 0 = []
    | fast_prime start 12 xs = start : search_for_primes (fp_next start) (n - 1) (drop 12 xs)
    | otherwise = search_for_primes (fp_next start) n (drop 12 xs)

time :: IO t -> IO t
time a = do
  start <- getCPUTime
  v <- a
  end <- getCPUTime
  let diff = (fromIntegral (end-start)) / (10^12)
  printf "Computation time: %0.6f sec\n" (diff :: Double)
  return v 

timed_prime_test start n xs = do
  time $ print $ search_for_primes start n xs

main = do
  g <- getStdGen
  putStrLn "Test 1000 3"
  timed_prime_test 1000 3 (randomRs (1, (3 - 1)) g :: [Int])
  putStrLn "Test 10000 3"
  timed_prime_test 10000 3 (randomRs (1, (3 - 1)) g :: [Int])
  putStrLn "Test 100000 3"
  timed_prime_test 100000 3 (randomRs (1, (3 - 1)) g :: [Int])
  putStrLn "Test 1000000 3"
  timed_prime_test 1000000 3 (randomRs (1, (3 - 1)) g :: [Int])
  putStrLn "Test 10000000 3"
  timed_prime_test 10000000 3 (randomRs (1, (3 - 1)) g :: [Int])
  putStrLn "Test 100000000 3"
  timed_prime_test 100000000 3 (randomRs (1, (3 - 1)) g :: [Int])
  putStrLn "Done.."

