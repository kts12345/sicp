; sicp.exercise.1.6
;-------------------------------------------------------
; * Problem : 
;Alyssa P. Hacker doesn¡¯t see why if needs to be provided
;as a special form. ¡°Why can¡¯t I just define it as an ordinary
;procedure in terms of cond?¡± she asks. Alyssa¡¯s friend Eva Lu Ator
;claims this can indeed be done, and she defines a new version of
;if:

(define (new-if predicate then-clause else-clause)
           (cond (predicate then-clause)
                 (else else-clause)))

;Eva demonstrates the program for Alyssa:
(new-if (= 2 3) 0 5) ; output 5

(new-if (= 1 1) 0 5) ; output 0

;Delighted, Alyssa uses new-if to rewrite the square-root program:
(define (sqrt-iter guess x)
           (new-if (good-enough? guess x)
                   guess
                   (sqrt-iter (improve guess x) x)))

;What happens when Alyssa attempts to use this to compute square
;roots? Explain.


(define (good-enough? guess x)
           (< (abs (- (square guess) x)) 0.001))

(define (improve guess x)
           (average guess (/ x guess)))

(define (average x y)
          (/ (+ x y) 2))

(define (square x)
          (* x x))

(sqrt-iter 1 5)

;------------------------------------------------------------
; * Output
; 5
; 0
; 'infinite-loop'
;

;------------------------------------------------------------
; * Answer
;
; (sqrt-iter g_n x)
; (new-if (good-enough? g_n x)  g_n (sqrt-iter (improve g_n x) x))
; (new-if #true_or_false        g_n (sqrt-iter (improve g_n x) x))
; (new-if #true_or_false        g_n (sqrt-iter g_n+1           x))
;
; So We have below infinite sequence
;
; (sqrt-iter 1 5)                                                                                   
; (new-if #f 1 (sqrt-iter 3 5))
; (new-if #f 1 (new-if #f 3 (sqrt-iter 4.667 5)))
; ...     ...  ...          ...
; (new-if #f 1 (new-if #f 3 ... (new-if #t g_n ((sqrt-iter g_n+1 5))) ...))
; (new-if #f 1 (new-if #f 3 ... (new-if #t g_n (new-if #t  g_n+1 (sqrt-iter g_n+2 5)))...))
; ...
; (new-if #f 1 (new-if #f 3 ... (new-if #t g_n (new-if #t  g_n+1 (new-if #t g_n+2... (sqrt-iter g_infinite 5)...)))...))
; ...
; 'infinite-loop'


; Compare oritinal-if Pattern
;
; (sqrt-iter guess_1 x)
; (if #f guess_1 sqrt-iter(quess_2, x))
; (if #f guess_1 (if #f guess_2 sqrt-iter(quess_3, x)))
; ...
; (if #f guess_1 (if #f guess_2 (if #f guess_3... (if #t guess_n sqrt-iter(guess_n, x))...)))
; (if #f guess_1 (if #f guess_2 (if #f guess_3,...       guess_n                       ...)))
; (if #f guess_1 (if #f guess_2                          guess_n                           ))
; (if #f guess_1                                         guess_n                            )
;                                                        guess_n                             
;

; bottom line is 'laziness for special-form' in original-if pattern

