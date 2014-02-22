-- 1.1.3 Evaluating Combinations
 
main =
 -- (* (+ 2 (* 4 6))
 --    (+ 3 5 7))
 print $ (*) ((+) 2 ((*) 4 6)) 
             (foldl (+) 0 [3,5,7]) 