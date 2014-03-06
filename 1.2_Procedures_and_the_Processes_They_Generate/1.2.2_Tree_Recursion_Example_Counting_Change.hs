-- (define (count-change amount)
--   (cc amount 5))
count_change amount = cc amount 5

-- (define (cc amount kinds-of-coins)
--   (cond ((= amount 0) 1)
--         ((or (< amount 0) (= kinds-of-coins 0)) 0)
--         (else (+ (cc amount
--                      (- kinds-of-coins 1))
--                  (cc (- amount
--                         (first-denomination kinds-of-coins))
--                      kinds-of-coins)))))
cc amount kinds_of_coins | 0 == amount = 1
                         | or [(amount < 0), (kinds_of_coins == 0)] = 0
                         | otherwise = (cc amount (kinds_of_coins - 1)) +
                                       (cc (amount - (first_demonination kinds_of_coins))
                                           kinds_of_coins)

-- (define (first-denomination kinds-of-coins)
--   (cond ((= kinds-of-coins 1) 1)
--         ((= kinds-of-coins 2) 5)
--         ((= kinds-of-coins 3) 10)
--         ((= kinds-of-coins 4) 25)
--         ((= kinds-of-coins 5) 50)))
first_demonination kinds_of_coins | kinds_of_coins == 1 = 1
                                  | kinds_of_coins == 2 = 5
                                  | kinds_of_coins == 3 = 10
                                  | kinds_of_coins == 4 = 25
                                  | kinds_of_coins == 5 = 50

main = do
  print $ count_change 100
