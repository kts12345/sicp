; (define (* a b)
;   (if (= b 0)
; 	0
; 	(+ a (* a (- b 1)))))

(define (addition a b)
  (+ a b))

(define (double a)
  (+ a a))

(define (halve a)
  (/ a 2))

(define (multiply a b)
  (cond ((= a 0) 0)
		((= b 0) 0)
		((even? b) (+ (double a) (multiply (double a) (- (halve b) 1))))
		(else (+ a (multiply (double a) (halve (- b 1)))))))


