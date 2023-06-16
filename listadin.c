typedef struct {
    void *prox;
    int data;
} no;

no *HEAD = NULL;


void inserir(int val){      //Aloca um novo elemento não repetido no final da lista
    no *new = malloc(sizeof(no));   
    if(new == NULL){                
        return;
    }
    new->prox = NULL;               
    new->data = val;
    if(HEAD == NULL){               
        HEAD = new;                 
        return;                     
    }
    else{                           
        no *busca = HEAD;          
        while(busca->prox != NULL){
            if(busca->data == val){
                printf("\nValor ja presente na lista.");
                return;
            }
            busca=busca->prox;  
        }
        if(busca->data == val){     //tive q repetir esse bloco pq o ultimo elemento dava pau na busca
            printf("\nValor ja presente na lista.");
            return;
        }
        busca->prox = new;
        return;
    }
}


void remover(int val) {     //Percorre a lista em busca de um valor, se encontrado
    if (HEAD == NULL) {     //libera ele para a memória
        printf("\nLista vazia.");
        return;
    }

    no *busca = HEAD, *anterior = NULL;
    do {
        if (busca->data == val) {
            if (anterior != NULL) {
                anterior->prox = busca->prox;
            } else {
                HEAD = busca->prox;
            }
            free(busca);
            printf("\nValor removido da lista.");
            return;
        }
        anterior = busca;
        busca = busca->prox;
    } while (busca != NULL);
    
    printf("\nValor nao encontrado na lista.");
}


void busca(int val){    //Percorre a lista procurando um valor
    no *busca = HEAD;
    int count = 1;
    do {
        if(busca->data == val){
            printf("\nValor encontrado na %d posicao.", count);
            return;
        }
        count++;
        busca = busca->prox;   
    } while(busca != NULL);

    printf("\nO valor nao foi encontrado.");
}

void printlista(){  //Printa toda a lista
    if(HEAD == NULL){
        printf("\nLista Vazia.");
        return;
    }
    no *ptr = HEAD;
    do{
        printf("%d -> ", ptr->data);
        ptr = ptr->prox;
    } while(ptr != NULL);
    printf("\n");
}

void finalizar(){   //Libera toda a memória após a execução do programa
    if(HEAD == NULL){
        return;
    }
    no *end = HEAD;
    do{
        end = end->prox;
        free(HEAD);
        HEAD = end;
    } while(end != NULL);
}

void menu(){
    printf("LISTA ENCADEADA (LINKED LIST)");
    printf("\n1. Adicionar elemento");
    printf("\n2. Remover elemento");
    printf("\n3. Buscar elemento");
    printf("\n4. Printar lista");
    printf("\n5. Sair");
    printf("\nEscolha: ");
}

