// Metodo de Jordan - Eliminação de Gauss
function [x, c] = jordan(a,b)
  n = length(b);

  // Pivoteamento
  for m = 1 : n
    for k = (m+1) : n
      a(m,k) = a(m,k)/a(m,m);
    end
    
    b(m) = b(m)/a(m,m);
    a(m,m) = 1;

    // Eliminacao
    for j = 1 : n,
      if(j <> m) then 
        d = a(j,m);
        
        for k = 1 : n,
          if(n<>1) then
            a(j,k) = a(j,k) - d * a(m,k);
          end
        end
        
        b(j) = b(j) - b(m) * d;
      end
    end
    
  end
endfunction
// Exemplo da apostila
a = [ 1  1  2; 
      2 -1 -1; 
      1 -1 -1];
      
b = [4 0 -1];

[a,b] = jordan(a,b)


