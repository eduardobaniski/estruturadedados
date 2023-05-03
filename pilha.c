#include <stdio.h>
#define TAM 4

void push(int a);
void pop();
void topoPilha();
void imprimir();
void menu();

int pilha[TAM], topo = -1;

int main(){
    int escolha = 0;
    while(escolha != 5){
        menu();
        scanf("%d", &escolha);
        printf("\n");
        switch (escolha)
        {
        case 1:
            printf("\nDigite o elemento a ser adicionado na pilha: ");
            int newElemento;
            scanf("%d", &newElemento);
            push(newElemento);
            break;
        case 2:
            pop();
            break;
        case 3:
            topoPilha();
            break;
        case 4:
            imprime();
        
        default:
            break;
        }
        printf("\n");
    }
}

void imprime(){
    if(topo != -1){
        printf("Os elementos presentes na pilha sao:");
        for(int i = topo; i > -1; i--){
            printf("\n%d. %d", i + 1, pilha[i]);
        }
    }
    else
        printf("Pilha vazia");
}

void topoPilha(){
    if(topo != -1){
        printf("O elemento no topo da pilha e: %d", pilha[topo]);
    }
    else
        printf("Pilha vazia");
}

void pop(){
    if(topo != -1){
        topo--;
        printf("Elemento no topo da pilha removido.");
    }
    else{
        printf("Pilha vazia");
    }
}

void push(int a){
    if(topo < TAM - 1){
        topo++;
        pilha[topo] = a;
        printf("O elemento %d foi adicionado ao topo da pilha", a);
    }
    else{
        printf("Pilha cheia");
    }
}

 void menu(){
    printf("\nOpcoes da pilha:");
    printf("\n1. Adicionar elemento na pilha (push)");
    printf("\n2. Remover valor da pilha (pop)");
    printf("\n3. Consultar valor no topo da pilha");
    printf("\n4. Consultar pilha inteira");
    printf("\n5. Sair do programa");
    printf("\nDigite sua escolha: ");
 }