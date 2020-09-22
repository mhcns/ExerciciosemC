#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// exercicio de hash

typedef struct no{
	int K, U;
	struct no *next;
}no;

typedef struct print{
    int i;
    int contador;
}print;
int M;

typedef struct head{
	int L;
	struct no *next;
	struct no *tail;
}head;

int ADD(head *H, int K, int L, int t){ //funcao para adicionar um no a hash
	int i;
	int Andar = K%t;
	while(H[Andar].L==L){
		Andar++;
		if(Andar == t)
			Andar = 0;
		if(Andar == K%t){
            return -1;
        }
	}
	no *add = (no *)malloc(sizeof(no));
	add->next=NULL;
	add->K=K;
	add->U=1;
	if(H[Andar].L==0)
        H[Andar].next=add;
    else
        (H[Andar].tail)->next=add;
    H[Andar].tail=add;
	H[Andar].L++;
	return Andar;
}

print DEL(head *H, int K){  // funcao que deleta um no da hash, e reorganiza
	int i =K%M, contador;
	print r;
	no *aux = (no *)malloc(sizeof(no));
	contador=0;
    aux = H[i].next;
    while((aux!=NULL)&&(aux->K!=K)){
        aux=aux->next;
        contador++;
    }
    if(aux!=NULL){
        if(aux->U==0){
            r.i=-1;
            return r;
        }
        else{
            r.i=i;
            r.contador=contador;
            aux->U=0;
            return r;
        }
    }
    i++;
    if(i==M)
        i=0;
	while(i!=K%M){
        contador=0;
        aux = H[i].next;
        while((aux!=NULL)&&(aux->K!=K)){
            aux=aux->next;
            contador++;
        }
        if((aux==NULL)&&(i==(K%M)-1)){
            r.i=-1;
            return r;
        }
        else if(aux!=NULL){
            if(aux->U==0){
                r.i=-1;
                return r;
            }
            else{
                r.i=i;
                r.contador=contador;
                aux->U=0;
                return r;
            }
        }
    i++;
    if(i==M)
        i=0;
    }
    r.i=-1;
    return r;
}

print QRY(head *H, int K){ // funcao que faz a busca na hash
	int i = K%M, contador;
	print r;
	no *aux = (no *)malloc(sizeof(no));
    contador = 0;
    aux = H[i].next;
	while((aux!=NULL)&&(aux->K!=K)){
        aux=aux->next;
        contador++;
    }
    if(aux!=NULL){
        if(aux->U==0){
            r.i=-1;
            return r;
        }
        else{
            r.i=i;
            r.contador=contador;
            return r;
        }
    }
    i++;
    if(i==M)
        i=0;
	while(i!=K%M){
        contador=0;
        aux = H[i].next;
        while((aux!=NULL)&&(aux->K!=K)){
            aux=aux->next;
            contador++;
        }
        if((aux==NULL)&&(i==(K%M)-1)){
            r.i=-1;
            return r;
        }
        else if(aux!=NULL){
            if(aux->U==0){
                r.i=-1;
                return r;
            }
            else{
                r.i=i;
                r.contador=contador;
                return r;
            }
        }
        i++;
        if(i==M) i=0;
    }
    r.i=-1;
    return r;
}

void main(){
      //  freopen("l2.in", "r", stdin);
      //  freopen("l2.out", "w", stdout);
	char s[3];                     //string para identificar o comando desejado
	int L, K, i, y, finishim, caso=0; // ADD para adicionar, DEL para deletar e QRY para procurar na hash
	print x;
	scanf("%d %d", &M, &L);
	head *H = (head *)malloc(M*sizeof(head));
	for(i=0;i<M;i++){
		H[i].next=NULL;
		H[i].L=0;
		H[i].tail=NULL;
	}
	while(1){
        finishim = 0;
        scanf("%s %d", s, &K);
        switch(s[0]){
            case 'A':
                y = ADD(H,K,L,M);
                if(y==-1){
                    int t=(2*M)+1, j, h;
                    head *aux = (head *)malloc(t*sizeof(head));
                    no *qq = (no *)malloc(sizeof(no));
                    for(j=0;j<t;j++){
                        aux[j].next=NULL;
                        aux[j].L=0;
                    }
                    for(j=0;j<M;j++){
                        qq = H[j].next;
                        while(qq!=NULL){
                            if(qq->U==1)
                                ADD(aux,qq->K,L,t);
                            else;
                            qq=qq->next;
                        }
                    }
                    H = (head *)malloc(t*sizeof(head));
                    for(j=0;j<t;j++){
                        H[j] = aux[j];
                    }
                    M=t;
                    y=ADD(H,K,L,M);
                }
                finishim++;
                printf("%d %d.%d", caso, y, H[y].L-1);
                break;
            case 'R':
                x = DEL(H,K);
                if(x.i==-1)
                    printf("%d ?.?", caso);
                else
                    printf("%d %d.%d", caso, x.i, x.contador);
                finishim++;
                break;
            case 'Q':
                x = QRY(H,K);
                if(x.i==-1)
                    printf("%d ?.?", caso);
                else
                    printf("%d %d.%d", caso, x.i, x.contador);
                finishim++;
                break;
        }
        caso++;
        strcpy(s,"\0");
        if(finishim==0) return;
        printf("\n");
	}
}
