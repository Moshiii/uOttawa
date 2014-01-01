;; CSI3120 Assignment 1 Question 3
;; Author: Trung Do
;; A program that calculates the percentage of vowels, consonants and other characters in a given paragraph

;;Input the string
(display "Please enter the paragraph (with double quote): ")
(define paragraph (read))

;;Define the lists
(define vowelList (list #\a #\i #\u #\e #\o #\A #\I #\U #\E #\O))
(define consonantList (list #\b #\c #\d #\f #\g #\h #\j #\k #\l #\m #\n #\p #\q #\r #\s #\t #\v #\w #\x #\y #\z 
                            #\B #\C #\D #\F #\G #\H #\J #\K #\L #\M #\N #\P #\Q #\R #\S #\T #\V #\W #\X #\Y #\Z))
(define paragraphLength (string-length paragraph))

;;count the number of vowel in a string
(define count-vowel 
  (let ((count 0))
    (lambda (paragraph index length)    
      (if (= index length) count
                          (if (member (string-ref paragraph index) vowelList) (begin (set! count (+ 1 count))(count-vowel paragraph (+ 1 index) length))
                              (count-vowel paragraph (+ 1 index) length))))))

;; count the number of consonant in a string
(define count-consonant 
  (let ((count 0))
    (lambda (paragraph index length)    
      (if (= index length) count
                          (if (member (string-ref paragraph index) consonantList) (begin (set! count (+ 1 count))(count-consonant paragraph (+ 1 index) length))
                              (count-consonant paragraph (+ 1 index) length))))))

(display "Number of vowel: ")
(define numVowel (count-vowel paragraph 0 paragraphLength)) (display numVowel) (newline)

(display "Number of consonant: ")
(define numConsonant (count-consonant paragraph 0 paragraphLength)) (display numConsonant) (newline)

(display "Number of other character: ")
(define numOther (- paragraphLength (+ numVowel numConsonant))) (display numOther) (newline)

(display "Percentage of vowel: ")
(display (* (/ numVowel paragraphLength) 100))(newline)

(display "Percentage of consonant: ")
(display (* (/ numConsonant paragraphLength) 100))(newline)

(display "Percentage of other: ")
(display (* (/ numOther paragraphLength) 100))(newline)