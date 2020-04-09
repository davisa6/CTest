#include <stdio.h>
#include <stdlib.h>
#include <string.h>
        struct pilha{
        char valor;
        struct pilha *proximo;
        };

        struct pilha *empilhar(struct pilha *head, char data){
        struct pilha *tmp;
        if (head == NULL){
                head = malloc(sizeof(struct pilha));
                head->valor = data;
                head->proximo = NULL;
        }
        else
        {
                tmp = NULL;
                tmp = malloc(sizeof(struct pilha));
                tmp->valor = data;
                tmp->proximo = head;
                head=tmp;
        
        }
        return head;
        }
struct pilha *desempilhar (struct pilha *head){
        if (head != NULL){
                head = head->proximo;    
        }
        return head;
        }
int pilhavazia(struct pilha *head)
{
        if(head == NULL)
                return 1;
        else
                return 0;
}
void esvaziar(struct pilha *head){
        struct pilha *tmp, *oto;
        tmp = head->proximo;
        if (!pilhavazia(head)){
                while(tmp){
                        oto = tmp->proximo;
                        free(tmp);
                        tmp = oto;
                }
        }
}
int func ()
{
        int cont = 0;
        int cont2 = 0;
        int cont3 = 0;
        char stra[255];
        int finished = 0;
        struct pilha *p_head = NULL;
                fgets(stra,255,stdin);
                for (int j = 0; j<strlen(stra); j++){
                        if (stra[0] == ']'){
                                printf("No\n");
                                cont++;
                                cont2++;
                                cont3++;
                                break;    
                        }
                        else if (stra[0] == '\n'){
                            printf("Yes\n");
                            cont++;
                            cont2++;
                            cont3++;
                            break;
                        }
                        else if (stra[0] == ')'){
                                printf("No\n");
                                cont++;
                                cont2++;
                                cont3++;
                                break;    
                        }
                        else if (stra[j]  == '('){
                                p_head = empilhar(p_head, '(');
                        }
                        else if (stra[j] == '['){
                                p_head = empilhar(p_head, '[');
                        }
                        else if (stra[j] == ')'){    
                                if (pilhavazia(p_head)){
                                        printf("No\n");
                                        cont++;
                                        cont2++;
                                        cont3++;
                                        break;                                      
                                }                                
                                else if (p_head->valor == '('){
                                        p_head = desempilhar(p_head);
                                }
                                else if (p_head->valor == '['){
                                        printf("No\n");
                                        cont++;
                                        cont2++;
                                        break;
                                }
                        }
                        else if(stra[j] == ']'){
                                if (pilhavazia(p_head)){
                                        printf("No\n");
                                        cont++;
                                        cont2++;
                                        cont3++;
                                        break;                                      
                                }
                                else if (p_head->valor == '['){
                                        p_head = desempilhar(p_head);
                                }
                                 else if (p_head->valor == '('){
                                        printf("No\n");
                                        cont++;
                                        cont2++;
                                        break;
                                }
                        }
        }
        if (pilhavazia(p_head) && cont3 == 0){
                printf("Yes\n");
                cont2++;
        }
        else if (cont == 0){
                printf("No\n");
                cont2++;
        }
        else if (cont2 == 0){
                printf("No\n");
                cont2++;
                
        cont = 0;
        cont2 = 0;
        cont3 = 0;
        esvaziar(p_head);
        p_head = NULL;
        }                
        return 0;
}
int main ()
{
int cont = 0;
        int casos;
        scanf("%d\n",&casos);
        for (int i = 0; i<casos; i++){
                func();
        }
}