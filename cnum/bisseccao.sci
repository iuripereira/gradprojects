clear;

function y =f(x)
    y = %e^(-x) -x
endfunction;


counter = 0;
epsilon = 10^(-6);
delta = 0.5;
xi = 0;
xf = xi + delta;

while((f(xi)*f(xf)) > 0)
    xi = xf;
    xf = xf + delta;
end;

xm = (xi+xf)/2;


while ((abs(f(xm)) > epsilon) & counter < 20),
    xm = (xi + xf)/2;
    if(f(xm)*f(xi) < 0) then
        xf = xm;
    else
        xi = xm;
    end;
    counter = counter + 1;
end;

if(counter < 20) then
    printf("Resultado de f(x) = %f, utilizando precisao %f em %d iteracoes\n",f(xm),epsilon,counter);
else
    printf("Resultado nao convergente no intervalo em 20 iteracoes !\n");
end;


