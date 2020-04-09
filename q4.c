#include <stdio.h>
#include <stdlib.h>
#include <String.h>
struct lista{
int valor;
struct lista *proximo;
};

struct fila{
        struct lista *i;
        struct lista *f;
};
void *push(struct fila *aux, int data)
 {
        struct lista *tmp = malloc(sizeof(struct lista));
        tmp->proximo = NULL;
        tmp->valor = data;
        if (aux->i == NULL){
                aux->i = tmp;
                aux->f = tmp;
        }
        else
        {
                aux->f->proximo = tmp;
                aux->f = tmp;
        }
        }
void *pop(struct fila *aux, int data)
        {
                struct lista *tmp;
                tmp = malloc(sizeof(struct lista));
                tmp->proximo = NULL;
                tmp->valor = data;
                struct lista *anterior, *oto;
                anterior = aux->i;
                tmp = anterior->proximo;
                int flag = 0;
                if (anterior->valor == data){
                        aux->i = anterior->proximo;
                        free(anterior);
                        flag = 1;
                }
                anterior = aux->i;
                if (flag != 1){
                while (tmp->valor != data){
                        anterior = anterior->proximo;
                        tmp = tmp->proximo;
                }
                oto = tmp;
                tmp = tmp->proximo;
                free(oto);
                anterior->proximo = tmp;
                }

        }
void imprimir (struct fila *aux){
	struct lista *tmp;
	tmp = aux->i;
        while (tmp != NULL & tmp->proximo != NULL){
                printf("%d ",tmp->valor);
                tmp = tmp -> proximo;
        }
	printf("%d\n",tmp->valor);
}

int main()
{
        struct fila *aux;
        aux = malloc(sizeof(struct fila));
        aux->i = NULL;
        aux->f = NULL;
        int qtdd_inicial,val;
        int i = 0;
        char st[1000];
        int qtdd_saiu;
        val = 0;
        struct lista *teste;
        teste = aux->i;
        struct lista *tmp;
        tmp = aux->i;        
        int cont = 0;
        while (1){
                scanf("%s",&st);
                if (strcmp(st,"Finalizar") == 0){
                        return 0;
                }
                else if (strcmp(st, "Desenfileirar") == 0){
        		teste = aux->i;
                        pop(aux,teste->valor);
                }
                else if(strcmp(st,"Imprimir") == 0){
			imprimir(aux);
		}
		else{
			scanf("%d",&val);
			push(aux,val);
		}
        }
        return 0;
}