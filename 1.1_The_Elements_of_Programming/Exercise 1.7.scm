; sicp.exercise.1.7
;-------------------------------------------------------
; * Problem : 
;The good-enough? test used in computing square
;roots will not be very effective for finding the square roots of very
;small numbers. Also, in real computers, arithmetic operations are
;almost always performed with limited precision. This makes our
;test inadequate for very large numbers. Explain these statements,
;with examples showing how the test fails for small and large numbers.
;An alternative strategy for implementing good-enough? is to
;watch how guess changes from one iteration to the next and to
;stop when the change is a very small fraction of the guess. Design
;a square-root procedure that uses this kind of end test. Does this
;work better for small and large numbers?


(define (sqrt-iter guess x)
           (if (good-enough? guess x)
               guess
               (sqrt-iter (improve guess x) x)))

(define (good-enough? guess x)
           (< (abs (- (square guess) x)) 0.001))

(define (improve guess x)
           (average guess (/ x guess)))

(define (average x y)
          (/ (+ x y) 2))

(define (square x)
          (* x x))

square (sqrt-iter 1 23)
square (sqrt-iter 1 0.0000000001))
square (sqrt-iter 1  10000000000))

;------------------------------------------------------------
; * Output
; 23.0000000097473428952288102... ;     OK
; 0.0312500010656249927537500...  ; Not Ok
; infinite-loop                   ; Not Ok
;


