#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// exercicio de lista/fila/pilha

typedef struct no{;
    int x, t, h;
    struct no *next;
}no;

void Push(no *T,int v,int t,no *tail){
    no *aux = (no *)malloc(sizeof(no));
    aux->x = v;
    aux->next = T[t].next;
    if(T[t].h==0)
        tail[t].next=aux;
    T[t].next=aux;
    T[t].h++;
    return;
}

void Enqueue(no *T,int v,int t,no *tail){
    no *aux = (no *)malloc(sizeof(no));
    aux->x = v;
    aux->next=NULL;
    if(T[t].h!=0){
        (tail[t].next)->next=aux;
    }
    else{

        T[t].next=aux;

    }
    tail[t].next=aux;
    T[t].h++;
    return;
}

void Pop(no *T,int t,no *tail){
    if(T[t].h==0){
        tail[t].next=NULL;
        return;
    }
    else{
        no *aux=T[t].next;
        if(T[t].h>1){
            T[t].next = aux->next;
        }
        else{
            T[t].next=NULL;
        }
        free(aux);
    }
    T[t].h--;
    if(T[t].h==0)
        tail[t].next=NULL;
    return;
}

void Split(no *T,int t,int x,no *tail){
    int i, j;
    no *head;
    no *aux = (no *)malloc(sizeof(no));
    no *temp = (no *)malloc(sizeof(no));
    no *temp2 = (no *)malloc(sizeof(no));
    if(T[t].h!=0){

        for(j=x;j>t;j--){
            temp2->next=T[j].next;
            T[j+1].next=temp2->next;
            temp2->next=tail[j].next;
            tail[j+1].next = temp2->next;
            T[j+1].h=T[j].h;
            T[j+1].t=T[j].t;
        }
        aux->next=T[t].next;
        for(i=0;i<T[t].h/2;i++){
            aux=aux->next;
        }
        if(T[t].h>1){
            tail[t].next=aux;
        }
        else{
            T[t].next = NULL;
            tail[t].next=NULL;
        }
        head = aux->next;
        aux->next=NULL;
        T[t+1].next = head;
        temp->next = T[t+1].next;
        while(temp->next!=NULL){
            temp=temp->next;
        }
            T[t+1].t = T[t].t;
        tail[t+1].next=temp;

    }
    else{
         for(j=x;j>t;j--){
            T[j+1]=T[j];
            temp2->next=tail[j].next;
            tail[j+1].next = temp2->next;
            T[j].next=NULL;
            tail[j].next=NULL;
            T[j].h=0;
            T[j].t=1;
        }
            T[t].t=1;
            T[t+1].t=1;
    }
    T[t+1].h = T[t].h - (T[t].h/2);
    T[t].h = T[t].h/2;
    aux=NULL;
    return;
}

void Merge(no *T,int t,int k,no *tail,int x){
    int i, j;
    if(T[k].h!=0){
        if(T[t].h>0){
            (tail[t].next)->next = T[k].next;
            tail[t].next = tail[k].next;
        }
        else{
            T[t].next = T[k].next;
            tail[t].next = tail[k].next;
            tail[k].next=NULL;
        }
        T[k].next = NULL;
        T[t].h= T[t].h+T[k].h;
        T[k].h=0;
    }
    for(i=k;i<x;i++){
        T[i] = T[i+1];
        tail[i].next = tail[i+1].next;
        T[i+1].next = NULL;
        tail[i+1].next = NULL;
        T[i+1].h=0;
        T[i+1].t=0;
    }
    return;
}
void Transforma(no *T,int t){
    if(T[t].t==0)
        T[t].t++;
    else T[t].t--;
    return;
}

void main(){
    char s[3];
    int i, v, j, x=1, caso=0,end=0,finishim;
    no *T = (no *)malloc(100*sizeof(no));
    no *tail = (no *)malloc(100*sizeof(no));
    while(1){
        for(i=0;i<100;i++){
            T[i].next=NULL;
            T[i].t=0;
            tail[i].next=NULL;
            T[i].h=0;
        }
        x=0;
        while(end==0){
            finishim=0;
            scanf("%s", s);
            switch(s[0]){
            case 'A':
                scanf("%d", &i);
                scanf("%d", &v);
                if(T[i].t==0)
                    Enqueue(T,v,i,tail);
                else
                    Push(T,v,i,tail);
                finishim++;
                break;
            case 'D':
                scanf("%d", &i);
                Pop(T,i,tail);
                finishim++;
                break;
            case 'S':
                scanf("%d", &i);
                Split(T,i,x,tail);
                x++;
                finishim++;
                break;
            case 'M':
                scanf("%d", &i);
                scanf("%d", &j);
                Merge(T,i,j,tail,x);
                x--;
                finishim++;
                break;
            case 'T':
                scanf("%d", &i);
                Transforma(T,i);
                finishim++;
                break;
            case 'E':
                end++;
                finishim++;
                break;
            }
            strcpy(s,"\0");
            if(finishim==0) return;
        }
        end--;
        printf("caso %d:", caso);
        caso++;
        for(i=0;i<=x;i++){
            printf(" ");
            if(T[i].next!=NULL){
                printf("%d", (T[i].next)->x);
            }
            else printf("?");
        }
        printf("\n\n");

    }
    return;
}
