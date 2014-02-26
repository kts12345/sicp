; sicp.exercise.1.1
;-------------------------------------------------------
; * Problem
;Below is a sequence of expressions. What is the result printed by the ;interpreter in
;response to each expression? Assume that the sequence is to be evaluated in the ;order in which it is 
;presented.
; (5+4+(2-(3-(6+4/3))) / (3(6-2)(2-7))

;-------------------------------------------------------
; * Answer

(/ (+ 5 4 (- 2 (- 3 (+ 6 (/ 4 3))))) (* (- 6 2) (- 2 7)))

;===========================================
; * Output
;-------------------------------------------
;-0.76