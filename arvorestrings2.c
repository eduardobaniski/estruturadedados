#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    int qtd;
    char str[40];
    struct no* dir;
    struct no* esq;
} no;

no* raiz = NULL;

void inserir(FILE *f) {
    char palavra[40];
    while (fscanf(f, "%s", palavra) != EOF){

        if (raiz == NULL) {
            no* new = malloc(sizeof(no));
            new->dir = NULL;
            new->esq = NULL;
            new->qtd = 1;
            strcpy(new->str, palavra);
            raiz = new;
        }
        else{
            no* atual = raiz;
            while (1) {
                int cmp = strcmp(atual->str, palavra);
                if (cmp < 0) {
                    if (atual->esq == NULL) {
                        no* new = malloc(sizeof(no));
                        new->dir = NULL;
                        new->esq = NULL;
                        new->qtd = 1;
                        strcpy(new->str, palavra);
                        atual->esq = new;
                        break;
                    } else {
                        atual = atual->esq;
                    }
                } else if (cmp > 0) {
                    if (atual->dir == NULL) {
                        no* new = malloc(sizeof(no));
                        new->dir = NULL;
                        new->esq = NULL;
                        new->qtd = 1;
                        strcpy(new->str, palavra);
                        atual->dir = new;
                        break;
                    } else {
                        atual = atual->dir;
                    }
                } else {
                    atual->qtd++;
                    break;
                }
            }
        }
    }
}

void emOrdem(no* atual) {
    if (atual == NULL) {
        return;
    }
    emOrdem(atual->dir);
    printf("%s - %d vez(es)\n", atual->str, atual->qtd);
    emOrdem(atual->esq);
}

int main() {
    FILE* f = fopen("texto.txt", "r");
    if (f == NULL) {
        printf("Erro com o arquivo. Crie um arquivo chamado texto.txt na mesma pasta\n");
        return 1;
    }

    inserir(f);
    emOrdem(raiz);

    fclose(f);
    return 0;
}
