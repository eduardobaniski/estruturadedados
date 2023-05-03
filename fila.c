
//P0221042023 - Prática 02 FILA
//Estrutura de Dados I - Prof. Albino Szesz Jr.
//Aluno Carlos Eduardo Baniski RA: 22008126

#include <stdio.h>
#define TAM 3

int fila[TAM], frente = 0, fim = 0, cont = 0;

void insereFila(int valor){
    if(cont < TAM){
        if(cont == 0){  //essa forma não é a mais eficiente, eu precisei fazer assim pois senao o primeiro elemento fica como 0
            fila[fim] = valor;
            cont++;
            printf("\nElemento introduzido no final da fila");
            return;
        }
        fim++;
        if(fim == TAM){  
            fim = 0;
        }
    fila[fim] = valor;
    cont++;
    printf("\nElemento introduzido no final da fila");
    }
    else printf("\nFila cheia - elemento nao introduzido");
}

void removeFila(){
    if(cont > 0){
        printf("\nO elemento %d foi removido da fila", fila[frente]);
        cont--;
        if(frente == TAM -1){
            frente = 0;
        }
        else{
            frente++;
        }
    }
    else{
        printf("\nFila vazia - nenhum elemento removido");
    }
}

void inicioFila(){
    if(cont > 0){
        printf("\nO elemento na frente da fila e %d", fila[frente]);
    }
    else printf("\nFila vazia - nao ha elemento no comeco");
}

void imprime(){
    if(cont > 0){
        int cont2 = frente;
        for(int i = 0; i < cont; i++){
            if(cont2 == TAM){
                cont2 = 0;
            }
            printf("\n%d. %d", i+1, fila[cont2]);
            cont2++;
        }
    }
    else printf("\nFila vazia");
}

int main(){
    int escolha = 0;
    do{
        printf("\nMenu da fila");
        printf("\n1. Adicionar elemento na fila");
        printf("\n2. Remover elemento da fila");
        printf("\n3. Consultar primeiro elemento da fila");
        printf("\n4. Imprimir a fila");
        printf("\n5. Sair");
        printf("\nDigite sua escolha: ");
        scanf("%d", &escolha);

        switch(escolha){
            case 1:{
                int elem;
                printf("\nDigite o elemento a ser adicionado: ");
                scanf("%d", &elem);
                insereFila(elem);
                break;
            }
            case 2:{
                removeFila();
                break;
            }
            case 3:{
                inicioFila();
                break;
            }
            case 4:{
                imprime();
                break;
            }
        }
    }   while(escolha != 5);

    return 0;
}