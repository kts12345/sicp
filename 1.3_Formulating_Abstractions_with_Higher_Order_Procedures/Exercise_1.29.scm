(define (sum term a next b)
  (if (> a b)
       0 (+ (term a)
          (sum term (next a) next b))))


(define (cube x) (* x x x))

(define (integral f a b dx)
  (define (add-dx x) (+ x dx))
  (* (sum f (+ a (/ dx 2.0)) add-dx b)
     dx))


(define (simpsons_rule f a b n)
  (define (h) (/ (- b a) n))
  (define (add-dx x) (+ x 1))
  (define (y_k k) (f (+ a (* k (h)))))
  (define (term k)
    (cond ((= k 0) (y_k k))
          ((= k n) (y_k k))
          (= (even? k) (* 4 (y_k k)))
          (else (* 2 (y_k k)))))
    (* (sum term 0 add-dx n)
       (/ (h) 3)))

(simpsons_rule cube 0 1 100)
(simpsons_rule cube 0 1 1000)


----------------------------------
9901/30000
999001/3000000

