#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 100000

//  Já peço desculpas previamente, esse
//  código tá uma zona e readaptado um
//  monte de vezes, mas ele funciona pra 
//  calcular o tempo do shaker sort
int Vector[n];
long int trocasBubble, trocasSelection, trocasInsertion, trocasQuick;
long int compBubble, compSelection, compInsertion, compQuick;

long int trocas, comp;
void aleatorio(){
    int i;
    for(i=0; i < n; i++){
        Vector[i] = rand()%n;
        // printf("\n%d", Vector[i]);
    }
}
void crescente(){
    int i;
    for(i=0;i<n;i++){
        Vector[i]=i+1;
    }
}
void swap(int xp, int yp) {
    int temp = xp;
    xp = yp;
    yp = temp;
}

void CocktailSort(int a[], int b) {
    int swapped = 1;
    int start = 0;
    int end = b - 1;

    while (swapped) {
        swapped = 0;

        for (int i = start; i < end; ++i) {
            comp++;
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                trocas++;
                swapped = 1;
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
            }
        }

        ++start;
    }
}
void decrescente(){
    int i;
    for(i=0;i<n;i++){
        Vector[i]=n-i;
    }
}

/*Funcao do algoritmo Bubble Sort */

void BubbleSort(){
     int i,aux,pass=1;
     int sorted=0;

     while(!sorted && pass < n){
          sorted = 1;
          for (i = 0; i<= n-pass-1; i++){
            compBubble++;

              if (Vector[i] > Vector[i+1]){
                  aux = Vector [i+1];
                  Vector [i+1] = Vector [i];
                  Vector [i] = aux;
                  trocasBubble++;
                  sorted = 0;
              
              }
         
          }
          pass = pass +1;

     }
}


/* Funcao do algoritmo Selecion Sort */

void SelectionSort(){
     int current;
     int i,k,aux;

     for (i=0 ; i <= n-2 ; i++){
         current = i;
         for (k=i+1 ; k <= n-1; k++){
            compSelection++;
             if (Vector[current] > Vector [k])
                current = k;
         }
        trocasSelection++;
         aux = Vector [i];
         Vector [i] = Vector [current];
         Vector [current] = aux;
     }
}

/* Funcao do algoritmo InsertionSort */

void InserctionSort (){
     int k,x,i,found;
     int aux;

     for(k=1 ; k<=n-1 ; k++){
        compInsertion++;
         x = Vector[k];
         i = k-1;
         found = 0;
         while (!found && i>=0){
               if(Vector[i] > x){
                trocasInsertion++;
                  aux = Vector [i+1];
                  Vector [i+1] = Vector [i];
                  Vector [i] = aux;
                  i = i-1;
               }
               else
                   found =1;
         }
     }
}



/* Algoritmo para  QuickSort */

int partition(int p,int r){
    int aux,piv,i,j;

    piv=Vector[p];
    i=p-1;
    j=r+1;
    while(1){
        compQuick++;
        do
            j=j-1;
        while(Vector[j]>piv);
        do
            i=i+1;
        while(Vector[i]<piv);
        if(i<j){
            aux=Vector[i];
            Vector[i]=Vector[j];
            Vector[j]=aux;
            trocasQuick++;
        }
        else
            return j;
    }
}

void QuickSort(int p, int r){
    int q;

    if(p<r){
        q=partition(p,r);
        QuickSort(p,q);
        QuickSort(q+1,r);
    }
}

