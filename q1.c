#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista{
        float valor;
        int qtd;
        struct lista *proximo;
        char *nome;
}lista;
struct fila{
        struct lista *i;
        struct lista *f;
};
void *push(struct fila *aux, char *nome, float data, int quant)
{
        struct lista *tmp = malloc(sizeof(struct lista));
        tmp->valor = data;
        tmp->qtd = quant;
        tmp->proximo = NULL;
        tmp->nome = strdup(nome);
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
void pop(struct fila *aux, char nome[], int data)
{
                struct lista *tmp;
                tmp = malloc(sizeof(struct lista));
                tmp->proximo = NULL;
                struct lista *anterior, *oto;
                anterior = aux->i;
                tmp = anterior->proximo;
                float a = 1;
                float flag = 0;
                if (strcmp(anterior->nome,nome)==0){
                        if (anterior->qtd == data){
                        aux->i = anterior->proximo;
                        free(anterior);
                        }
                        else{
                        anterior->qtd = anterior->qtd - data;
                        }
                anterior = aux->i;
                }
                else{
                while (strcmp(tmp->nome, nome)!=0){
                        anterior = anterior->proximo;
                        tmp = tmp->proximo;
                }
                if (tmp == NULL)
                        return;
                else if (tmp->qtd == data){
                        oto = tmp;
                        tmp = tmp->proximo;
                        free(oto);
                        anterior->proximo = tmp;    
                }
                else{
                        tmp->qtd = tmp->qtd - data;       
                }
                }
}
void group (struct fila *aux, float valor)
{
                struct lista *tmp;
                tmp = malloc(sizeof(struct lista));
                tmp->proximo = NULL;
                struct lista *anterior, *oto;
                anterior = malloc(sizeof(struct lista));
                oto = malloc(sizeof(struct lista));
                anterior = aux->i;
                tmp = aux->i->proximo;
                struct lista *final;
                final = aux->f;
                float flag = 0;
                if (valor > final->valor){
                        flag = 1;
                }
                if (flag != 1){
                if (anterior->valor > valor){
                        aux->i = anterior->proximo;
                        free(anterior);
                }
                else{
                anterior = aux->i;
                while (tmp){
                        while (valor >= tmp->valor){
                                anterior = anterior->proximo;
                                tmp = tmp->proximo;
                        }
                        if (tmp == NULL){
                                return;
                        } 
                        else{
                                oto = tmp;
                                tmp = tmp->proximo;
                                free(oto);
                                anterior->proximo = tmp;
                        }
                }
                }
                }

}
float consulta (struct fila *aux)
{
        float soma = 0;
        struct lista *tmp;
        tmp = aux->i;
        float resultado;
        while (tmp != NULL){
                resultado = (tmp->valor * tmp->qtd);
                soma += resultado;
                tmp = tmp->proximo;
        }
        return soma;
}
void procura(struct fila *aux, char nome[])
{
        struct lista *tmp, *anterior;
        anterior = malloc(sizeof(struct lista));
        anterior = aux->i;
        int cont = 0;
        while (anterior){
                if (strcmp(anterior->nome,nome)==0){
                        printf("%s\n",anterior->nome);
                        printf("- %.1f\n",anterior->valor);
                        printf("- %d\n",anterior->qtd);
                        printf("\n");
                        cont++;
                        break;
                }
                else{
                anterior = anterior->proximo;
                }
        }
                if(cont == 0){
                      printf("%s nao foi encontrado.",nome);
                      printf("\n\n");  
                }
}
int main ()
{
        char st[1000];
        char teste[100];
        float value;
        int qtdd;
        struct fila *aux;
        aux = malloc(sizeof(struct fila));
        aux->i = NULL;
        aux->f = NULL;
        float cont = 0;
        float i = 0;
        while(scanf("%s",st) != EOF){
                if(strcmp(st,"REMOVER") == 0){
                        scanf("%s%d",teste,&qtdd);
                        pop(aux,teste,qtdd);
                }
                else if(strcmp(st,"REMOVERGRUPO")==0){
                        scanf("%f",&value);
                        group(aux,value);
                }
                else if(strcmp(st,"PROCURAR")==0){
                        scanf(" %s",teste);
                        procura(aux,teste);
                }
                else if (strcmp(st,"CONSULTAR") == 0){
                        printf("Atualmente a lista esta em R$%.1f\n",consulta(aux));
                        printf("\n");
                }
                else if (strcmp(st,"INSERIR") == 0){
                        scanf("%s%f%d",teste,&value,&qtdd);
                        push(aux,teste,value,qtdd);
                }
                else{
                        return 0;
                }
        }
        struct lista *tmp;
        tmp = aux->i;
        return 0;
}