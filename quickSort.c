#include <stdio.h>
#include <string.h>

typedef struct tipoDado{
    char nome[30];
}tipoDado;

void insectionSort(tipoDado v[], int ini, int fim){
    tipoDado *i, *j;
    tipoDado *pfim = &v[fim];
    tipoDado *pini = &v[ini];
    tipoDado pivot;
    for(j = &v[ini+1]; j<=pfim; j++){
        i = j -1;
        pivot = *j;
        while((i>=pini) && (strcmp(i->nome, pivot.nome)>0)){
            *(i + 1) = *i;
            i--;
        }
        *(i + 1) = pivot;
    }
}

void qSortInterno2(tipoDado v[], int ini, int fim){
    if(fim - ini <= 10)
        insectionSort(v, ini, fim);
    else{
        qSortInterno2(v, ini, (ini+fim)/2);
        qSortInterno2(v, (ini+fim)/2+1, fim);
        tipoDado u[fim - ini + 2];
        int i = ini, j = (ini+fim)/2+1;
        int k = 0;
        while(i<=(ini+fim)/2 || j<=fim){
            if((strcmp(v[i].nome, v[j].nome)<0 && i<=(ini+fim)/2)||j>fim){
                u[k] = v[i];
                i++;
            }
            else{
                u[k] = v[j];
                j++;
            }
            k++;
        }
        for(int i=ini; i<=fim; i++)
            v[i] = u[i-ini];
    }
}
void quickSort(int n, tipoDado v[]){
    qSortInterno2(v, 0, n-1);
}

int main(){
    int n;
    tipoDado v[1001];
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%s", v[i].nome);
    quickSort(n, v);
    for(int i=0; i<n; i++)
        printf("%s ", v[i].nome);
    printf("\n");
}
