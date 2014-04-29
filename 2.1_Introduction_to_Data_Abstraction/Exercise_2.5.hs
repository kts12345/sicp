cons x y = truncate (2**x * 3**y)

get_exp_of b z = 
  if 0 == mod z b then 1 + get_exp_of b (div z 2) 
  else 0

car z = get_exp_of 2 z
cdr z = get_exp_of 3 z 

main = do
  print $ cons 1 2
  print $ car $ cons 1 2
  print $ cdr $ cons 1 2
