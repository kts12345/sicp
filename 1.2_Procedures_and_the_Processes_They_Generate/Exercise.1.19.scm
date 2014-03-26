(define (fin n)
  (fib-iter 1 0 0 1 n))

(define (fib-iter a b p q count)
  (cond ((= count 0) b)
		((even? count)
		 (fib-iter a
				   b
				   p2 ; ???
				   q2 ; ???
				   (/ count 2)))
		(else (fib-iter (+ (* b q) (* a q) (* a p))
						(+ (* b q) (* a q))
						p
						q
						(- count 1)))))




