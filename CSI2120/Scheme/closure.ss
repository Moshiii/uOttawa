(define closure
      (let ((x 0))
    (lambda ()
      (set! x (+ x 1))
      x)))
