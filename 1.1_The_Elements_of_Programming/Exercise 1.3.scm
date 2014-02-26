; sicp.exercise.1.3
;-------------------------------------------------------
; * Problem : 
;   Define a procedure that takes three numbers as arguments and returns the sum of the
;   squares of the two larger numbers.

;-------------------------------------------------------
; * Answer

(define (square x) (* x x))

(define (sum-of-squares x y)
  (+ (square x) (square y)))

(define (sum-of-squares-without-min x y z)
    (cond ((and (< x y)(< x z)) (sum-of-squares y z))
          ((< y z)              (sum-of-squares z x))
          (else                 (sum-of-squares x y))))

;-------------------------------------------------------
; * Test

(sum-of-squares-without-min 1 2 3)
(sum-of-squares-without-min 4 2 3)
(sum-of-squares-without-min 4 5 3)   

;========================================================
; Output
;--------------------------------------------------------
;13
;25
;41