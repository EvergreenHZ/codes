;; NOTE: There's something wrong.
(define result '())

; Point: (row col)

(define tree-copy
  (lambda (ls)
    (if (not (pair? ls))
      '()
      (cons (tree-copy (car ls))
            (tree-copy (cdr ls))))))

(define abs
  (lambda (a)
    (if (> a 0)
      a
      (- 0 a))))

(define is-legal
  (lambda (pre-k p)
    (cond ((null? pre-k) #t)
          ((= (car (car pre-k)) (car p)) #f)  ; same row
          ((= (abs (- (car (car pre-k)) (car p)))
              (abs (- (cadr (car pre-k)) (cadr p)))) #f)
          (else (is-legal (cdr pre-k) p)))))

(define print
  (lambda (l)
    (cond ((null? l) newline)
          (else
            (display (car result))
            (print (cdr result))))))

(define nQueens
  (lambda (col-n result)
    (let ((N 6))
      (cond ((= col-n (+ N 1)) (print result))
            (else
              (let ((tmp (tree-copy result)))
                ; iterate from 1 to N
                (letrec ((iter             ;; iterate all rows
                           (lambda (k)
                             (cond ((= k (+ N 1)) #t)  ;; break here, which I don't know how
                                   (else
                                     (if (is-legal tmp (cons k col-n))
                                       (begin 
                                         (cons (cons k col-n) tmp)
                                         (nQueens (+ col-n 1) tmp)
                                         (iter (+ k 1)))))))))
                  (iter 1))))))))  ;; starting from 1

(define test
  (lambda ()
    (let ((col-n 1)
          (result '()))
      (nQueens col-n result))))
