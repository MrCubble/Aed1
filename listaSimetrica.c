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
    return 0;
}
