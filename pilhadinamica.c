#include <stdio.h>
#include <stdlib.h>
#include "pilhadin.h"


int main(){
    int escolha;
    do{
        menu();
        scanf("%d", &escolha);
        switch(escolha){
            case 1:{
                printf("\nDigite o numero a ser inserido: ");
                int val;
                scanf("%d", &val);
                inserir(val);
                break;
            }
            case 2:{
                printf("\nDigite o numero a ser removido: ");
                int val;
                scanf("%d", &val);
                remover(val);
                break;
            }
            case 3:{
                printf("\nDigite o numero a ser buscado: ");
                int val;
                scanf("%d", &val);
                busca(val);
                break;
            }
            case 4:{
                printlista();
                break;
            }
            case 5: {
                finalizar();
                break;
            }
        }
    } while(escolha != 5);
    return 0;
}