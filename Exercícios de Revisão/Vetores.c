#include <stdio.h>

int main() {
    int n;
    int i, temp;
    int vetor[n];
    
    printf("Quantos elementos o vetor terá?\n");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        vetor[i] = i;
    }
   
    for (i = 0; i < n/2; i++) {
        temp = vetor[i];
        vetor[i] = vetor[(n - 1) - i];
        vetor[(n - 1) - i] = temp;
    }

    printf("Vetor invertido:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
