-- Exercise 2.1. Define a better version of make-rat that handles both positive and negative arguments. 
-- Make-rat should normalize the sign so that if the rational number is positive, 
-- both the numerator and denominator are positive, and if the rational number is negative, only the numerator is negative.

make_rat n d = 
  let 
    g = gcd n d
    s = if n < 0 && d < 0 then (-1)
        else 1
  in
    (s * div n g, s * div d g)

main = do
  print $ make_rat 10 20
  print $ make_rat (-10) 20
  print $ make_rat (-10) (-20)