int main(){
//  ALEATORIO
    FILE *f = fopen("resultados.txt", "w");
    printf("******ALEATORIO******");
    aleatorio();
    clock_t start = clock();
    BubbleSort();
    clock_t end = clock();
    float time = (float) (end - start) / CLOCKS_PER_SEC;
    // bubbleEnd = bubbleStart - clock();
    /*printf("\nBubble sort");
    printf("\nN de elementos: %d", n);
    printf("\nTempo: %.5lf", time);
    printf("\nNum de trocas: %d", trocasBubble);
    printf("\nNum de comparacoes: %d", compBubble);
    printf("\n\n");
    fprintf(f, "bubble\n\ntempo: %.5lf", time);
    fprintf(f, "\ncomp: %d", compBubble);
    fprintf(f, "\ntrocas: %d", trocasBubble);
   
    aleatorio();
    start = clock();
    InserctionSort();
    end = clock();
    time = (float) (end - start) / CLOCKS_PER_SEC;
    printf("\nInsertion sort");
    printf("\nN de elementos: %d", n);
    printf("\nTempo: %.5lf", time);
    printf("\nNum de trocas: %d", trocasInsertion);
    printf("\nNum de comparacoes: %d", compInsertion);
    printf("\n\n");
    fprintf(f, "\n\ninsertion\n\ntempo: %.5lf", time);
    fprintf(f, "\ncomp: %d", compInsertion);
    fprintf(f, "\ntrocas: %d", trocasInsertion);
   
    aleatorio();
    start = clock();
    SelectionSort();
    end = clock();
    time = (float) (end - start) / CLOCKS_PER_SEC;
    printf("\nSelection sort");
    printf("\nN de elementos: %d", n);
    printf("\nTempo: %.5lf", time);
    printf("\nNum de trocas: %d", trocasSelection);
    printf("\nNum de comparacoes: %d", compSelection);
    printf("\n\n");
    fprintf(f, "\n\nselection\n\ntempo: %.5lf", time);
    fprintf(f, "\ncomp: %d", compSelection);
    fprintf(f, "\ntrocas: %d", trocasSelection);
    
    aleatorio();
    start = clock();
    QuickSort(0, n-1);
    end = clock();
    time = (float) (end - start) / CLOCKS_PER_SEC;
    printf("\nQuick sort");
    printf("\nN de elementos: %d", n);
    printf("\nTempo: %.5lf", time);
    printf("\nNum de trocas: %d", trocasQuick);
    printf("\nNum de comparacoes: %d", compQuick);
    printf("\n\n");
    fprintf(f, "\n\nquick\n\ntempo: %.5lf", time);
    fprintf(f, "\ncomp: %d", compQuick);
    fprintf(f, "\ntrocas: %d", trocasQuick);

    trocasBubble =0, trocasInsertion=0, trocasQuick=0, trocasSelection=0;
    compBubble=0, compInsertion=0,compQuick=0,compSelection=0;
    // getchar();
//  CRESCENTE
    fprintf(f, "\n\nCRESCENTE\n\n");
    printf("******CRESCENTE******");
    crescente();
    start = clock();
    BubbleSort();
    end = clock();
    time = (float) (end - start) / CLOCKS_PER_SEC;
    // bubbleEnd = bubbleStart - clock();
    printf("\nBubble sort");
    printf("\nN de elementos: %d", n);
    printf("\nTempo: %.5lf", time);
    printf("\nNum de trocas: %d", trocasBubble);
    printf("\nNum de comparacoes: %d", compBubble);
    printf("\n\n");
    fprintf(f, "bubble\n\ntempo: %.5lf", time);
    fprintf(f, "\ncomp: %d", compBubble);
    fprintf(f, "\ntrocas: %d", trocasBubble);
   
    crescente();
    start = clock();
    InserctionSort();
    end = clock();
    time = (float) (end - start) / CLOCKS_PER_SEC;
    printf("\nInsertion sort");
    printf("\nN de elementos: %d", n);
    printf("\nTempo: %.5lf", time);
    printf("\nNum de trocas: %d", trocasInsertion);
    printf("\nNum de comparacoes: %d", compInsertion);
    printf("\n\n");
    fprintf(f, "\n\ninsertion\n\ntempo: %.5lf", time);
    fprintf(f, "\ncomp: %d", compInsertion);
    fprintf(f, "\ntrocas: %d", trocasInsertion);
    
    crescente();
    start = clock();
    SelectionSort();
    end = clock();
    time = (float) (end - start) / CLOCKS_PER_SEC;
    printf("\nSelection sort");
    printf("\nN de elementos: %d", n);
    printf("\nTempo: %.5lf", time);
    printf("\nNum de trocas: %d", trocasSelection);
    printf("\nNum de comparacoes: %d", compSelection);
    printf("\n\n");
    fprintf(f, "\n\nselection\n\ntempo: %.5lf", time);
    fprintf(f, "\ncomp: %d", compSelection);
    fprintf(f, "\ntrocas: %d", trocasSelection);
    
    crescente();
    start = clock();
    QuickSort(0, n-1);
    end = clock();
    time = (float) (end - start) / CLOCKS_PER_SEC;
    printf("\nQuick sort");
    printf("\nN de elementos: %d", n);
    printf("\nTempo: %.5lf", time);
    printf("\nNum de trocas: %d", trocasQuick);
    printf("\nNum de comparacoes: %d", compQuick);
    printf("\n\n");
    fprintf(f, "\n\nquick\n\ntempo: %.5lf", time);
    fprintf(f, "\ncomp: %d", compQuick);
    fprintf(f, "\ntrocas: %d", trocasQuick);

    trocasBubble =0, trocasInsertion=0, trocasQuick=0, trocasSelection=0;
    compBubble=0, compInsertion=0,compQuick=0,compSelection=0;
    // getchar();
//  DECRESCENTE
    fprintf(f, "\n\nDECRESCENTE\n\n");
    printf("******DECRESCENTE******");
    decrescente();
    start = clock();
    BubbleSort();
    end = clock();
    time = (float) (end - start) / CLOCKS_PER_SEC;
    // bubbleEnd = bubbleStart - clock();
    printf("\nBubble sort");
    printf("\nN de elementos: %d", n);
    printf("\nTempo: %.5lf", time);
    printf("\nNum de trocas: %d", trocasBubble);
    printf("\nNum de comparacoes: %d", compBubble);
    printf("\n\n");
    fprintf(f, "bubble\n\ntempo: %.5lf", time);
    fprintf(f, "\ncomp: %d", compBubble);
    fprintf(f, "\ntrocas: %d", trocasBubble);
   
    decrescente();
    start = clock();
    InserctionSort();
    end = clock();
    time = (float) (end - start) / CLOCKS_PER_SEC;
    printf("\nInsertion sort");
    printf("\nN de elementos: %d", n);
    printf("\nTempo: %.5lf", time);
    printf("\nNum de trocas: %d", trocasInsertion);
    printf("\nNum de comparacoes: %d", compInsertion);
    printf("\n\n");
    fprintf(f, "\n\ninsertion\n\ntempo: %.5lf", time);
    fprintf(f, "\ncomp: %d", compInsertion);
    fprintf(f, "\ntrocas: %d", trocasInsertion);
    
    decrescente();
    start = clock();
    SelectionSort();
    end = clock();
    time = (float) (end - start) / CLOCKS_PER_SEC;
    printf("\nSelection sort");
    printf("\nN de elementos: %d", n);
    printf("\nTempo: %.5lf", time);
    printf("\nNum de trocas: %d", trocasSelection);
    printf("\nNum de comparacoes: %d", compSelection);
    printf("\n\n");
    fprintf(f, "\n\nselection\n\ntempo: %.5lf", time);
    fprintf(f, "\ncomp: %d", compSelection);
    fprintf(f, "\ntrocas: %d", trocasSelection);
    
    decrescente();
    start = clock();
    QuickSort(0, n-1);
    end = clock();
    time = (float) (end - start) / CLOCKS_PER_SEC;
    printf("\nQuick sort");
    printf("\nN de elementos: %d", n);
    printf("\nTempo: %.5lf", time);
    printf("\nNum de trocas: %d", trocasQuick);
    printf("\nNum de comparacoes: %d", compQuick);
    printf("\n\n");
    fprintf(f, "\n\nquick\n\ntempo: %.5lf", time);
    fprintf(f, "\ncomp: %d", compQuick);
    fprintf(f, "\ntrocas: %d", trocasQuick);
    fclose(f);

    */

    aleatorio();
    start = clock();
    CocktailSort(Vector, n);
     end = clock();
     time = (float) (end - start) / CLOCKS_PER_SEC;
    printf("\naleatorio: %.5lf", time);
    printf("trocas %d", trocas);
    printf("comp %d", comp);
    trocas=0;comp=0;
    crescente();
     start = clock();
    CocktailSort(Vector, n);
     end = clock();
     time = (float) (end - start) / CLOCKS_PER_SEC;
    printf("\ncrescente: %.5lf", time);
    printf("trocas %d", trocas);
    printf("comp %d", comp);
    decrescente();
    trocas=0;comp=0;    
     start = clock();
    CocktailSort(Vector, n);
     end = clock();
     time = (float) (end - start) / CLOCKS_PER_SEC;
    printf("\ndecresc: %.5lf", time);
    printf("trocas %d", trocas);
    printf("comp %d", comp);
}