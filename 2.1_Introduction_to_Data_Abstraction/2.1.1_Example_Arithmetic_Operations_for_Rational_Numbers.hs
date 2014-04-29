

-- make_rat n d = (n, d)
numer (n, _) = n
denom (_, d) = d

-- (define (add-rat x y)
--   (make-rat (+ (* (numer x) (denom y))
--                (* (numer y) (denom x)))
--             (* (denom x) (denom y))))
add_rat x y =
  make_rat (numer x * denom y + numer y * denom x)
           (denom x * denom y)

-- (define (sub-rat x y)
--   (make-rat (- (* (numer x) (denom y))
--                (* (numer y) (denom x)))
--             (* (denom x) (denom y))))
sub_rat x y =
  make_rat (numer x * denom y - numer y * denom x)
           (denom x * denom y)

-- (define (mul-rat x y)
--   (make-rat (* (numer x) (numer y))
--             (* (denom x) (denom y))))
mul_rat x y = 
  make_rat (numer x * numer y)
           (denom x * denom y)
 
-- (define (div-rat x y)
--   (make-rat (* (numer x) (denom y))
--             (* (denom x) (numer y))))
div_rat x y =
  make_rat (numer x * denom y)
           (denom x * numer y) 

-- (define (equal-rat? x y)
--   (= (* (numer x) (denom y))
--      (* (numer y) (denom x))))
equal_rat x y = 
  (numer x * denom y) == (numer y * denom x)

-- (define (make-rat n d)
--   (let ((g (gcd n d)))
--       (cons (/ n g) (/ d g))))
make_rat n d = 
  let 
    g = gcd n d
  in
    (div n g, div d g)

main = do
  print $ make_rat 10 20
  print $ numer $ make_rat 10 20
  print $ denom $ make_rat 10 20
  print $ equal_rat (make_rat 10 20) (make_rat 1 2)
  print $ add_rat (make_rat 10 20) (make_rat 3 4)
  print $ sub_rat (make_rat 10 20) (make_rat 3 4)
  print $ mul_rat (make_rat 10 20) (make_rat 3 4)
  print $ div_rat (make_rat 10 20) (make_rat 3 4)
