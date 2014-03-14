; (define (* a b)
;   (if (= b 0)
; 	0
; 	(+ a (* a (- b 1)))))

(define (double a)
  (+ a a))

(define (halve a)
  (/ a 2))

(define (multiply a b)
  (multiply-iter (a b 0))

(define (multiply-iter a b k)
  (cond ((= a 0) k)
		((= b 0) k)
		((= b 1) k)
		((even? b) (multiply-iter (double a) (halve b) k))
		(else (multiply-iter (double a) (halve b) (+ k a)))))


