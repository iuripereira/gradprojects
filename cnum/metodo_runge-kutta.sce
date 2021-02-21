// Equações Diferenciais Ordinárias - Problema do Valor Inicial
// Métodos de Runge-Kutta de Segunda Ordem e de Quarta Ordem - 10/05/2007

// Resolver pelos métodos de Runge-Kutta o seguinte problema de valor inicial:
// dy/dx = xy   y(x_0 = 0) = y_0 = 1   Y = (e)^(x^2/2)

// Obs:. Testar os seguintes passos de integracao:
// x = [ 0  :  0.25   : 1 ]
// x = [ 0  :  0.05   : 1 ]
// x = [ 0  :  0.005  : 1 ]

// Euller
// y_i+1 = y_i + h * x_i * y_i

// Runge-Kutta de Segunda Orgem
// y_i+1 = y_i + h/2 * (k_1 + k_2)
// k_1 = f(x_i, y_i)
// k_2 = f(x_i+1, y_i + h * k_1)

// Runge-Kutta de Quarta Orgem
// y_i+1 = y_i + h/6 * (k_1 + 2 * k_2 + 2 * k_3 + k_4)
// Ou seja:
// k_1 = f(x_i,y_i)
// k_2 = f(x_i + h/2, y_i + (h/2) * k_1)
// k_3 = f(x_i + h/2, y_i + (h/2) * k_2)
// k_4 = f(x_i + h, y_i + h * k_3)

clear
clc

// Funcao Caracteristica dydx
function z = dydx(x, y)
  z = x * y;
endfunction

// Função que fornece a menor diferença
function Y = f(x)
  n = length(x);
  
  for i = 1 : n
    Y(i) = (%e)^((x(i)^2)/2);
  end
endfunction

function y = rungekutta2(x, h)
  n = length(x);
  y(1) = 1.0; // pvi
  
  for i = 1 : (n - 1)
    k1 = dydx(x(i), y(i));
    k2 = dydx(x(i+1), y(i) + (h * k1));
    y(i+1) = y(i) + (h/2 * (k1 + k2));
  end
endfunction

function y = rungekutta4(x, h)
  n = length(x);
  y(1) = 1.0; // pvi
  
  for i = 1 : (n - 1)
    k1 = dydx(x(i), y(i));
    k2 = dydx(x(i) + h/2, y(i) + (h/2 * k1));
    k3 = dydx(x(i) + h/2, y(i) + (h/2 * k2));
    k4 = dydx(x(i) + h, y(i) + (h * k3));
    y(i+1) = y(i) + (h/6 * (k1 + 2 * k2 + 2 * k3 + k4));
  end
endfunction

// x variando de 0 a 1 com intervalos de 0.25
h = 0.25;
x = [ 0 : h : 1 ];

//resp = rungekutta2(x, h)
//resp2 = f(x) // retirar o ponto-e-virgula para obter o resultado
//erro = resp2 - resp // retirar o ponto-e-virgula para obter o resultado

// x variando de 0 a 1 com intervalos de 0.25
//h = 0.05;
//x = [ 0 : h : 1 ];

//resp = rungekutta2(x, h)
//resp2 = f(x) // retirar o ponto-e-virgula para obter o resultado
//erro = resp2 - resp // retirar o ponto-e-virgula para obter o resultado

// x variando de 0 a 1 com intervalos de 0.25
//h = 0.005;
//x = [ 0 : h : 1 ];

//resp = rungekutta2(x, h)
//resp2 = f(x) // retirar o ponto-e-virgula para obter o resultado
//erro = resp2 - resp // retirar o ponto-e-virgula para obter o resultado
