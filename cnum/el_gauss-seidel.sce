// Métodos Iterativos - Gauss-Seidel

a = [ 15   3   2   9  -1 ; 
       2   9   3   3  -2 ;
       5   8 -22   4   0 ;
       1  -1   3  13   0 ;
       0   3   6  -5  18 ];
       
ya = [ 0 0.5 2 0 2 ];

b = [  0  12 -15   0   0 ];

n = length(b);

e = 0,001;

ea = e + 1;

// Método de Gauss-Seidel

y = [ 0 0 0 0 0 ];

max_it = 8;

it = 0;

while (ea > e) & (it < max_it) do

    for i = 1 : n
    
        somat = 0;
        
        for k = 1 : (i-1)
            somat = somat + a(i,k)*y(k);
        end
        
        for k = (i + 1) : n
            somat = somat + a(i,k)*ya(k);
        end        	
        
        y(i) = (1/a(i,i))*(b(i) - somat);
    end;
    
    ea = max( abs(y - ya) );
    ya = y;
    it = it + 1;
end

y
