; sicp.exercise.1.2
;-------------------------------------------------------
; * Problem
;Translate the following expression into prefix form:
; (5+4+(2-(3-(6+4/5))) / (3(6-2)(2-7))

;-------------------------------------------------------
; * Answer

(/ (+ 5 4 (- 2 (- 3 (+ 6 (/ 4 5))))) (* (- 6 2) (- 2 7)))

;===========================================
; * Output
;-------------------------------------------
;-0.76
