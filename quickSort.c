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

void qSortInterno(int v[], int ini, int fim){
    int i, j;
    int pivot, tmp;
    if(fim - ini > 0){
        i = ini;
        j = fim;
        pivot = v[(i+j)/2];
        do{
            while(v[i] < pivot) i++;
            while(v[j] > pivot) j--;
            if(i<=j){
                tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
                i++; j--;
            }
        }while(i<=j);
        qSortInterno(v, ini, j);
        qSortInterno(v, i, fim);
    }
}

void qSortInterno2(tipoDado v[], int ini, int fim){
    if(fim - ini <= 10)
        insectionSort(v, ini, fim);
    else{
        qSortInterno2(v, ini, (ini+fim)/2);
        qSortInterno2(v, (ini+fim/2), fim);
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
