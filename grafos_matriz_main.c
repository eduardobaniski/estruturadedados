#include <stdio.h>
#include <stdlib.h>
#include "grafos_matriz.c"

/*
Grafo orientado - direcional
Matriz de incidencia - matriz vertices x arestas
    (V) E1  E2  E3
    A   1   0   1
    B   1   1   0
    C   0   1   1

Matriz de adjacência - matriz vertice x vertice
    Relação de conexões entre vértices
    Pode ser direcional - linhas são vert. de origem e col. são vert. de destino
   (V)  A   B   C
    A   0   1   1
    B   1   0   1
    C   1   1   0
*/

int main(){
    inicializa();
    int escolha = 0;
    while(escolha != 6){
        menu();
        scanf("%d", &escolha);
        switch(escolha){
            case 1:{
                int val;
                printf("\nDigite o valor de nome do vertice: ");
                scanf("%d", &val);
                insereVertice(val);
                break;
            }
            case 2:{
                int or, des;
                printf("\nDigite o vertice de origem: ");
                scanf("%d", &or);
                printf("\nDigite o vertice de destino: ");
                scanf("%d", &des);
                insereAresta(or, des);
                break;
            }
            case 3:{
                int or1, des1;
                printf("\nDigite o vertice de origem: ");
                scanf("%d", &or1);
                printf("\nDigite o vertice de destino: ");
                scanf("%d", &des1);
                removeAresta(or1, des1);
                break;
            }
            case 4:{
                imprimeGrafo();
                break;
            }   
            case 5:{
                int or1, des1;
                printf("\nDigite o vertice de origem: ");
                scanf("%d", &or1);
                printf("\nDigite o vertice de destino: ");
                scanf("%d", &des1);
                haAresta(or1, des1);
                break;
            }   
        }
    }
    return 0;
}