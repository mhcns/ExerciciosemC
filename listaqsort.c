#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// exercicio de sort (quicksort)


void swap(int *V, int i, int j){ //funcao para trocar elementos de lugar
    int t = V[i];
    V[i] = V[j];
    V[j] = t;
    printf("(%d,%d)", V[i],V[j]);
}

int partition(int *V, int left, int right, int meio){ //funcao para dividir o vetor
    int pos, i;                                       //e fazer a ordenacao
    swap(V, meio, right);
    pos = left;
    for(i = left; i < right; i++){
        if (V[i] < V[right]){
            swap(V, i, pos);
            pos++;
        }
    }
    swap(V, right, pos);
    return pos;
}

void quicksort(int *V,int left,int right){ //funcao que inicia o sort
    if (left <= right){
        int m = right + l/2;
        int pos = partition(V, left, right, meio);
        quicksort(V, left, pos - 1);
        quicksort(V, pos + 1, right);
    }
}

void main(){
    int n=0, finishim, k, i;
    int V[700];
    for(i=0; i<699; i++){   //"zerar" o vetor para o site de submissao enche-lo
        V[i] = -1;
    }
    char s[3];
    while(1){
        finishim = 0;   // variavel de condicao para finalizacao do codigo
        scanf("%s", s);
        if(strcmp(s, "ADD") == 0){  // adicionar um elemento no vetor
            scanf("%d", &k);
            V[n] = k;
            quicksort(V, 0, n);
            printf("%d %d %d'", V[n], V[n/2], V[0]);
            for(i=0; i<=n; i++)
                printf(" %d", V[i]);
            n++;
            finishim++;
        }
        else if(strcmp(s, "MAX") == 0){ //printa o maior valor do vetor
            if(n>0) printf("%d", V[0]);
            else printf("-1");
            finishim++;
        }
        else if(strcmp(s, "MIN") == 0){ //printa o menor valor do vetor
            if(n>0) printf("%d", V[n]);
            else printf("-1");
            finishim++;
        }
        else if(strcmp(s, "MED") == 0){ // printa o valor mediano do vetor
            if(n>0) printf("%d", V[n/2]);
            else printf("-1");
            finishim++;
        }
        else if(strcmp(s, "RES") == 0){ // reseta o vetor
            printf("%d", n);
            for(i=0; i<n; i++){
                V[i] = -1;
            }
            n=0;
            finishim++;
        }
        strcpy(s, "\0");
        printf("%s", s);
        if(finishim == 0) return;
        printf("\n");
    }
}
