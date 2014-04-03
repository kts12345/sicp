import FixedPoint
golden_ratio = fixed_point (\ x -> 1 + 1 / x) 1.0

main = do
  print $ golden_ratio


