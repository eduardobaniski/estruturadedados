#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int Vector[N],comparacoes=0,trocas=0;


void inserir_crescente(){
    int i;
    for(i=0;i<N;i++){
        Vector[i]=i+1;
    }


}
void inserir_decres(){
    int i;
    for(i=N;i>0;i--){
        Vector[N-i]=i;
    }

}
void inserir_aleatorio(){
    int i;
    for(i=0;i<N;i++){
        Vector[i]=rand()%N;

    }

}

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;

}

void CocktailSort(int a[], int n) {
    int swapped = 1;
    int start = 0;
    int end = n - 1;
    

    while (swapped) {
        swapped = 0;

        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = 1;
                trocas++;
                comparacoes++;
            }
        }

        if (!swapped)
            break;

        swapped = 0;

        --end;

        for (int i = end - 1; i >= start; --i)
        {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = 1;
                trocas++;
                comparacoes++;
            }
        }

        ++start;
    }
}

int main()
{
    clock_t tempo_1,tempo_2;
    printf("*CRESCENTE*\n");
    inserir_crescente();
    tempo_1=clock();
    CocktailSort(Vector,N);
    tempo_2=clock() - tempo_1;
    printf("BUBBLE SORT\n");
    printf("CRESCENTE comparacoes: %d | trocas: %d\n",comparacoes,trocas);
    printf("tempo: %f\n",(double)tempo_2/CLOCKS_PER_SEC);

    printf("**DESCRESCENTE***\n");
    inserir_decres();
    tempo_1=clock();
    CocktailSort(Vector,N);
    tempo_2=clock() - tempo_1;
    printf("BUBBLE SORT\n");
    printf("DECRESCENTE comparacoes: %d | trocas: %d\n",comparacoes,trocas);
    printf("tempo: %f\n",(float)tempo_2/CLOCKS_PER_SEC);

    printf("****ALEATORIO****\n");
    inserir_aleatorio();
    tempo_1=clock();
    CocktailSort(Vector,N);
    tempo_2=clock() - tempo_1;
    printf("BUBBLE SORT\n");
    printf("ALEATORIO comparacoes: %d | trocas: %d\n",comparacoes,trocas);
    printf("tempo: %f\n",(float)tempo_2/CLOCKS_PER_SEC);

    return 0;
}