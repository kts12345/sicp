
make_point x y = (x, y)
x_point (x, _) = x
y_point (_, y) = y

make_segment s e = (s, e)
start_segment (s, _) = s
end_segment (_, e) = e

midpoint_segment seg = 
  let
--   (x, y)    = start_segment seg 
--   (x', y')  = end_segment seg 
    s = start_segment seg 
    e = end_segment seg 
    x = x_point s
    y = y_point s
    x' = x_point e
    y' = y_point e
  in
    make_point (x + x' / 2)
               (y + y' / 2)

main = do
  print $ make_point 10 20
  print $ make_segment (make_point 10 20) (make_point 20 30)
  print $ start_segment $ make_segment (make_point 10 20) (make_point 20 30)
  print $ end_segment $ make_segment (make_point 10 20) (make_point 20 30)
  print $ midpoint_segment $ make_segment (make_point 10 20) (make_point 20 30)
