#include <stdio.h>
#include <stdlib.h>


typedef struct Node {    // Estrutura para representar um nó na fila
    int data;            // Dado armazenado no nó
    struct Node* next;   // Ponteiro para o próximo nó
} Node;

// Estrutura para representar a fila
typedef struct Queue {
    Node* front;         // Ponteiro para o nó da frente da fila
    Node* rear;          // Ponteiro para o nó de trás da fila
} Queue;

// Função para criar e inicializar uma nova fila
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));  // Aloca memória para a fila
    if (q == NULL) {                           // Verifica se a alocação foi bem-sucedida
        printf("Falha na alocação de memória para a fila.\n");
        return NULL;
    }
    q->front = q->rear = NULL;  // Inicializa a fila vazia
    return q;
}

// Função para inserir um novo elemento na fila
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Aloca memória para o novo nó
    if (newNode == NULL) {                        // Verifica se a alocação foi bem-sucedida
        printf("Falha na alocação de memória para o novo nó.\n");
        return;
    }
    newNode->data = value;     // Atribui o valor ao nó
    newNode->next = NULL;      // O próximo nó é NULL, pois será o último na fila
    if (q->rear == NULL) {     // Se a fila estiver vazia, o novo nó é tanto o front quanto o rear
        q->front = q->rear = newNode;
    } else {                   // Caso contrário, adiciona o novo nó ao final da fila
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Função para remover o elemento da frente da fila
int dequeue(Queue* q) {
    if (q->front == NULL) {    // Verifica se a fila está vazia
        printf("Fila está vazia.\n");
        return -1;             // Retorna -1 se a fila estiver vazia
    }
    Node* temp = q->front;     // Guarda o nó da frente para liberar memória depois
    int data = temp->data;     // Salva o dado do nó a ser removido
    q->front = q->front->next; // Avança o ponteiro front para o próximo nó
    if (q->front == NULL) {    // Se a fila ficar vazia, rear também deve ser NULL
        q->rear = NULL;
    }
    free(temp);                // Libera a memória do nó removido
    return data;               // Retorna o dado removido
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* q) {
    return q->front == NULL;   // Retorna 1 (verdadeiro) se a fila estiver vazia, caso contrário, 0 (falso)
}

// Função para contar o número de elementos na fila
int countQueueElements(Queue* q) {
    int count = 0;              // Inicializa o contador de elementos
    Node* temp = q->front;      // Começa pelo primeiro nó
    while (temp != NULL) {      // Percorre a fila até o último nó
        count++;                // Incrementa o contador para cada nó
        temp = temp->next;      // Move para o próximo nó
    }
    return count;               // Retorna o número total de elementos
}

// Função para limpar todos os elementos da fila, liberando a memória
void clearQueue(Queue* q) {
    Node* temp;
    while (q->front != NULL) {   // Enquanto houver nós na fila
        temp = q->front;         // Armazena o nó atual
        q->front = q->front->next; // Avança o ponteiro front
        free(temp);              // Libera a memória do nó atual
    }
    q->rear = NULL;              // Define rear como NULL, pois a fila está vazia
    printf("Fila esvaziada e memória liberada.\n");
}

// Função para imprimir todos os elementos da fila
void printQueue(Queue* q) {
    if (isEmpty(q)) {          // Verifica se a fila está vazia
        printf("A fila está vazia.\n");
        return;
    }
    Node* temp = q->front;     // Começa pelo primeiro nó
    printf("Elementos da fila: ");
    while (temp != NULL) {     // Percorre a fila até o último nó
        printf("%d ", temp->data);  // Imprime o dado de cada nó
        temp = temp->next;          // Move para o próximo nó
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();  // Cria e inicializa a fila
    enqueue(q, 10);            // Insere 10 na fila
    enqueue(q, 20);            // Insere 20 na fila
    enqueue(q, 30);            // Insere 30 na fila
    printQueue(q);             // Imprime os elementos da fila

    printf("Número de elementos na fila: %d\n", countQueueElements(q));  // Conta os elementos

    printf("Desenfileirado: %d\n", dequeue(q));  // Remove o primeiro elemento
    printQueue(q);             // Imprime os elementos da fila
    printf("Desenfileirado: %d\n", dequeue(q));  // Remove o próximo elemento
    printQueue(q);             // Imprime os elementos da fila
    printf("Desenfileirado: %d\n", dequeue(q));  // Remove o último elemento
    printQueue(q);             // Imprime os elementos da fila

    clearQueue(q);             // Limpa a fila e libera a memória
    free(q);                   // Libera a memória da estrutura da fila
    return 0;
}
