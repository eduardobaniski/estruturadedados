#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int qtd;
    char str[40];
    struct no *dir, *esq;
} no;

no *raiz = NULL;

void inserir(FILE *f){
    char string[40];
    // fscanf(f, "%s", string);
    while(fscanf(f, "%s", string) != EOF){
        // no *new = malloc(sizeof(no));
        // new->dir = NULL;
        // new->esq = NULL;
        // new->qtd = 0;
        if(raiz == NULL){
            no *new = malloc(sizeof(no));
            new->dir = NULL;
            new->esq = NULL;
            new->qtd = 1;
            strcpy(new->str,string);
            raiz = new;
            continue;
        }
        no *atual = raiz;
        while(atual != NULL){
            if(strcmp(atual->str, string) < 0){
                if(atual->esq == NULL){
                    no *new = malloc(sizeof(no));
                    new->dir = NULL;
                    new->esq = NULL;
                    new->qtd = 1;
                    strcpy(new->str,string);
                    atual->esq = new;
                }
                else{
                    atual = atual->esq;
                }
            }
            else if(strcmp(atual->str, string) > 0){
                if(atual->dir == NULL){
                    no *new = malloc(sizeof(no));
                    new->dir = NULL;
                    new->esq = NULL;
                    new->qtd = 1;
                    strcpy(new->str,string);
                    atual->dir = new;
                }
                else{
                    atual = atual->dir;
                }
            }
            else{
                atual->qtd ++;
            }                
        }
    }
}

void emordem(no *atual){
    if(atual == NULL){
        return;
    }
    emordem(atual->esq);
    printf("\n%s - %d vez(es)", atual->str, atual->qtd);
    emordem(atual->dir);
}

int main(){
    FILE *f = fopen("texto.txt", "r");
    
    inserir(f);
    emordem(raiz);
    fclose(f);
    return 0;
}
