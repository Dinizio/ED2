/*
O código abaixo apresenta a implementação de uma lista linear.

Para esse exemplo, faça:
- Implemente funções adicionais como buscar(int elemento) para encontrar a posição de um elemento na lista.
ou 
- Adicione métodos para inverter a lista, encontrar o máximo/mínimo, ou ordenar a lista.
*/

#include <stdio.h>
#define MAX_SIZE 10

int lista[MAX_SIZE];
int tamanho = 0;

void inserir(int elemento) {
    if (tamanho < MAX_SIZE) {
        lista[tamanho++] = elemento;
    } else {
        printf("Lista cheia!\n");
    }
}

void remover(int index) {
    if (index < 0 || index >= tamanho) {
        printf("Índice inválido!\n");
    } else {
        for (int i = index; i < tamanho - 1; i++) {
            lista[i] = lista[i + 1];
        }
        tamanho--;
    }
}

void imprimir() {
    printf("Elementos da lista:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

void Busca(int x) {
    int i, aux;
    aux = 0;
    for(i= 0; i< MAX_SIZE; i++){
        if(lista[i]==x){
            printf("Seu elemento está na %d° posição\n", i);
            aux++;
        }
    }
    
    if(aux==0){
        printf("Seu elemento não está aqui\n" );
    }
    
      }

int main() {
    inserir(10);
    inserir(20);
    inserir(30);
    Busca(20);
    imprimir();
    remover(1);
    Busca(20);
    imprimir();
    return 0;
}
