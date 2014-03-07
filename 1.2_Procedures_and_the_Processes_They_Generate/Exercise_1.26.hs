
-- (remainder (square (expmod base (/ exp 2) m))
--            m))
-- => (expmod ...) 이 계산된 후, square에 넘겨짐
--
-- (remainder (* (expmod base (/ exp 2) m)
--            (expmod base (/ exp 2) m))
-- => (expmod ...) 이 각각 계산된 후, square에 넘겨짐
