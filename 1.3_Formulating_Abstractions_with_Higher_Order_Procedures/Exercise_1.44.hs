import Repeated

dx = 0.00001

smooth f = (\x -> (f (x - dx) + f x + f (x + dx)) / 3)
n_fold_smoothed n = repeated smooth n

main = do 
  print $ smooth (\x -> x * x) 3
  print $ n_fold_smoothed 3 (\x -> x * x) 3
