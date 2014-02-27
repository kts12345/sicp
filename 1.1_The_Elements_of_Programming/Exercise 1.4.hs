-- sicp.exercise.1.4
---------------------------------------------------------
-- * Problem : 
--   Observe that our model of evaluation allows for combinations whose operators are
--   compound expressions. Use this observation to describe the behavior of the following procedure:

--  (define (a-plus-abs-b a b)
--      ((if (> b 0) + -) a b))
a_plus_abs_b a b =
        (if b > 0 then (+) else (-)) a b
    
---------------------------------------------------------
-- * Test
-- (a-plus-abs-b 10 -4)
-- (a-plus-abs-b 10 +4)
main = do
    print $ a_plus_abs_b 10 (-4)
    print $ a_plus_abs_b 10   4
    
-- ========================================================
-- * Output
----------------------------------------------------------
--14
--14

---------------------------------------------------------
-- * Answer

-- a_plus_abs_b                    10 (-4)
-- (if (-4) > 0 then (+) else (-)) 10 (-4)
-- (if False    then (+) else (-)) 10 (-4)
--                            (-)  10 (-4)
--                            14

-- a_plus_abs_b                    10 4
-- (if 4 > 0    then (+) else (-)) 10 4
-- (if True     then (+) else (-)) 10 4
--                   (+)           10 4
--                   14
