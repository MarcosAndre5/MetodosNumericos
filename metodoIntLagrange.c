#include <stdio.h>
#include <stdlib.h>

#define TAM 4

int main(){
	int i, j;
	float x[TAM] = {0.1, 0.4, 0.7, 1};
	float y[TAM] = {2.31, 3.36, 4.59, 6};
	float xinterpol = 0.2;
	float yinterpolado = 0, produtosNum = 0, produtosDen = 0;

	printf("\tMétodo de Interpolação de Lagrange.\n");

	for(i = 0; i < TAM; i++){
		produtosNum = 1;
		produtosDen = 1;
		for(j = 0; j < TAM; j++){
			if(i != j){
				produtosNum = produtosNum * (xinterpol - x[j]);
				produtosDen = produtosDen * (x[i] - x[j]);
			}
		}
		yinterpolado = yinterpolado + (produtosNum / produtosDen) * y[i];
	}

	printf("\nO Y interpolado é: %f\n\n", yinterpolado);

	return 0;
}