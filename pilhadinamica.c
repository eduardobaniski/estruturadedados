#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int data;
    no *prox;
} no;
// Iniciando o ponteiro do topo
no *topo = NULL, *first = NULL;

void push(int val)
{
    no *newno = malloc(sizeof(no));
    if (newno == NULL)
    {
        printf("\nNao foi possivel adicionar elemento - memoria cheia.");
        return;
    }
    if(first == NULL){
        first = newno;
    }
    newno->data = val;
    newno->prox = NULL;
    topo->prox = newno;
    topo = newno;
}

void pop()
{
    if (topo == NULL)
    {
        printf("\nPilha vazia, nenhum elemento removido.");
        return;
    }
    
}

int main()
{

    return 0;
}