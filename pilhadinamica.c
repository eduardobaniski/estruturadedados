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
    else{
        no *anterior = buscaAnterior();
        free(topo);
        topo = anterior;
        printf("\nPop sucessful, elemento removido e topo retornou ao elemento anterior.");
        return;
    }

}

no *buscaAnterior(){
    no *ptr = first;
    while(1){
        if(ptr->prox == topo){
            return ptr;            
        }
        else{
            ptr = ptr->prox;
        }
    }
}

/*
        O bloco a seguir é uma busca que retorna o endereço do
        elemento, se encontrado(otherwise NULL). Não adianta 
        usar ela aqui, isso pode servir para lista encadeada.

no * busca(int valor){
    no *ptr = first;
    while(ptr != NULL){
        if(ptr->data == valor){
            return ptr;            
        }
        else{
            ptr = ptr->prox;
        }
    }
    return NULL;    
}   */

int main()
{

    return 0;
}