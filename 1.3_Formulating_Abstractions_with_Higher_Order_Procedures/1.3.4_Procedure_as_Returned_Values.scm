#lang racket


(define (average x y)
  (/ (+ x y) 2))


(define tolerance 0.00001)

(define (fixed-point f first-guess)
  (define (close-enought? v1 v2)
	(< (abs (- v1 v2)) tolerance))
  (define (try guess)
	(let ((next (f guess)))
	  (display "guess: ")
	  (display guess)
	  (newline)
	  (if (close-enought? guess next)
		next
		(try next))))
  (try first-guess))

(define (square x) (* x x))

(define (average-damp f)
  (lambda (x) (average x (f x))))


((average-damp square) 10)
; 55

(define (sqrt2 x)
  (fixed-point (average-damp (lambda (y) (/ x y)))
			   1.0))

(sqrt2 9)
; 3.0

(define (cube-root x)
  (fixed-point (average-damp (lambda (y) (/ x (square y))))
			   1.0))

(cube-root 27)
; 2.9999972321057697


(define (deriv g)
  (lambda (x)
	(/ (- (g (+ x dx)) (g x))
	   dx)))

(define dx 0.00001)

(define (cube x) (* x x x))

((deriv cube) 5)
; 75.00014999664018

(define (newton-transform g)
  (lambda (x)
	(- x (/ (g x) ((deriv g) x)))))

(define (newtons-method g guess)
  (fixed-point (newton-transform g) guess))

(define (sqrt_newton x)
  (newtons-method (lambda (y) (- (square y) x))
				  1.0))


(sqrt_newton 9)
; 3.0


(define (fixed-point-of-transform g transform guess)
  (fixed-point (transform g) guess))

(define (sqrt2_2 x)
  (fixed-point-of-transform (lambda (y) (/ x y))
							average-damp
							1.0))

(define (sqrt2_3 x)
  (fixed-point-of-transform (lambda (y) (- (square y) x))
							newton-transform
							1.0))

(sqrt2_2 9)
; 3.0

(sqrt2_3 9)
; 3.0


