// Interpolação por Polinomios de Lagrange(valor de X) - 10/04/2007

// Em um açude, são feitas quatro medições de cotas(em metros) e, para cada uma delas,
// é medida a área do espelho d'água(em m^2) por aerofotogrametria, resultando nas medições:
// (x_0 = 0, y_0 = 100), (x_1 = 3, y_1 = 855), (x_2 = 6, y_2 = 7700), (x_3 = 9, y_3 = 35600).
// Calcular a área do espelho d'água na cota de 4,5m. (Resposta: 2580,93 m^2)

clear
clc

function resposta = lagrange(x, y, valor)
  n = length(x);
  soma = 0;
  
  for i = 1 : n
    mult = 1;
    
    for j = 1 : n
      if(j <> i)
        mult = mult * (valor - x(j)) / (x(i) - x(j));
      end
    end
    soma = soma + (y(i) * mult);
  end
  
  resposta = soma;
endfunction

// Constantes
x = [ 0 3 6 9 ];
y = [ 100 855 7700 35600 ];
valor = 4.5;

resp = lagrange(x, y, valor);

printf("\n\n ## Resultado por Lagrange: %f\n", resp);



