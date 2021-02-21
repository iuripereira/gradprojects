main = print (rInt "12",rBool "True", rFloat "34", rString 50)

rInt :: String -> Int
rInt = read

rBool :: String -> Bool
rBool = read

rFloat :: String -> Float
rFloat = read

rString :: Int -> String
rString = show

