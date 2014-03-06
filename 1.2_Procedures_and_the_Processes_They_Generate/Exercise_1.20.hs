-- Exercise 1.20.  
-- The process that a procedure generates is of course dependent on the rules used by the interpreter. 
-- As an example, consider the iterative gcd procedure given above. 
-- Suppose we were to interpret this procedure using normal-order evaluation, as discussed in section 1.1.5. 
-- (The normal-order-evaluation rule for if is described in exercise 1.5.) 
-- Using the substitution method (for normal order), 
-- illustrate the process generated in evaluating (gcd 206 40) and indicate the remainder operations that are actually performed. 
-- How many remainder operations are actually performed in the normal-order evaluation of (gcd 206 40)? In the applicative-order evaluation?

-- normal-order
-- gcd 206 40
-- gcd 40 (206 mod 40)                    
--  => if 0 == b 계산을 위해 1회
-- gcd (206 mod 40) (40 mod (206 mod 40)) 
--  => if 0 == b 계산을 위해 2회
-- gcd (40 mod (206 mod 40)) ((206 mod 40) mod (40 mod (206 mod 40)))
--  => if 0 == b 계산을 위해 4회
-- gcd ((206 mod 40) mod (40 mod (206 mod 40)))
--     ((40 mod (206 mod 40)) mod ((206 mod 40) mod (40 mod (206 mod 40))))
--  => if 0 == b 계산을 위해 7회
--  => then a 계산을 위해 4회
--
-- => 총 1 + 2 + 4 + 7 + 4 = 18 회
--
-- applicative-order
-- gcd 206 40
-- gcd 40 (206 mod 40) => gcd 40 6
-- gcd 6 (40 mod 6) => gcd 6 4
-- gcd 4 (6 mod 4) => gcd 4 2
-- gcd 2 (4 mod 2) => gcd 2 0
--
-- => 총 4회
--     