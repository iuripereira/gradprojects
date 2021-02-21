// Sistemas de Integracao - 24/04/207

// Três lagos constituem um complexo de geracão de energia elétrica, abastecimento de água e irrigação.
// A tabela 1 fornece medições, para os três lagos, de cotas e áreas planimétricas de espelho d'agua.
// Calcule o volume máximo de água que pode ser acumulada em cada lago.

clear
clc

// Método dos Trapézios
function resultado = trapezios(x, y)
  n = length(x);
  h = (x(n) - x(1)) / n;
  soma = 0;
  
  for i = 2 : n - 1
			soma = soma + y(i);
	end
	
	resultado = (soma + ((y(1) + y(n)) / 2)) * h;
endfunction

// Método Simpson de 1/3
function resultado = simpson1_3(x, y)
  n = length(x);
  h = (x(n) - x(1)) / n;
  
  somapares = 0;	
  somaimpares = 0;	
  
  for i = 1 : n - 2
    if(modulo(i, 2) == 0) then
      somapares = somapares + y(i + 1);
    else
      somaimpares = somaimpares + y(i + 1);
    end
  end

  resultado = (h / 3) * (somapares * 2 + somaimpares * 4 + y(1) + y(n));
endfunction

// Método Simpson de 3/8
function resultado = simpson3_8(x, y)
  n = length(x);
  h = (x(n) - x(1)) / n;
  
  somam3 = 0;
  somanm3 = 0;
  
  for i = 1 : (n - 2)
    if(modulo(i, 3) == 0)
      somam3 = somam3 + y(i + 1);
    else
      somanm3 = somanm3 + y(i + 1);
    end
  end

  resultado = (3 * h / 8) * (y(1) + y(n) + (2 * somam3) + (3 * somanm3));
endfunction


// Constantes
x1 = [ 0 5 10 15 20 ];
y1 = [ 10000 12000 14000 17000 20000 ];

x2 = [ 0 3 6 9 12 ];
y2 = [ 12000 20000 25000 33000 45000 ];

x3 = [ 0 4 8 12 16 ];
y3 = [ 16000 20000 25000 33000 45000 ];

// Trapézio
trap_1 = trapezios(x1, y1)
trap_2 = trapezios(x2, y2)
trap_3 = trapezios(x3, y3)

// Simpson de 1/8
simpson_1 = simpson1_3(x1, y1)
simpson_2 = simpson1_3(x2, y2)
simpson_3 = simpson1_3(x3, y3)

// Simpson de 3/8
simpson_1 = simpson3_8(x1, y1)
simpson_2 = simpson3_8(x2, y2)
simpson_3 = simpson3_8(x3, y3)
