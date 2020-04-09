//(12(7(3()())(10()(11()())))(23(17()())(31()())))

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct arvore {
        struct arvore *esq;
        struct arvore *dir;
        struct arvore *pai;
        int valor;
};
void *push(struct arvore *aux, int val)
{
        if (aux == NULL){
                aux = malloc(sizeof(struct arvore));
                aux->valor = val;
                aux->esq = NULL;
                aux->dir = NULL; 
                return aux;
        }
        else{
                if (val <= aux->valor){
                        aux->esq = push(aux->esq,val);
                        aux->esq->pai = aux;
                }
                else{
                        aux->dir = push(aux->dir,val);
                        aux->dir->pai = aux;             
                }
                return aux;
        }

}
int profundidade (struct arvore *aux, int data, int altura){
        int cont = 0;
        if (aux == NULL){
                return 0;
        }
        if (aux->valor == data){
                cont = altura+1;
        }
        else if (data <= aux->valor){
                cont = profundidade(aux->esq, data,altura+1);
        }
        else if (data > aux->valor){
                cont = profundidade(aux->dir,data,altura+1);
        }
        return cont;
}

int main ()
{
        char a[400];
        struct arvore *auxe = NULL;
        int ia;
        int num;
        int altura = 0;
        int cont2 = 0;
        scanf("%s",a);
        for (int i = 0; i<strlen(a); i++){
                                if (a[i+3] >= '0' && a[i+3] <= '9' && a[i+2] >= '0' && a[i+2] <= '9' && a[i+1] >= '0' && a[i+1] <= '9' && a[i] >= '0' && a[i] <= '9'){
                                        ia = a[i+3] - '0' + (a[i+1] - '0') * 10 + (a[i+1] - '0') * 100 + (a[i] - '0') * 1000;
                                        auxe = push(auxe,ia);
                                        i++;
                                        i++;
                                        i++;
                                }
                                else if (a[i+2] >= '0' && a[i+2] <= '9' && a[i+1] >= '0' && a[i+1] <= '9' && a[i] >= '0' && a[i] <= '9'){
                                        ia = a[i+2] - '0' + (a[i+1] - '0') * 10 + (a[i] - '0') * 100;
                                        auxe = push(auxe,ia);
                                        i++;
                                        i++;
                                }
                                else if (a[i+1] >= '0' && a[i+1] <= '9' && a[i] >= '0' && a[i] <= '9'){
                                        ia = a[i+1] - '0' + (a[i] - '0') * 10;
                                        auxe = push(auxe,ia);
                                        i++;
                                }
                                else if (a[i] >= '0' && a[i] <= '9'){
                                ia = a[i] - '0';
                                auxe = push(auxe,ia);
                                }
        }
        scanf("%d",&num);
        int c;
        c= profundidade(auxe,num,altura);
        if (c){
                printf("ESTA NA ARVORE\n");
                printf("%d",c-1);
        }

        else{
                printf("NAO ESTA NA ARVORE\n");
                printf("-1");
        }
        
}