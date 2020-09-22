#include <stdio.h>
#include <stdlib.h>

// exercicio de bst (binary search tree)

typedef struct no{
    int k;
    struct no* left;
    struct no* right;
}no;

typedef struct root{
    struct no* raiz;
}root;

int ADD(no* root, int k, int h){
    if(root==NULL){
        no *novo = malloc(sizeof(no));
        novo->left=NULL;
        novo->right=NULL;
        novo->k = k;
        root = novo;
        return 1;
    }
    else{
        if(k<root->k)
            return ADD(root->left, k, h+1);
        else if(k>root->k)
            return ADD(root->right, k, h+1);
        else
            return h;
    }
}

int QRY(no* root, int k, int h){
    if(root==NULL){
        return 0;
    }
    else{
        if(k<root->k)
            return QRY(root->left, k, h+1);
        else if(k>root->k)
            return QRY(root->right, k, h+1);
        else
            return h;
    }
}

int DEL(no* root, int k, int h){
    if(root==NULL){
        return 0;
    }
    else{
        if(k<root->k){
            if(root->left!=NULL)
                if((root->left)->k==k){
                        no* aux = malloc(sizeof(no));
                        if((root->left)->left==NULL){
                            aux=root->left;
                            if((root->left)->right==NULL){
                                root->left=NULL;
                                free(aux);
                                return h;
                            }
                            else{
                                root->left=aux->right;
                                free(aux);
                                return h;
                            }
                        }
                        else{
                            if((root->left)->right==NULL){
                                root->left=aux->left;
                                free(aux);
                                return h;
                            }
                            else{
                                aux=aux->right;
                                while(aux->left!=NULL)
                                    aux=aux->left;
                                (root->left)->k=aux->k;
                                no *temp = malloc(sizeof(no));
                                temp=(root->left);
                                if(temp->right==aux){
                                    temp->right=NULL;
                                }
                                else{
                                    temp=temp->right;
                                    while(temp->left!=aux)
                                        temp=temp->left;
                                    temp->left=NULL;
                                }
                                free(aux);
                                return h;
                            }
                        }
                }
                return DEL(root->left,k,h+1);
        }
        else if(k>root->k){
                if(root->right!=NULL)
                    if((root->right)->k==k){
                        no* aux = malloc(sizeof(no));
                        if((root->right)->left==NULL){
                            aux=root->right;
                            if((root->right)->right==NULL){
                                root->right=NULL;
                                free(aux);
                                return h;
                            }
                            else{
                                root->right=aux->right;
                                free(aux);
                                return h;
                            }
                        }
                        else{
                            if((root->right)->right==NULL){
                                root->right=aux->left;
                                free(aux);
                                return h;
                            }
                            else{
                                aux=aux->right;
                                while(aux->left!=NULL)
                                    aux=aux->left;
                                (root->right)->k=aux->k;
                                no *temp = malloc(sizeof(no));
                                temp=(root->right);
                                if(temp->right==aux){
                                    temp->right=NULL;
                                }
                                else{
                                    temp=temp->right;
                                    while(temp->left!=aux)
                                        temp=temp->left;
                                    temp->left=NULL;
                                }
                                free(aux);
                                return h;
                            }
                        }
                }
            return DEL(root->right,k,h+1);
        }
    }
}

void main(){
    int N, M, seedX, A, C, i, j;
    root *BST;
    BST->raiz=NULL;
    scanf("%d %d %d %d %d", &N, &M, &seedX, &A, &C);
    int *Iniciais = malloc(N*sizeof(int));
    Iniciais[0]=seedX;
    ADD(BST->raiz,Iniciais[0],0);
    for(i=1;i<N;i++){
        Iniciais[i]=(((A*Iniciais[i-1])+C)%M);
        ADD(BST->raiz,Iniciais[i],0);
    }
}