-- (define zero (lambda (f) (lambda (x) x)))
zero = (\f -> (\x -> x))

-- (define (add-1 n)
--   (lambda (f) (lambda (x) (f ((n f) x)))))
add_1 n = (\f -> (\x -> f ((n f) x)))

-- 0 = (\f -> (\x -> x))
-- 1 = (\f -> (\x -> f (((\f -> (\x -> x)) f) x)))
-- 1 = (\f -> (\x -> f ((\x -> x) x)))
-- 1 = (\f -> (\x -> f x))
one = (\f -> (\x -> f x))

-- 2 = (\f -> (\x -> f (((\f -> (\x -> f x)) f) x)))
-- 2 = (\f -> (\x -> f ((\x -> f x) x)))
-- 2 = (\f -> (\x -> f (f x))
two = (\f -> (\x -> f (f x))

-- (f (f (f x))) + (f (f x))
-- = (f (f (f (f (f x)))))
add a b = (\f -> (\x -> (a f).(b f)))
