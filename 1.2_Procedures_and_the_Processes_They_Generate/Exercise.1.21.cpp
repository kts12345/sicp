//  sicp.exercise.1.21
/* -------------------------------------------------------
 * Problem
  Use the smallest-divisor procedure to ?nd the
  smallest divisor of each of the following numbers: 199, 1999, 19999

// -------------------------------------------------------
// Answer

/*
(define (smallest-divisor n) (find-divisor n 2))

(define (find-divisor n test-divisor)
      (cond ((> (square test-divisor) n) n)
            ((divides? test-divisor n) test-divisor)
            (else (find-divisor n (+ test-divisor 1)))))

(define (divides? a b) (= (remainder b a) 0))

(define (square x) (* x x))

(smallest-divisor 199) 
(smallest-divisor 1999) 
(smallest-divisor 19999)

*/

/*
 ========================================================
  * Output
 --------------------------------------------------------
199
1999
7
*/
