
#include <stdio.h>

int main() {
    int n;
    printf("Qual será o tamanho da sua Matriz Quadrada?:\n");
    scanf("%d", &n);
    int matriz[n][n];
    int i, j, soma = 0;

    printf("Insira os elementos da sua matriz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
            if (i == j) {
                soma += matriz[i][j];
            }
        }
    }

    printf("Soma dos elementos da diagonal principal: %d\n", soma);
    return 0;
}
