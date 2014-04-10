square x = x * x

compose f g = f.g

-- ((compose square inc) 6)
-- 49

main = do
  print $ compose square succ 6
