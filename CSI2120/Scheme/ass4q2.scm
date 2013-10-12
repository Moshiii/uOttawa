(define quadratic-formula
	(lambda (a b c)
		(let(
				(minusb (- 0 b))
				(delta (- (* b b) (* 4 (* a c))))
				(divisor (* 2 a))
			)
			(cond
				((> delta 0) (let(	(root1 (/ (+ minusb (sqrt delta)) divisor))
									(root2 (/ (- minusb (sqrt delta)) divisor)))	(list root1 root2)))
				((= delta 0) (let(  (root (/ (+ minusb (sqrt delta)) divisor)))(list root)))
				((< delta 0) (list 'none))
			)
		)
	)
)

(define solution
	(lambda (l)
		(let (
				(a (car l)) 
				(b (cadr l)) 
				(c (caddr l))
			 )
			(quadratic-formula a b c)
		)
	)
)