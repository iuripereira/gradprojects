clear
clc

function pol = f(x,val)
	pol = 0;
	
	for i = 0 : length(x) - 1
		pol = pol + x(i+1)*val^i;
	end
endfunction

// Metodo de Jordan - Eliminação de Gauss
function [a,b] = jordan(a,b)

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

function [a,b] = regPol(n,x,y)
	a = [];
	b = [];
	m = length(x);

	for i = 0 : n
		for j = 0 : n
			soma = 0;
			for k = 1 : m
				soma = soma + (x(k)^(i+j));
			end
			a(i+1,j+1) = soma;
		end
		soma = 0;
		for k = 1 : m
			soma = soma + y(k)*(x(k)^i);
		end
		b(i+1) = soma;
	end
endfunction


function [c] =  f2(x)
	c = sin((%pi/4)*x);
endfunction

d = 0;
for i=0.2: 0.2 :1
	d = d+1;
	x(1,d) = i;
	y(1,d) = f2(i);
end
x
y

[a,b] = regPol(3, x, y);
[result,resp] = jordan(a,b);
result2 = f(resp, 0.5)




