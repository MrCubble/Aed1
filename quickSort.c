#include <stdio.h>

void insectionSort(int v[], int ini, int fim){
    int *i, *j;
    int *pfim = &v[fim];
    int *pini = &v[ini];
    int pivot;
    for(j = &v[ini+1]; j<=pfim; j++){
        i = j -1;
        pivot = *j;
        while((i>=pini) && (*i>pivot)){
            *(i + 1) = *i;
            i--;
        }
        *(i + 1) = pivot;
    }
}

void qSortInterno(int v[], int ini, int fim){
    if(fim - ini <= 10)
        insectionSort(v, ini, fim);
    else{
        qSortInterno(v, ini, (ini+fim)/2);
        qSortInterno(v, (ini+fim/2), fim);
    }
}
void quickSort(int n, int v[]){
    qSortInterno(v, 0, n-1);
}

int main(){
    int n, v[1001];
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &v[i]);
    quickSort(n, v);
    for(int i=0; i<n; i++)
        printf("%d ", v[i]);
}
