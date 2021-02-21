f :: (Eq a, Eq b) => a -> a -> b -> b -> Bool
f a1 a2 b1 b2 = if a1 == a2 && b1 == b2 then True
		else False