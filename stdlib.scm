;(define number? integer?)

(define done 'done)
(define (caar x) (car (car x)))
(define (cadr x) (car (cdr x)))
(define (cdar x) (cdr (car x)))
(define (cddr x) (cdr (cdr x)))
(define zero? (lambda (x) (eq? x 0)))

;(define (vector? x) #f)
(define (caaar x) (car (car (car x))))
(define (caadr x) (car (car (cdr x))))
(define (cadar x) (car (cdr (car x))))
(define (caddr x) (car (cdr (cdr x))))
(define (cdaar x) (cdr (car (car x))))
(define (cdadr x) (cdr (car (cdr x))))
(define (cddar x) (cdr (cdr (car x))))
(define (cdddr x) (cdr (cdr (cdr x))))
(define (caaaar x) (car (car (car (car x)))))
(define (caaadr x) (car (car (car (cdr x)))))
(define (caadar x) (car (car (cdr (car x)))))
(define (caaddr x) (car (car (cdr (cdr x)))))
(define (cadaar x) (car (cdr (car (car x)))))
(define (cadadr x) (car (cdr (car (cdr x)))))
(define (caddar x) (car (cdr (cdr (car x)))))
(define (cadddr x) (car (cdr (cdr (cdr x)))))
(define (cdaaar x) (cdr (car (car (car x)))))
(define (cdaadr x) (cdr (car (car (cdr x)))))
(define (cdadar x) (cdr (car (cdr (car x)))))
(define (cdaddr x) (cdr (car (cdr (cdr x)))))
(define (cddaar x) (cdr (cdr (car (car x)))))
(define (cddadr x) (cdr (cdr (car (cdr x)))))
(define (cdddar x) (cdr (cdr (cdr (car x)))))
(define (cddddr x) (cdr (cdr (cdr (cdr x)))))

;(define call/cc    call-with-current-continuation)
(define first 	   car)
(define second     cadr)
(define third      caddr)
(define rest 	   cdr)
(define set-first! set-car!)
(define set-rest!  set-cdr!)
(define eqv? eq?)

(define (square n) (* n n))
(define (length items)
  (define (iter a count)
    (if (null? a)
        count
        (iter (cdr a) (+ 1 count))))
  (iter items 0))
(define (list? l)
 (if (null? l) #t
  (if (pair? l) (list? (cdr l)) #f)))
(define (pairlen l)
 (define (iter a count)
  (if (not (pair? a)) (+ count 1) (iter (cdr a) (+ 1 count))))
 (iter l 0))
(define (pair2list pr)
 (cond
  ((pair? pr) (cons (car pr) (pair2list (cdr pr))))
  (else (cons pr '()))))
(define (mappairorlist fun lst)
 (cond 
  ((null? lst) '())
  ((not (pair? lst)) (fun lst))
  (else (cons (fun (car lst)) (mappairorlist fun (cdr lst))))))
(define (list-ref lst n)
  (if (= n 0) (car lst)
    (list-ref (cdr lst) (- n 1))
    )
  )

(define (sumn n) (define (isumn n s) (if (= n 0) s (isumn (- n 1) (+ s n)))) (isumn n 0))
(define (test-quad-float n init) (if (= n 0) init (test-quad-float (- n 1) (+ (* init 0.3) 0.5))))
(define (append-core list1 list2)
  (if (null? list1)
      list2
      (cons (car list1) (append-core (cdr list1) list2))))
(define (append . lsts)
 ;(display lsts)
 (cond
   ((null? lsts) '())
   ((null? (cdr lsts)) (car lsts))
   (else
  (append-core (car lsts) (apply append (cdr lsts))))))

(define (reverse l)
  (define (iter in out)
    (if (pair? in)
        (iter (cdr in) (cons (car in) out))
        out))
  (iter l '()))
(define (headn n l)
 (if (or (= n 0) (null? l)) '()
  (cons (car l) (headn (- n 1) (cdr l)))))
	

(define (map proc . items)
 (define (map-core proc items)
  (if (null? items) '() (cons (proc (car items)) (map-core proc (cdr items)))))
 (if (null? items)
  (write-string "Error: unable to map zero arguments")
  (if (null? (car items)) '() 
   (cons (apply proc (map-core car items)) (apply map proc (map-core cdr items))))))

(define (transpose lst)
 (cond 
  ((null? lst) '())
  (else (apply map list lst))))
(define (for-all f l)
 (cond
  ((null? l) #t)
  ((f (car l)) (for-all f (cdr l)))
  (else #f)))
(define get-n-items
    (lambda (lst num)
        (if (> num 0)
            (cons (car lst) (get-n-items (cdr lst) (- num 1)))
            '())))
(define (for-each f l)
  (if (null? l)
      #t
      (begin
        (f (car l))
        (for-each f (cdr l)))))
(define (write-list lst mid endl)
  (if (null? lst) (write-char endl)
   (begin (write (car lst))
    (write-char mid)
    (write-list (cdr lst) mid endl))))
(define (simple-write-list lst)
 (if (null? lst) #t
  (begin (write (car lst)) (simple-write-list (cdr lst)))))

(define (display m1 . fp)
  (set! fp (if (null? fp) current-output-port (car fp)))
 (cond 
  ((char? m1) (write-char m1 fp))
  ((string? m1) (write-string m1 fp))
  (else (write m1 fp))))
(define (newline . z)
 (cond
  ((null? z) (write-char #\newline))
  (else (write-char #\newline (car z)))))
(define (not x)
  (if x #f #t))
(define (concat s1 s2) 
 (let ((strs2 (string->list (cond ((pair? s2) (list->string s2)) ((string? s2) s2) ((symbol? s2) (symbol->string s2))))))
  (define convertedstring (list->string (append (string->list (if (symbol? s1) (symbol->string s1) s1)) strs2)))
  (if (string? s1) convertedstring (string->symbol convertedstring))))
(define (multi-concat . args)
  (cond
    ((null? args) "")
    ((null? (cdr args)) (car args))
    (else
      (concat (car args) (apply multi-concat (cdr args)))
      )
    )
  )

(define lcons (lambda args
 (cond
  ((not (pair? (cdr args))) (car args))
  (else (cons (car args) (apply lcons (cdr args)))))))
	
(define (gengensym prefix n)
 (lambda () 
  (set! n (+ n 1))
  (concat prefix (number->string n))
  ))

(define gensym (gengensym 'MYGEN 0))
(define mygensym gensym)
(define (make_let_var_list paras input)
 (cond 
  ((null? input) (reverse paras))
  (else (make_let_var_list (cons (car (car input)) paras) (cdr input)))))
(define (make_let_val_list paras input)
 (cond 
  ((null? input) (reverse paras))
  (else (make_let_val_list (cons (car (cdr (car input))) paras) (cdr input)))))
(define quasiquote 
 (macro (x) 
  (define (constant? exp) 
   (if (pair? exp) (eq? (car exp) 'quote) (and (not (null? exp)) (not (symbol? exp)))))
  (define (combine-skeletons left right exp)
   (cond
    ((and (constant? left) (constant? right)) 
     (if (and (eqv? (eval left) (car exp)) (eqv? (eval right) (cdr exp))) 
      (list 'quote exp) 
      (list 'quote (cons (eval left) (eval right))))) 
    ((null? right) (list 'list left)) 
    ((and (pair? right) (eq? (car right) 'list)) 
     (cons 'list (cons left (cdr right)))) 
    (else (list 'cons left right)))) 
  (define (expand-quasiquote exp nesting) 
   ;(display exp) (display nesting) (newline)
   (cond 
    ((vector? exp) 
     (list 'apply 'vector (expand-quasiquote (vector->list exp) nesting))) 
    ((not (pair? exp)) 
     (if (constant? exp) exp (list 'quote exp))) 
    ((and (eq? (car exp) 'unquote) (= (length exp) 2)) 
     (if (= nesting 0) 
      (second exp) 
      (combine-skeletons ''unquote 
       (expand-quasiquote (cdr exp) (- nesting 1)) 
       exp))) 
    ((and (eq? (car exp) 'quasiquote) (= (length exp) 2)) 
     (combine-skeletons ''quasiquote 
      (expand-quasiquote (cdr exp) (+ nesting 1))
      exp)) 
    ((and (pair? (car exp)) 
      (eq? (caar exp) 'unquote-splicing) 
      (= (length (car exp)) 2)) 
     (if (= nesting 0) 
      (list 'append (second (first exp)) 
       (expand-quasiquote (cdr exp) nesting)) 
      (combine-skeletons (expand-quasiquote (car exp) (- nesting 1)) 
       (expand-quasiquote (cdr exp) nesting) 
       exp))) 
     (else (combine-skeletons (expand-quasiquote (car exp) nesting) (expand-quasiquote (cdr exp) nesting) exp))))
  (expand-quasiquote x 0)))
(define let 
 (macro input
  (cond 
   ((symbol? (car input))
    (cons (lcons 'named-lambda (car input) (cons (make_let_var_list '() (cadr input)) (cddr input))) (make_let_val_list '() (cadr input))))
   (else (cons (cons 'lambda (cons (make_let_var_list '() (car input)) (cdr input))) (make_let_val_list '() (car input)))))))
;(define let (macro input
; (set! input (cons 'let input))
; (cons (cons 'lambda (cons (make_let_var_list '() (car (cdr input))) (cdr (cdr input)))) (make_let_val_list '() (car (cdr input))))))

(define defmacro 
 (macro (name args . body)
  `(define ,name ,(cons 'macro (cons args body)))))
(defmacro named-lambda
 (name vars . body)
 (let ((varsym (gensym)))
 `(lambda ,varsym
   (let ((,name 'undefined))
    (set! ,name (lambda ,vars . ,body)) 
    (apply ,name ,varsym)))))
(defmacro case (var . cls)
 (cond
  ((null? cls) ''ERROR-IN-CASE)
  ((and (null? (cdr cls)) (eq? (caar cls) 'else)) `(begin . ,(cdar cls)))
  ((pair? var) (define tmpsym1 (gensym)) 
    `(let ((,tmpsym1 ,var)) (case ,tmpsym1 . ,cls)))
  (else
    `(cond ((eq? ,var ,(caar cls)) . ,(cdar cls))
      (else (case ,var . ,(cdr cls)))
)
)
)
)


(defmacro let* (binds . body)
 (cond 
  ((null? binds) (append '(let ()) body))
  (else (cons `(lambda (,(caar binds)) (let* ,(cdr binds) . ,body)) (cdar binds)))))

(define (letrec-proc oldbidings varnames)
 (cond
  ((null? oldbidings) varnames)
  (else (letrec-proc (cdr oldbidings) (cons (caar oldbidings) varnames)))))

(defmacro letrec (binds . body)
  (let ((vnames (letrec-proc binds '())))
   ;(display vnames)(newline)
   `(let ,(map (lambda (x) (list x 0)) vnames)
	   ,(cons 'begin (append (map (lambda (y) (cons 'set! y)) binds) body)))))

(define (remove a lst)
 (cond
  ((null? lst) '())
  ((equal? a (car lst)) (remove a (cdr lst)))
  (else (cons (car lst) (remove a (cdr lst))))))
(define (uniq-list lst)
 (cond
  ((null? lst) '())
  (else (cons (car lst) (uniq-list (remove (car lst) (cdr lst)))))))

(define cwhile
 (macro (ilt expr)
  (let ((innerloopsym (gensym)))
  `(begin (define ,innerloopsym (lambda () (if ,ilt (begin ,expr (,innerloopsym)) 'done))) (,innerloopsym)))))
	  
(define cfor 
 (macro (i0 ilt ipp expr)
  (list 'let '() i0
  (macroexpand `(cwhile ,ilt (begin ,expr ,ipp))))))
(define cfor-from-to
 (macro (i f t expr)
  (macroexpand `(cfor (define ,i ,f) (< ,i ,t) (set! ,i (+ ,i 1)) ,expr))))
(define cfffor-from-to
 (macro (x y z x0 y0 z0 x1 y1 z1 expr)
  (macroexpand `(cfor-from-to ,z ,z0 ,z1 ,(macroexpand `(cfor-from-to ,y ,y0 ,y1 ,(macroexpand `(cfor-from-to ,x ,x0 ,x1 ,expr))))))))
(define cfffor-from-zero-to
 (macro (x y z xm ym zm expr)
  (macroexpand (list 'cfffor-from-to x y z 0 0 0 xm ym zm expr))))
(define cfffor-xyz-from-zero-to
 (macro (xm ym zm expr)
  (macroexpand (list 'cfffor-from-zero-to 'xyzx 'xyzy 'xyzz xm ym zm expr))))
(define genTPH 
 (macro (name n0 n1 itans2)
  (let ((corename (concat name 'core)))
  `(define (,name n x) (define (,corename n m ans2 ans1 x) (define curn (+ (- n m) 1)) (if (= m 0) ans2 (,corename n (- m 1) ,itans2 ans2 x))) (if (= n 0) 1 (,corename n (- n 1) ,n1 ,n0 x))))))
(genTPH Tn 1 x (- (* 2 x ans2) ans1))
(genTPH Pn 1 x (- (* (/ (- (* 2 curn) 1) curn) ans2 x) (* (/ (- curn 1) curn) ans1)))
(genTPH Hn 1 (* x 2) (- (* 2 x ans2) (* 2 (- curn 1) ans1)))
(genTPH Hen 1 x (- (* x ans2) (* (- curn 1) ans1)))
(genTPH Ln 1 (- 1 x) (/ (- (* (- (* 2 curn) 1 x) ans2) (* (- curn 1) ans1)) curn))
(define m_pi 3.14159265358979323)
(define (isinlst x lst) (cond ((null? lst) #f) ((eq? x (car lst)) #t) (else (isinlst x (cdr lst)))))
(define (is-c-operator x) (isinlst x '(#\+ #\- #\* #\/ #\, #\? #\> #\<)))
(define (is-c-symbol x) (or (alpha? x) (isinlst x '(#\_))))
(define (is-c-symbol-all x) (or (is-c-symbol x) (is-c-num x) (isinlst x (string->list "!?"))))
(define (isspace x) (isinlst x (string->list "\n\r\t\v ")))
(define (is-c-del x) (or (isspace x) (is-c-operator x)))
(define (is-c-num x) (isinlst x (string->list "0123456789.")))
(define (is-c-num-all x) (or (isinlst x (string->list "Ee")) (is-c-num x)))
(define (is-bracket x) (isinlst x (string->list "()")))
(define (del-space str) 
 (cond 
  ((null? str) str)
  ((isspace (car str)) (del-space (cdr str)))
  (else str)))
(define (operatorlevel x)
 (cond 
  ((eq? x #\() -5)
  ((eq? x #\)) 100)
  ((isinlst x '(#\* #\/)) 20)
  ((isinlst x '(#\+ #\-)) 10)
  ((isinlst x '(#\> #\<)) 7)
  ((eq? x #\,) 5)
  (else 0)))

(define (get-1st-symbol str)
 (define reststr str)
 (define (get-1st-symbol-core cursym str)
  (cond
   ((or (null? str) (not (is-c-symbol-all (car str)))) cursym)
   (else (begin (set! reststr (cdr str)) (get-1st-symbol-core (cons (car str) cursym) reststr)))))
 (cons (string->symbol (list->string (reverse (get-1st-symbol-core '() (del-space str))))) reststr))

(define (get-1st-num str)
 (define reststr str)
 (define (get-1st-num-core curnum str)
  (cond
   ((or (null? str) (not (is-c-num-all (car str)))) curnum)
   (else (begin (set! reststr (cdr str)) (get-1st-num-core (cons (car str) curnum) reststr)))))
 (cons (string->number (list->string (reverse (get-1st-num-core '() (del-space str))))) reststr))
; 

(define (get-1st-element str isop)
 (define stra (del-space str))
 (cond 
  ((null? stra) '())
  ((and (eq? (car stra) #\-) isop) (cons '(-1 #\*) (cdr str)))
  ((or (is-c-operator (car stra)) (is-bracket (car stra))) stra)
  ((is-c-symbol (car stra)) (get-1st-symbol stra))
  ((is-c-num (car stra)) (get-1st-num stra))
  (else '())
 ))

(define (connectlst a b)
 (cond 
  ((pair? a) (append a b))
  (else (cons a b))))

(define (parseall str)
 (define (parseall-core str isop)
 (cond ((null? str) '())
  (else (begin (define tmpvar (get-1st-element str isop))
   (connectlst (car tmpvar) (parseall-core (cdr tmpvar) (or (is-c-operator (car tmpvar)) (pair? (car tmpvar))(isinlst (car tmpvar) '(#\()))))))))
 (parseall-core str #t))

(define (levelofstk stk)
 (cond 
  ((null? stk) 0)
  (else (operatorlevel (car stk)))))

(define (c2schemecore strp stk opt) ;(write-string "dbg:stk:") (write stk) (write-string "strp:")(write strp) (display "")(newline)
 (if (null? strp) (begin 
		   ;(write-string "end") (display stk) 
		   (append (reverse stk) opt))
  (cond 
   ((or (number? (car strp)) (symbol? (car strp))) (begin 
	   ;(write-string "pm") (display strp)(newline)
	   (c2schemecore (cdr strp) stk (cons (car strp) opt))))
   ((and (eq? (car strp) #\)) (eq? (cadr strp) #\()) (c2schemecore (cdddr strp) stk (append (list #\@ (caddr strp)) opt)))
   ((>= (operatorlevel (car strp)) (levelofstk stk)) (begin 
	   ;(write strp) (write stk) (display "opt")
	   (c2schemecore (cdr strp) (cons (car strp) stk) opt)))
   ((eq? (car strp) #\() (begin ;(write-string "(") (display stk)
    (cond
     ((eq? (car stk) #\)) 
      (cond
       ((or (null? (cdr strp)) (not (symbol? (cadr strp)))) (c2schemecore (cdr strp) (cdr stk) opt))
       (else (c2schemecore (cddr strp) (cdr stk) (append (list #\# (cadr strp)) opt)))))
     (else (c2schemecore strp (cdr stk) (cons (car stk) opt))))))
   ((eq? (car stk) #\)) (c2schemecore (cdr strp) (cons (car strp) stk) opt))
   (else (begin 
	  ;(write-string "lst") (display strp) 
	  (c2schemecore strp (cdr stk) (cons (car stk) opt)))))))

(define (getfun strp) 
 (cond 
  ((or (eq? (car strp) #\#) (eq? (car strp) #\@)) (cadr strp))
  ((is-c-operator (car strp)) (string->symbol (list->string (list (car strp)))))
  (else (display 'synerr:) (display strp) '())))

(define (findfirstn curn ele lst)
 (cond 
  ((or (null? lst) (not (eq? ele (car lst)))) (cons curn lst))
  (else (findfirstn (+ curn 1) ele (cdr lst)))
 ))

(define (getnumarg strp)
 (cond
  ((eq? (car strp) #\@) (cons 0 (cddr strp)))
  ((eq? (car strp) #\#) (findfirstn 1 #\, (cddr strp)))
  (else (cons 2 (cdr strp)))))

(define (last2schemecore numargs ans strp)
 (cond 
  ((or (null? strp) (= numargs 0)) (cons ans strp))
  ((or (number? (car strp)) (symbol? (car strp))) (last2schemecore (- numargs 1) (cons (car strp) ans) (cdr strp)))
  (else ;(write strp) (display 'last)
   (let ((fun (getfun strp)) (parseline (getnumarg strp)))
	 (define fstproc (last2schemecore (car parseline) '() (cdr parseline)))
	 ;(write fstproc) (display 'lastproc)
	 (last2schemecore (- numargs 1) (cons (cons fun (reverse (car fstproc))) ans) (cdr fstproc))))))
   
(define (c2scheme str)
 (caar (last2schemecore 1 '() (c2schemecore (reverse (parseall (string->list str))) '() '()))))

(define (read-line-list-stdin curlst) 
 (cond 
  ((eof-object? (peek-char)) (reverse curlst))
  ((eq? (peek-char) #\newline) (read-char) (reverse curlst))
  (else (read-line-list-stdin (cons (read-char) curlst)))))

(define (read-line-list curlst pt) 
 (cond 
  ((eof-object? (peek-char pt)) (reverse curlst))
  ((eq? (peek-char pt) #\newline) (read-char pt) (reverse curlst))
  (else (read-line-list (cons (read-char pt) curlst) pt))))
(define (read-line fp)
 (define r1 (peek-char fp))
 (cond
  ((eof-object? r1) r1)
  (else (list->string (read-line-list '() fp)))))

(define runc (macro (str)
 (c2scheme str)))

(define (crepl-stdin)
 (define li (read-line-list-stdin '()))
  (cond
   ((null? li)(write-string "=> ") (crepl-stdin))
   ((eq? (list->string li) "toscheme") 'done)
   (else  (display (eval (c2scheme (list->string li)))) (write-string "=> ") (crepl-stdin))))

(define (crepl pt)
 (define li (read-line-list '() pt))
  (cond
   ((null? li) 'done)
   (else (eval (c2scheme (list->string li))) (crepl pt))))

(define (s2lcore lst)
 ;(display lst)
 (cond 
  ((pair? lst) 
   (cond 
    ((and (eq? (car lst) 'define) (not (null? (cdr lst))) (not (null? cddr lst)) (pair? (cadr lst))) (append (list 'defun (caadr lst) (cdadr lst)) (s2lcore (cddr lst))))
    (else (cons (s2lcore (car lst)) (s2lcore (cdr lst))))))
  ((eq? lst 'else) 'T)
  ((eq? lst #t) 'T)
  ((eq? lst #f) 'nil)
  ((eq? lst 'null?) 'null)
  ((eq? lst 'eq?) 'eq)
  ((eq? lst 'define) 'defvar)
  ((eq? lst 'begin) 'progn)
  ((eq? lst 'symbol?) 'symbolp)
  ((eq? lst 'pair?) 'consp)
  ((eq? lst 'set!) 'setq)
  (else lst)))

(define (s2l fname) 
 (cfor (begin (define fin (open-input-file fname)) (define ipa (read fin))) 
  (not (eof-object? ipa))
  (set! ipa (read fin))
  (begin 
   ;(display ipa)
   (display (s2lcore ipa)))))

(define expt pow)

(define (loadaspackage . args)
 (define str (car args))
 ;(display (cdr args))
 (define fport (open-input-file str))
 (cond
  ((eq? fport #\f) '())
  (else 
    (define emp '())
    (define (loadall filp)
     (define tmpobj 0)
     (cwhile (begin (set! tmpobj (read filp)) (not (eof-object? tmpobj))) (begin (set! emp (cons tmpobj emp)))));(display (car emp)) (newline))))
     ;(begin (define MYGEN1 (lambda () (if (and (not (eof-object? (peek-char filp))) (< (length emp) 10)) (begin (begin (set! emp (cons (read filp) emp))) (MYGEN1)) (quote done)))) (MYGEN1)))
    (begin (loadall fport) 
     (display 'file-loaded)(newline)
     (let ((myeval (cons 'begin (reverse (append (cdr args) emp)))))
     ;(display myeval)
     (eval myeval))
     ))))
(define (equal? a b)
 (cond
  ((not (pair? a)) (eq? a b))
  ((and (pair? a) (pair? b))
   (and (equal? (car a) (car b)) (equal? (cdr a) (cdr b))))
  (else #f)
  ))

;(define localcpser (loadaspackage "cpser.scm" '(list cpser localeval prefuncps global_cpsfuns_generate global_cpsfuns)))
;(define cpser (car localcpser))
(define 
 (mypow x n)
  (cond
   ((= n 0) 1)
   ((even? n) (square (mypow x (/ n 2))))
   (else (* x (mypow x (- n 1))))))
(define (delete-from-list x lst)
 (cond ((null? lst) '())
  ((pair? lst) (cond ((eq? x (car lst)) (delete-from-list x (cdr lst))) (else (cons (car lst) (delete-from-list x (cdr lst))))))
  (else lst)))
(define replace-all
 (lambda (lst from to)
  (cond
   ((null? lst) '())
   ((pair? lst) (cons (replace-all (car lst) from to) (replace-all (cdr lst) from to)))
   (else 
    (cond ((eq? lst from) to) 
     (else lst))))))
(define (atom? x) (not (or (null? x) (pair? x))))
(define (atomall? x) (or (atom? x) (eq? (car x) 'quote)))

(define (macroexpand-all-list lst)
 (cond 
  ((not (pair? lst)) lst)
  (else (cons (macroexpand-all (car lst)) (macroexpand-all-list (cdr lst))))))

(define (dump-lambda lmd)
 (lcons 'lambda (args-of-lambda lmd) (body-of-lambda lmd)))
(define (macroexpand-all prog)
 (cond 
  ((pair? prog) 
   (cond
    ((eq? (car prog) 'quote) prog)
    ((and (symbol? (car prog)) (symbol-binded? (car prog)) (macro? (eval (car prog))))
     (macroexpand-all (macroexpand prog)))
    (else (cons (macroexpand-all (car prog)) (macroexpand-all-list (cdr prog))))))
  (else prog)))
(define (let_var_to_values_form lst)
 ;(display lst)(newline)
 (cond 
  ((null? lst) '(() ()))
  (else 
   (let ((transformed (let_var_to_values_form (cdr lst))))
    (list (cons (caar lst) (car transformed)) (cons (cadar lst) (cadr transformed)))))))
(define (let_values_to_var_form lst)
 (cond 
  ((null? (car lst)) '())
  (else
   (cons (list (caar lst) (caadr lst)) (let_values_to_var_form (list (cdar lst) (cdadr lst)))))))

(define (optload-core str)
 (let ((fp (open-input-file str)))
  (cond 
   ((not fp) (write-string "unable to open file :")(write-string str)(newline) #f)
   (else
    (let loop ((fstl (read fp)) (progloaded '()))
     (cond 
      ((eof-object? fstl) (cons 'begin (reverse progloaded)))
      (else (loop (read fp) (cons fstl progloaded)))))))))
(defmacro optload (str)
 ;(cond 
  ;((not (string? str)) (write-string "Error: this macro can only accept string form")(newline) #f)
 `(eval (macroexpand-all (optload-core ,str))))
(define cscheme_internal_write iwrite)
(define cscheme_internal_read iread)
(define cscheme_internal_write-string iwrite-string)
(define cscheme_internal_write-char iwrite-char)
(define cscheme_internal_read-char iread-char)
(define cscheme_internal_peek-char ipeek-char)

(define genwrite 
 (macro (name internalname defaultport)
  `(define (,name . arg)
	  (cond 
	   ((null? (cdr arg)) (,internalname (car arg) ,defaultport))
	   (else (,internalname (car arg) (cadr arg)))))))
(genwrite write cscheme_internal_write current-output-port)
(genwrite write-string cscheme_internal_write-string current-output-port)
(genwrite write-char cscheme_internal_write-char current-output-port)
(define genread
 (macro (name internalname defaultport)
  `(define (,name . arg)
	  (cond 
	   ((null? arg) (,internalname ,defaultport))
	   (else (,internalname (car arg)))))))

(genread read cscheme_internal_read current-input-port)
(genread read-char cscheme_internal_read-char current-input-port)
(genread peek-char cscheme_internal_peek-char current-input-port)
(define current-input-port icurrent-input-port)
(define current-output-port icurrent-output-port)
(define current-error-port icurrent-error-port)
(define (append-string . args)
 (cond 
  ((null? args) "")
  (else (list->string (append (string->list (car args)) (string->list (apply append-string (cdr args))))))))

(define (quick-sort! vec cmpfun)
 (define (quick-sort-core vec beg end1)
  (cond
   ((<= (- end1 beg) 1) 'done)
   (else 
    (let
     ( 
      (len (- end1 beg))
      (midvar (vector-ref vec beg))
      (i (+ beg 1))
      (j (- end1 1))
    )
    (let loop ()
     (cfor 'done (and (< i end1) (cmpfun (vector-ref vec i) midvar)) (set! i (+ i 1)) (begin (write 'i=)(write i) (newline))) 
     (cfor 'done (and (> j 0) (not (cmpfun (vector-ref vec j) midvar))) (set! j (- j 1)) (begin (write 'j=)(write j) (newline)))
     (cond
      ((>= i j) 'done)
      (else 
       (let ((tmpvar (vector-ref vec i))) 
	(vector-set! vec i (vector-ref vec j)) 
	(vector-set! vec j tmpvar)
	(loop)))))
    (vector-set! vec beg (vector-ref vec j))
    (vector-set! vec j midvar)
    (quick-sort-core vec beg j)
    (quick-sort-core vec (+ j 1) end1)))))
 (quick-sort-core vec 0 (vector-length vec)))
(define (genrand initnum)
 (lambda ()
  (set! initnum (* initnum 44485709377909))
  initnum))
(define rand (genrand 12))

(define (list->vector lst)
 (apply vector lst))
(define (vector->list vec)
 (define l0 '())
 (cfor-from-to i 0 (vector-length vec)
  (set! l0 (cons (vector-ref vec i) l0)))
 (reverse l0))
(define (list-copy lst) (vector->list (list->vector lst)))
(defmacro with-current (old new . prog)
  (define fportsym (gensym))
  (define res (gensym))
  `(let ((,fportsym ,old))
     (set! ,old ,new)
     (define ,res (begin . ,prog))
     (set! ,old ,fportsym)
     ,res
     )
  )
(defmacro with-current-input-port (newport . prog)
  `(with-current current-input-port ,newport . ,prog)
  )
(defmacro with-current-output-port (newport . prog)
  `(with-current current-output-port ,newport . ,prog)
  )
(define pairs2list (lambda (p) (cond ((null? p) p) ((not (pair? p)) (list p)) (else (cons (car p) (pairs2list (cdr p)))))))
(define (complement a b)
 (cond
  ((pair? a)
   (cond ((isinlst (car a) b) (complement (cdr a) b))
    (else (cons (car a) (complement (cdr a) b)))))
  (else '())))
(define (fast-make-single-env-from-var-and-val varval)
  (internal-make-single-env-from-var-and-val (map car varval) (map cdr varval))
  )
(define (fast-find-var-in-single-env var env)
  (internal-find-var-in-single-env var (list env) 'VAR-NOT-BOUND)
  )
(define (multi-define-core vars lst)
 (define (multi-define-core-core vars lst)
  (cond ((pair? vars)
    (cons `(define ,(car vars) (car ,lst)) (multi-define-core-core (cdr vars) `(cdr ,lst))))
   (else '())))
 (multi-define-core-core vars lst))
(defmacro multi-define vars-lst
 (define sym (gensym))
 (define revvarlst (reverse vars-lst))
 (define vars (reverse (cdr revvarlst)))
 `(begin (define ,sym ,(car revvarlst)) . ,(multi-define-core vars sym)))
(define (random01)
  (+ (/ (rand) (pow 2 64)) 0.5)
  )



'stdlib-loaded
;(defmacro cfor (i0 ilt ipp expr) (defun icfor (ilt ipp expr) (if (eval ilt) (progn (eval expr) (eval ipp) (icfor ilt ipp expr)) ''done)) (progn (eval i0) (icfor ilt ipp expr)))
