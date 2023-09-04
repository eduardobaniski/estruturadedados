#include <stdlib.h>
#include <stdio.h>
//Arquivo de funções de lista dinâmica (Linked List)
typedef struct {
    void *prox;
    int data;
} no;

no *HEAD = NULL;


void inserir(int val){      //Aloca um novo elemento não repetido no final da lista
    no *newNo = malloc(sizeof(no));   
    if(newNo == NULL){                
        return;
    }
    newNo->prox = NULL;               
    newNo->data = val;
    if(HEAD == NULL){               
        HEAD = newNo;                 
        return;                     
    }
    else{ 
        no *busca = HEAD;
        while(busca != NULL){
            if(busca->data == val){
                printf("\nValor ja presente na lista. ");
                return;
            }
            busca=busca->prox;
        }
        if (HEAD->data > val) {
            newNo->prox = HEAD;
            HEAD = newNo;
            printf("\nElemento adicionado.");
            return;
        }
        no *anterior = HEAD;      
        no *atual = HEAD;
        while (atual != NULL && val > atual->data) {    //esse insertionsort me complicou, deve estar funcionando
            if(atual->prox == NULL){
                atual->prox = newNo;
                return;
            }
            anterior = atual;
            atual = atual->prox;
        }
        anterior->prox = newNo;
        newNo->prox = atual;
        printf("\nElemento adicionado.");
        return;
    }
}


void remover(int val) {     //Percorre a lista em busca de um valor, se encontrado
    if (HEAD == NULL) {     //libera ele para a memória
        printf("\nLista vazia.");
        return;
    }

    no *busca = HEAD, *anterior = NULL;
    do {
        if (busca->data == val) {
            if (anterior != NULL) {
                anterior->prox = busca->prox;
            } else {
                HEAD = busca->prox;
            }
            free(busca);
            printf("\nValor removido da lista.");
            return;
        }
        anterior = busca;
        busca = busca->prox;
    } while (busca != NULL);
    
    printf("\nValor nao encontrado na lista.");
}


void busca(int val){    //Percorre a lista procurando um valor
    no *busca = HEAD;
    int count = 1;
    do {
        if(busca->data == val){
            printf("\nValor encontrado na %d posicao.", count);
            return;
        }
        count++;
        busca = busca->prox;   
    } while(busca != NULL);

    printf("\nO valor nao foi encontrado.");
}

void printlista(){  //Printa toda a lista
    if(HEAD == NULL){
        printf("\nLista Vazia.");
        return;
    }
    no *ptr = HEAD;
    do{
        printf("%d -> ", ptr->data);
        ptr = ptr->prox;
    } while(ptr != NULL);
    printf("\n");
}

void finalizar(){   //Libera toda a memória após a execução do programa
    if(HEAD == NULL){
        return;
    }
    no *end = HEAD;
    do{
        end = end->prox;
        free(HEAD);
        HEAD = end;
    } while(end != NULL);
}

void menu(){
    printf("\nLISTA ENCADEADA (LINKED LIST)");
    printf("\n1. Adicionar elemento");
    printf("\n2. Remover elemento");
    printf("\n3. Buscar elemento");
    printf("\n4. Printar lista");
    printf("\n5. Sair");
    printf("\nEscolha: ");
}

