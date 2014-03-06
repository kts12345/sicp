-- Exercise 1.12.  
-- The following pattern of numbers is called Pascal's triangle.
--       1 
--      1 1
--     1 2 1
--    1 3 3 1
--   1 4 6 4 1

-- The numbers at the edge of the triangle are all 1, 
-- and each number inside the triangle is the sum of the two numbers above it.
-- Write a procedure that computes elements of Pascal's triangle 
-- by means of a recursive process.
--
--
-- n줄, m번째 pascal number를 계산하는 함수.
-- n, m >= 1
pascal n m | m == 1 || n == m = 1
           | otherwise = pascal (n - 1) (m - 1) + pascal (n - 1) m

-- n번째 줄 pascal 숫자들을 배열로 반환하는 함수
pascal_rows n = 
  elems_left n 1 
  where elems_left n' m' | m' == n' = [1]
                         | otherwise = pascal n' m' : elems_left n' (m' + 1) 

main = do
  print $ pascal_rows 1 
  print $ pascal_rows 2 
  print $ pascal_rows 3 
  print $ pascal_rows 4 
  print $ pascal_rows 5 
  print $ pascal_rows 6 

