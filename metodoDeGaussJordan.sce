/////////////////////////////////////////////////////////
// Sistema de Equeção Lineares: Método de Gauss-Jordan //
/////////////////////////////////////////////////////////

// Marcos André Azevedo de Assis

mprintf("Método de Gauss-Jordan:\n\n");

// Matriz
//A = [2 3 1 -1; -1 1 -4 1; 1 1 1 1; 4 -5 1 -2]; // Letra a

//A = [4 3 2 1; 1 2 3 4; 1 -1 -1 -1; 1 1 1 1]; //Letra b

A = [1 2 3 4; 2 1 2 3; 3 2 1 2; 4 3 2 1]; // Letra c

//A = [1 1 2 4; 1 1 5 6; 2 5 1 2; 4 6 2 1]; // Letra d

// Matriz resultado
//B = [6.90; -6.60; 10.20; -12.30]; // Letra a

//B = [10; 5; -1; 3]; // Letra b

B = [10; 7; 6; 5]; // Letra c

//B = [7.12; 12.02; 14.90; 20.72]; // Letra d

mprintf("Matriz:");
disp(A);

mprintf("\nResultante da Matriz:");
disp(B);

[n n] = size(A);

mprintf("\nTamanho da Matriz:");
disp([n n])

mprintf("\nMatriz Pronta:")
A=[A';B']';
disp(A)

x = zeros(n, 1);

for p = 1 : n
    for k = [1 : p - 1, p + 1 : n];
        m = -A(k, p) / A(p, p);
        A(k, :) = A(k, :) + m * A(p, :)
        disp(A)
    end
end

x = A(:, n + 1)./diag(A)

disp(x)
