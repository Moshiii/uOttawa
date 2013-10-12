(define generate_list
	(lambda (a b f)
		(cond
			((= a b)(if (f a) (list a) '()))
			((< a b)(if (f a) (append (list a)(generate_list (+ a 1) b f)) (generate_list (+ a 1) b f)))

		)
	)
)

(generate_list 1 35 (lambda(x) (= 0 (modulo x 2))))