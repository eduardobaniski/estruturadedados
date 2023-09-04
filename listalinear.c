#include <stdio.h>
#define TAM 4


int lista[TAM], cont = 0;

void order(){
    int aux, aux2;
    for(aux = cont - 1; aux>0; aux--){
        if(lista[aux] < lista[aux - 1]){
            aux2 = lista[aux - 1];
            lista[aux - 1] = lista[aux];
            lista[aux] = aux2;
        }
        else{
            return;
        }
    }
}
void insereLista(int valor){
    if(cont != TAM){
        int aux;
        for(aux = 0;aux < cont; aux++){
            if(lista[aux] == valor){
                printf("\nElemento nao inserido - o elemento ja esta na lista");
                return;
            }
        }
        lista[cont] = valor;
        cont++;
        order();
    }
    else{
        printf("\nElemento nao inserido - vetor cheio");
        return;
    }
}

int buscaLista(int valor){
    int aux;
    if(cont != 0){
        for(aux = 0; aux < cont; aux++){
            if(valor == lista[aux]){
                return aux;
            }
            else if(lista[aux] > valor){
                return -1;
            }
        }
    }
    return -1;
}
void removeLista(int valor){
    if(cont != 0){
        int pos = buscaLista(valor);
        if(pos != -1){
            int aux;
            for(aux = pos; aux < cont;aux++){
                lista[aux] = lista[aux + 1];
            }
            printf("\nElemento removido");
            cont--;
            return;
        }
        else{
            printf("\nElemento nao encontrado");
            return;
        }
    }
    printf("\nLista vazia");
}

void imprime(){
    if(cont != 0){
        int aux;
        for(aux = 0; aux < cont; aux++){
            printf("\n%d. %d", aux, lista[aux]);
        }
        return;
    }
    else{
        printf("\nLista vazia");
    }
}

void menu(){
    printf("\nLista - operacoes");
    printf("\n1. Inserir elemento");
    printf("\n2. Remover elemento");
    printf("\n3. Buscar elemento na lista");
    printf("\n4. Imprimir lista");
    printf("\n5. Sair do programa");
    printf("\n Digite sua escolha: ");
}

int main(){
    int escolha = 0;
    while(escolha != 5){
        menu();
        scanf("%d", &escolha);
        switch(escolha){
            case 1:{
                printf("\nDigite o valor: ");
                int val;
                scanf("%d", &val);
                insereLista(val);
                break;
            }
            case 2:{
                if(cont != 0){
                    printf("\nDigite o valor: ");
                    int val;
                    scanf("%d", &val);
                    removeLista(val);
                    break;
                }
                else printf("\nLista vazia\n");
                break;
            }
            case 3:{
                if(cont != 0){
                    printf("\nDigite o valor: ");
                    int val, pos;
                    scanf("%d", &val);
                    pos = buscaLista(val);
                    if(pos != -1){
                        printf("\nValor %d encontrado na posicao %d", val, pos);
                        break;
                    }
                    else{
                        printf("\nValor nao encontrado na lista");
                        break;
                    }
                }
                else printf("\nLista vazia");
                break;
            }
            case 4:{
                if(cont != 0){
                    imprime();
                } else printf("\nLista vazia");
                break;
            }
        }
    }
    return 0;
}


