make_point x y = (x, y)
x_point (x, _) = x
y_point (_, y) = y

-- 기울어진 직사각형은 고려X
-- 둘레/넓이 계산만 필요하므로 가로/세로 길이만 selector로...
make_rectangle p1 p2 = (p1, p2)

side (p1, p2) selector = 
  let
    v1 = selector p1 
    v2 = selector p2
  in 
    abs (v1 - v2)

width r = side r x_point
height r = side r y_point

perimeter r = 2 * (width r + height r) 
area r = width r * height r

main = do
  print $ make_rectangle (make_point 10 20) (make_point 20 40)
  print $ width $ make_rectangle (make_point 10 20) (make_point 20 40)
  print $ height $ make_rectangle (make_point 10 20) (make_point 20 40)
  print $ perimeter $ make_rectangle (make_point 10 20) (make_point 20 40)
  print $ area $ make_rectangle (make_point 10 20) (make_point 20 40)
