import IO

main = do
		x <- openFile "C:\\Documents and Settings\\Umberto\\Desktop\\foo.txt" ReadMode
		y <- hGetContents x
		let (h:t) = (words y) in putStr h
