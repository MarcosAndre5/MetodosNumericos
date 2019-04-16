#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 4

int main() {
	int t, j, i, k;
	bool pare = false;
	float x[TAM], x2[TAM], norma = 0, soma = 0, soma2 = 0;
	float x0[TAM] = {0, 0, 0, 0}; // Inserindo os elementos no vetor X
	float e = 10^-3; // Inserindo os critério de parada
	
		// Inserindo os elementos na matriz A
	//float a[TAM][TAM] = {{4, 3, 2, -1}, {1, 2, 3, 4}, {1, -1, -1, -1}, {1, 1, 1, 1}}; // Questão A
		// Inserindo os elementos na matriz B
	//float b[TAM] = {10, 5, -1, 3};
	
		// Inserindo os elementos na matriz A
	//float a[TAM][TAM] = {{1, 2, 3, 4}, {2, 1, 2, 3}, {3, 2, 1, 2}, {4, 3, 2, 1}}; // Questão B
		// Inserindo os elementos na matriz B
	//float b[TAM] = {10, 7, 6, 5};
	
		// Inserindo os elementos na matriz A
	//float a[TAM][TAM] = {{1, -0.25, -0.25, 0}, {-0.25, 1, 0, -0.25}, {-0.25, 0, 1, -0.25}, {0, -0.25, 0, 1}}; // Questão C
		// Inserindo os elementos na matriz B
	//float b[TAM] = {0, 0, 0.25, 0.25};
	
		// Inserindo os elementos na matriz A
	//float a[TAM][TAM] = {{4, 1, 1, 1}, {2, -8, 1, -1}, {1, 2, -5, 1}, {1, 1, 1, -4}}; // Questão D
		// Inserindo os elementos na matriz B
	//float b[TAM] = {7, -6, -1, -1};
	
		// Inserindo os elementos na matriz A
	float a[TAM][TAM] = {{4, 3, 2, -1}, {1, 2, 3, 4}, {1, -1, -1, -1}, {1, 1, 1, 1}}; // Questão E
		// Inserindo os elementos na matriz B
	float b[TAM] = {5, 26, -7, 33};
	
	printf("Matriz A:\n");
	for(i = 0; i < TAM; i++){
		for(j = 0; j < TAM; j++){
			printf("%.2f\t", a[i][j]);
		}
		printf("\n");
	}

	printf("\n\nMatriz B:\n");
	for(i = 0; i < TAM; i++){
		printf("%.2f\t", b[i]);
	}

	printf("\n\nVetor X:\n");
	for(i = 0; i < TAM; i++){
		printf("%.2f\t", x0[i]);
	}

	while(!(pare)){
		printf("\n\n");
		for(i = 0; i < TAM; i++){
			for(j = 0; j < i; j++){ //calculando o valor do primeiro somatório.
				soma = soma + a[i][j] * x0[j];	
			}
		
			for(j = i + 1; j < TAM; j++){ //calculando o valor do somatório.
				soma2 = soma2 + a[i][j]*x0[j];
			}
			x[i] = (b[i] - soma - soma2) / a[i][i];
			printf("x%i = %.2f\n", i, x[i]);
			soma = 0;
			soma2 = 0;
		}
	
		for(t = 0; t < TAM; t++){
			x2[t] = x[t] - x0[t];	
		}
		norma = (sqrt((x2[0] * x2[0]) + (x2[1] * x2[1]) + (x2[2] * x2[2]))) / sqrt((x[0] * x[0]) + (x[1] * x[1]) + (x[2] *x [2]));
		printf ("Norma = %f", norma);
		
		if(norma <= 2) {
			pare = true;
		} else {
			for(t = 0; t < TAM; t++){
				x0[t] = x[t];	
			}
			k++;
		}
	}
}