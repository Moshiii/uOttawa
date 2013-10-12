;;a tic-tac-toe program in Scheme

(define (atom? x) (not (or (pair? x) (null? x))))
 
;;substitute all old elements from a list into a new one
(define subst 
 (lambda (new old l) 
  (cond ((null? l) (quote ())) 
   ((atom? (car l)) 
    (cond ((eq? (car l) old) 
     (cons new (subst new old (cdr l)))) 
    (else (cons (car l) (subst new old (cdr l)))))) 
   (else (cons (subst new old (car l)) 
    (subst new old (cdr l)))))))
 
;;get the n-th element in a list
(define nth-in-list (lambda (ls n)
 (if (eq? n 1)
    ; this is the trivial case
    (car ls)
    ; otherwise find the result in the tail of ls
    (nth-in-list (cdr ls) (- n 1)))))
 
;;substitute all old element from a LIST OF 8 LIST into a new one
(define subst-all
 (lambda (new old ll)
  (let ((l1 (subst new old (nth-in-list ll 1))) (l2 (subst new old (nth-in-list ll 2))) 
   (l3 (subst new old (nth-in-list ll 3))) (l4 (subst new old (nth-in-list ll 4))) 
   (l5 (subst new old (nth-in-list ll 5))) (l6 (subst new old (nth-in-list ll 6)))
   (l7 (subst new old (nth-in-list ll 7))) (l8 (subst new old (nth-in-list ll 8))))
  (cons l1 (cons l2 (cons l3 (cons l4 (cons l5 (cons l6 (cons l7 (list l8)))))))))))
 
;;Print a tic-tac-toe board, take an argument which is a LIST OF 8 LIST
(define print-board
 (lambda (ll)
  (let ((l1 (car ll)) (l2 (cadr ll)) (l3 (caddr ll)))
   (if (number? (car l1)) (display " ") (display (car l1)))
   (display " | ")
   (if (number? (cadr l1)) (display " ")(display (cadr l1)))
   (display " | ")
   (if (number? (caddr l1)) (display " ")(display (caddr l1)))(newline)
   (display "__|___|__")(newline)
   (if (number? (car l2)) (display " ")(display (car l2)))
   (display " | ")
   (if (number? (cadr l2)) (display " ")(display (cadr l2)))
   (display " | ")
   (if (number? (caddr l2)) (display " ")(display (caddr l2)))(newline)
   (display "__|___|__")(newline)
   (if (number? (car l3)) (display " ")(display (car l3)))
   (display " | ")
   (if (number? (cadr l3)) (display " ")(display (cadr l3)))
   (display " | ")
   (if (number? (caddr l3)) (display " ")(display (caddr l3)))(newline) )))
 
;;check if a list of 3 elements consists of the same letter X or O, like (X X X) or (O O O) => #t
(define check-list
 (lambda (l)
  (if (or (and (equal? 'X (car l)) (equal? 'X (cadr l)) (equal? 'X (caddr l)))
   (and (equal? 'O (car l)) (equal? 'O (cadr l)) (equal? 'O (caddr l)))) 
  #t #f )))
 
;;check if there's a win, i.e there's at least a list in one of the 8 that is (X X X) or (O O O)
(define check-win
 (lambda (ll)
  (let ((l1 (nth-in-list ll 1))(l2 (nth-in-list ll 2))(l3 (nth-in-list ll 3))(l4 (nth-in-list ll 4))
   (l5 (nth-in-list ll 5))(l6 (nth-in-list ll 6))(l7 (nth-in-list ll 7))(l8 (nth-in-list ll 8)))
  (if (or (check-list l1) (check-list l2) (check-list l3) (check-list l4)
   (check-list l5) (check-list l6) (check-list l7) (check-list l8))
  #t #f ))))
 
;;check if a position a available (check if p is a member of one of the first three list of ll)
(define check-position
 (lambda (ll p)
  (if (or (member p (car ll)) (member p (cadr ll)) (member p (caddr ll)))  #t #f  )))
 
 
;;ask for a number from 1 to 9, takes an argument: the ll
(define ask-number
 (lambda(ll) 
  (let ((n (read)))
   (cond ((and (number? n)(< n 10)(> n 0)) (cond ((check-position ll n) n) 
    (else (display "Invalid move. Try again: ")(ask-number ll))))
   (else (display "Invalid input. Try again: ") (ask-number ll))))))
 
 
(define start  '((1 2 3) (4 5 6) (7 8 9) 
 (1 4 7) (2 5 8) (3 6 9) 
 (1 5 9) (3 5 7)
 ))
 
;;main program
(define tic-tac-toe
 (let ((current-turn 1)(current-player 'X)(notwon #t))
  (lambda (l)
   (cond ((> current-turn 9)(display "Draw game!"))
    (else (newline)
     (if (= 0 (modulo current-turn 2)) (set! current-player 'X) (set! current-player 'O));change to mod if use repl.it
     (display current-player)(display "'s turn: ")   
     (display "Enter 1 to 9: ")
     (let ((position (ask-number l)))
      (let ((newlist (subst-all current-player position l)))
       (print-board newlist)
       (cond ((check-win newlist)(newline)(display current-player)(display " has won!")(set! notwon #f)))
       (cond (notwon (set! current-turn (+ 1 current-turn))(tic-tac-toe newlist))
        (else (newline) (display "Game ended"))))))))))
 
(tic-tac-toe start)
