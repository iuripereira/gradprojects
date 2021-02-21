import IO

main fn = 
		do 	x <- openFile fn ReadMode
			y <- hGetContents x
			--let (h:t) = (words y) in putStr h
			putStr (show (words y))