// Métodos Iterativos - Gauss-Seidel
function [x] = gaussseidel(a, b, x0, m, tol)
n = length(b);
e = tol;
ea = e + 1;
// Método de Gauss-Seidel
max_it = m;
it = 0;
while (ea > e) & (it < max_it) do
    for i = 1 : n
    
        somat = 0;
        
        for k = 1 : (i-1)
            somat = somat + a(i,k)*x0(k);
        end
        
        //for k = (i + 1) : n
        //    somat = somat + a(i,k)*ya(k);
        //end        	
        
        x0(i) = (1/a(i,i))*(b(i) - somat);
    end;
    
    //ea = max( abs(y - ya) );
    //ya = y;
    it = it + 1;
end

x0
endfunction
