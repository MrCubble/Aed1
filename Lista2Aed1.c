#include <stdio.h>

typedef struct tipoNo{
	int dado;
	struct tipoNo *prox;
}tipoNo;

typedef struct{
	tipoNo* prim;
}tipoLista;

int listaSimetrica(tipoLista* l1){
	int i, tam = 1;
	tipoNo* tmp =  l1->prim;
	while(tmp->prox){tam++; tmp = tmp->prox;}
    tipoNo *meio = l1->prim;
    if(tam%2 == 0){
        i = tam/2;
        while(i--){meio = meio->prox;}
    }
    else{
        i = tam/2 + 1;
        while(i--){meio = meio->prox;}
    }
    tam = tam/2;
    tipoNo *aux = l1->prim;
    i = 0;
    while(i<tam){ 
        int ok = 0;
        tmp = meio;
        int chave = aux->dado;
        while(tmp){
            if(tmp->dado == chave)
                ok = 1;
            tmp = tmp->prox;
        }
        if(ok == 0) return 0;
        i++;
        aux = aux->prox;
    }
    return 1;
}

int main(){
	tipoNo a, b, c, d, e, f;
    a.dado = 3;
    b.dado = 6;
    c.dado = 9;
    d.dado = 3;
    e.dado = 6;
    f.dado = 9;
    a.prox = &b;
    b.prox = &c;
    c.prox = &d;
    d.prox = &e;
    e.prox = &f;
    f.prox = NULL;
    tipoLista x;
    x.prim = &a;
    if(listaSimetrica(&x) == 1)
        printf("Eu acho que funciona!\n");
    else
        printf("Rapaz, isso nao funciona\n"); 
    return 0;
}
