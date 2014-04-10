﻿#!r6rs
(import (rnrs base (6)))

(define (search f neg-point pos-point)
  (let ((midpoint (average neg-point pos-point)))
	(if (close-enought? neg-point pos-point)
	  midpoint
	  (let ((test-value (f midpoint)))
		(cond ((positive? test-value)
			   (search f neg-point midpoint))
			  ((negative? test-value)
			   (search f midpoint pos-point))
			  (else midpoint))))))

(define (average x y)
  (/ (+ x y) 2))

(define (close-enought? x y)
  (< (abs (- x y)) 0.001))

(define (half-interval-method f a b)
  (let ((a-value (f a))
		(b-value (f b)))
	(cond ((and (negative? a-value) (positive? b-value))
		   (search f a b))
	      ((and (negative? b-value) (positive? a-value))
		   (search f b a))
		  (else
			(error "Value are not of opposit sign" a b)))))

(half-interval-method sin 2.0 4.0)
; 3.14111328125

(half-interval-method (lambda (x) (- (* x x x) (* 2 x) 3))
					  1.0
					  2.0)
; 1.89306640625

(define tolerance 0.00001)

(define (fixed-point f first-guess)
  (define (close-enought? v1 v2)
	(< (abs (- v1 v2)) tolerance))
  (define (try guess)
	(let ((next (f guess)))
	  (if (close-enought? guess next)
		next
		(try next))))
  (try first-guess))

;(fixed-point cos 1.0)
;
;(fixed-point (lambda (y) (+ (sin y) (cos y)))
;			 1.0)
;
;(define (sqrt x)
;  (fixed-point (lambda (y) (/ x y))
;			   1.0))

(define (sqrt2 x)
  (fixed-point (lambda (y) (average y (/ x y)))
			   1.0))

(sqrt2 2.0)
; 1.4142135623746899

(define (golden_ratio)
  (fixed-point (lambda (y) (+ 1 (/ 1 x)))
			   1.0))

(golden_ratio)

; 1.6180327868852458 

