(define last-elem
	(lambda (l)
	(car (reverse l))))

(define all-but-last
	(lambda (l) 
		(reverse (cdr (reverse l)))))


(define (last-to-first x) (append (list (last-elem x)) (all-but-last x)))


(define decale
	(lambda (n ls)
		(if(null? ls)	
			'()
			(if (= n 0)
					ls
					(let ((newls (last-to-first ls)) (n_new (- n 1)))
						(decale n_new newls))))))

(decale 3 '(1 -5 2 4 3 7 9))

