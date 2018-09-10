(define (interp_cfg)
  (let loop ((expr (read)))
    (cond
      ((eof-object? expr) 0)
      (else
	(cond
	  ((pair? expr) 
	    (define carexpr (car expr))
	    (cond
	      ((eq? carexpr 'many-define)
		(map
		  (lambda (x)
		    (write (car x))
		    (write-string " ")
		    (write (cadr x))
		    (write-string "\n")
		    )
		  (cdr expr))
		)
	      ((eq? carexpr 'define)
		(cond
		  ((pair? (cadr expr)) 
		    (write (caadr expr))
		    (write-string " ")
		    (write (lcons 'lambda (cdadr expr) (cddr expr)))
		    (write-string "\n")
		    )
		  (else
		    (write (cadr expr))
		    (write-string " ")
		    (write (caddr expr))
		    (write-string "\n")
		    ))
		)
	      (else 0)
	      )
	    )
	  (else 0)
	  )
	(loop (read))
	)
      )
    )
  )
(interp_cfg)
(exit)
