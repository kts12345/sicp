-- 1.1.3 Evaluating Combinations
import Prelude hiding((++))

-- define multi input (+)
(++) = foldr (+) 0

main =

 --      (*   (+ 2 (* 4 6))
 --           (+ 3 5 7))
 print $ (*) ((+) 2 ((*) 4 6))
             ((++) [3,5,7])