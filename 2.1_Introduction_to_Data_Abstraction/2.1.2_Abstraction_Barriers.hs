-- (define (make-rat n d)
--   (cons n d))
make_rat n d = (n, d)

-- (define (numer x)
--   (let ((g (gcd (car x) (cdr x))))
--     (/ (car x) g)))
numer (n, d) = 
  let g = gcd n d
  in  div n g

-- (define (denom x)
--   (let ((g (gcd (car x) (cdr x))))
--     (/ (cdr x) g)))
denom (n, d) = 
  let g = gcd n d
  in  div d g

main = do
  print $ make_rat 10 20
  print $ numer $ make_rat 10 20
  print $ denom $ make_rat 10 20
