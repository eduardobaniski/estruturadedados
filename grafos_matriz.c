#include <stdio.h>
#include <stdlib.h>
#define TAM 3

int vetor[TAM]; //tamanho de vertices
int cont = 0;
int matriz_adj[TAM][TAM];

void inicializa(){
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            matriz_adj[i][j] = 0;
        }
    }
}

void insereVertice(int val){
    //Não repetir vértice
    if(cont == TAM){
        printf("\nGrafo cheio");
        return;
    }
    for(int i=0; i < cont; i++){
        if(vetor[i] == val){
            printf("\nElemento repetido");
            return;
        }
    }
    vetor[cont] = val;
    cont++;

}
void insereAresta(int origem, int destino){
    //Não repetir aresta
    //Precisa verificar se existe vertice 
   int v1 = -1, v2 = -1;
   for(int i = 0; i < cont && (v1 == -1 || v2 == -1); i++){ //Procurar vertice
        if(vetor[i] == origem){
            v1 = i;
        }
        if(vetor[i] == destino){
            v2 = i;
        }
    }
   if(v2 == -1 || v1 == -1){
    printf("\nVertice nao encontrado");
    return;
   }

   if(matriz_adj[v1][v2] == 1){ //Verifica se já existe aresta
        printf("\nJa existe aresta");
        return;
   }

    matriz_adj[v1][v2] = 1;
    printf("\nAresta inserida");
}

void removeAresta(int origem, int destino){
   int v1 = -1, v2 = -1;
   for(int i = 0; i < cont && (v1 == -1 || v2 == -1); i++){ //Procurar vertice
    if(vetor[i] == origem)
        v1 = i;
    if(vetor[i] == destino)
        v2 = i;
   }
   if(v2 == -1 || v1 == -1){
    printf("\nVertice nao encontrado");
    return;
   }

   if(matriz_adj[v1][v2] == 1){ //Verifica se existe aresta
        matriz_adj[v1][v2] = 0;
        printf("\nAresta removida");
        return;
   }
   printf("\nAresta nao existe");
}

void haAresta(int origem, int destino){
   int v1 = -1, v2 = -1;
   for(int i = 0; i < cont && (v1 == -1 || v2 == -1); i++){ //Procurar vertice
    if(vetor[i] == origem)
        v1 = i;
    if(vetor[i] == destino)
        v2 = i;
   }
   if(v2 == -1 || v1 == -1){
    printf("Vertice nao encontrado");
    return;
   }

   if(matriz_adj[v1][v2] == 1){ //Verifica se já existe aresta
        printf("\nAresta encontrada ligando vertices");
        return;
   }
   printf("\nNao ha aresta ligando os vertices");

}

void imprimeGrafo(){
    for(int i=0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            printf("%d ", matriz_adj[i][j]);
        }
        printf("\n");
    }
}

void menu(){
    printf("\nGRAFOS EM MATRIZES");
    printf("\n1. Inserir vertice");
    printf("\n2. Inserir Aresta");
    printf("\n3. Remover Aresta");
    printf("\n4. Imprimir grafo");
    printf("\n5. Procurar se ha aresta entre dois vertices");
    printf("\n6. Sair");
    printf("\nEscolha: ");
}