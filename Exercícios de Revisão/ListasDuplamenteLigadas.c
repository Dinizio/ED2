#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó na lista duplamente ligada
typedef struct Node {
    int data;               // Dado armazenado no nó
    struct Node* next;      // Ponteiro para o próximo nó
    struct Node* prev;      // Ponteiro para o nó anterior
} Node;

Node* head = NULL; // Ponteiro para o início da lista (cabeça da lista)

// Função para inserir um novo nó no início da lista
void insertFront(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Aloca memória para o novo nó
    newNode->data = value;                        // Atribui o valor ao novo nó
    newNode->next = head;                         // O próximo nó do novo nó é o atual início da lista
    newNode->prev = NULL;                         // Como é o primeiro nó, não tem nó anterior
    if (head != NULL)
        head->prev = newNode;                     // Se a lista não estiver vazia, ajusta o ponteiro prev do nó atual
    head = newNode;                               // O novo nó se torna o início da lista
}

// Função para deletar um nó específico da lista
void deleteNode(Node* node) {
    if (node == head)
        head = node->next;                       // Se o nó a ser deletado for o primeiro, atualiza o início da lista
    if (node->next != NULL)
        node->next->prev = node->prev;           // Ajusta o ponteiro prev do próximo nó
    if (node->prev != NULL)
        node->prev->next = node->next;           // Ajusta o ponteiro next do nó anterior
    free(node);                                  // Libera a memória do nó deletado
}

// Função para imprimir todos os valores da lista
void printList() {
    Node* temp = head;                           // Começa do início da lista
    while (temp != NULL) {
        printf("%d ", temp->data);               // Imprime o valor do nó atual
        temp = temp->next;                       // Move para o próximo nó
    }
    printf("\n");
}

// Função para buscar um valor específico na lista
void searchValue(int value) {
    Node* temp = head;  // Começa do início da lista

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Valor %d encontrado.\n", value);
            if (temp->prev != NULL)
                printf("Valor anterior: %d\n", temp->prev->data);
            else
                printf("Não há valor anterior.\n");

            if (temp->next != NULL)
                printf("Próximo valor: %d\n", temp->next->data);
            else
                printf("Não há próximo valor.\n");
            return;
        }
        temp = temp->next;  // Move para o próximo nó
    }

    printf("Valor %d não encontrado na lista.\n", value);
}

int main() {
    int n, value, searchVal;

    printf("Quantos valores deseja inserir? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Digite o valor para inserir: ");
        scanf("%d", &value);
        insertFront(value);
    }

    printf("Lista atual: ");
    printList();

    printf("Digite o valor para buscar: ");
    scanf("%d", &searchVal);

    searchValue(searchVal);

    return 0;
}
