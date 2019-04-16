#include <stdio.h>
#include <stdlib.h>
#define N 4 // Ordem do sistema

int main (){
    int i, j, k;
    float fator, soma;
    float X[N];
    float M[N][N + 1] = {{4, 3, 2, -1, 10}, {1, 2, 3, 4, 5}, {1, -1, -1, -1, -1}, {1, 1, 1, 1, 3}}; // Questão A
    //float M[N][N + 1] = {{1, 2, 3, 4, 10}, {2, 1, 2, 3, 7}, {3, 2, 1, 2, 6}, {4, 3, 2, 1, 5}}; // Questão B
    //float M[N][N + 1] = {{1, -0.25, -0.25, 0, 0}, {-0.25, 1, 0, -0.25, 0}, {-0.25, 0, 1, -0.25, 0.25}, {0, -0.25, 0, 1, 0.25}}; // Questão C
    //float M[N][N + 1] = {{4, 1, 1, 1, 7}, {2, -8, 1, -1, -6}, {1, 2, -5, 1, -1}, {1, 1, 1, -4, -1}}; // Questão D
    //float M[N][N + 1] = {{5, -1, 2, -1, 5}, {1, 9, -3, 4, 26}, {0, 3, -7, 2, -7}, {-2, 2, -3, 10, 33}}; // Questão E

    for(i = 0; i < N; i++) {
        for(j = 0; j <= N; j++) {
            printf("|  %.1f\t", M[i][j]);
        }
        printf("\n");
    }

    // ELIMINACAO PROGRESSIVA

    //Laco exterior se refere a coluna pivo que se altera. (linha pivo ou equacao pivo = equacao referencial para as eliminacoes)
    for(k = 0; k < (N - 1); k++) {
        //Este laco se refere as linhas que sofrerao as eliminacoes, que sempre iniciarao na linha seguinte da linha pivo
        for(i = (k + 1); i < N; i++) {
            fator = M[i][k] / M[k][k];//fator de correcao que sera multiplicada pela linha pivo
            for(j = 0; j <= N; j++) {//loco interno se refere a cada coluna da linha que sofrerao modificacoes da linha i
                M[i][j] = M[i][j] - fator * M[k][j];
            }
        }
    }

    X[N - 1] = M[N - 1][N] / M[N - 1][N - 1]; // Primeria variavel que obtamos

    printf("\n");
    for(i = 0; i < N; i++) {
        for(j = 0; j <= N; j++) {
            printf("|  %.1f\t", M[i][j]);
        }
        printf("\n");
    }

    // SUBSTITUICAO PROGRESSIVA

    //Laco exterior se refere a linha que recebera os valores das variaveis ja encontradas para descobrirmos  as outras. Ela se inicia na penultima linha e vai ate a primeira
    for(i = (N - 2); i >= 0; i--){
        soma = 0;
        for(j = (i + 1); j < N; j++){     
            soma = soma + M[i][j] * X[j]; // soma todos os numeros da linha que ja tem o valor de x
        }
        X[i] = (M[i][N] - soma) / M[i][i]; // Calcula o x da coluna i
    }

    printf("\nResultado: " );
    for(i = 0; i < N; i++) {
        printf("\nX%d = %f\n", i + 1, X[i]);
    }
}