#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 3  // Capacidade inicial da pilha

int* pilha;  // Ponteiro para a pilha
int topo = -1;  // Índice do topo da pilha (-1 indica que a pilha está vazia)
int capacidade = MAX_SIZE;  // Capacidade inicial da pilha

// Função para verificar se a pilha está vazia
int isEmpty() {
    return topo == -1;  // Retorna 1 (verdadeiro) se a pilha estiver vazia, caso contrário, 0 (falso)
}

// Função para expandir dinamicamente a pilha quando a capacidade máxima for atingida
void expandirPilha() {
    capacidade *= 2;  // Dobra a capacidade da pilha
    pilha = (int*)realloc(pilha, capacidade * sizeof(int));  // Redimensiona a pilha
    if (pilha == NULL) {
        printf("Erro ao expandir a pilha!\n");
        exit(1);  // Sai do programa em caso de erro na alocação
    }
    printf("Pilha expandida para capacidade: %d\n", capacidade);
}

// Função para inserir um elemento no topo da pilha (com expansão dinâmica)
void push(int elemento) {
    if (topo == capacidade - 1) {  // Verifica se a pilha está cheia
        expandirPilha();  // Expande a pilha se estiver cheia
    }
    pilha[++topo] = elemento;  // Insere o elemento no topo da pilha
}

// Função para remover e retornar o elemento do topo da pilha
int pop() {
    if (isEmpty()) {  // Verifica se a pilha está vazia
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha[topo--];  // Retorna o elemento do topo e decrementa o índice do topo
    }
}

// Função para retornar o elemento do topo da pilha sem removê-lo
int top() {
    if (isEmpty()) {  // Verifica se a pilha está vazia
        printf("Pilha vazia!\n");
        return -1;
    } else {
        return pilha[topo];  // Retorna o elemento do topo
    }
}

// Função para imprimir o conteúdo da pilha
void imprimir() {
    printf("Conteúdo da pilha:\n");
    for (int i = topo; i >= 0; i--) {  // Percorre a pilha do topo até a base
        printf("%d ", pilha[i]);  // Imprime cada elemento
    }
    printf("\n");
}

int main() {
    pilha = (int*)malloc(capacidade * sizeof(int));  // Aloca memória inicial para a pilha

    push(10);  // Insere 10 na pilha
    push(20);  // Insere 20 na pilha
    push(30);  // Insere 30 na pilha
    imprimir();  // Imprime o conteúdo da pilha
    printf("Elemento no topo: %d\n", top());  // Exibe o elemento do topo da pilha
    printf("Elemento removido: %d\n", pop());  // Remove e exibe o elemento do topo da pilha
    imprimir();  // Imprime o conteúdo da pilha após a remoção

    push(40);  // Insere 40 na pilha
    push(50);  // Insere 50 na pilha (causará expansão da pilha)
    imprimir();  // Imprime o conteúdo da pilha após a expansão

    free(pilha);  // Libera a memória alocada para a pilha

    return 0;
}
