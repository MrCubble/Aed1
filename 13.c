#include <stdio.h>

void partialSort(int v[], int ini, int fim, int k){
    int i, j;
    int tmp, pivot;
    if(fim-ini>0){
        i = ini;
        j = fim;
        pivot = v[(i+j)/2];
        do{
            while(v[i]<pivot) i++;
            while(v[j]>pivot) j--;
            if(i<=j){
                tmp = v[j];
                v[j] = v[i];
                v[i] = tmp;;
                i++; j--;
            }
        }while(i<=j);
        partialSort(v, ini, j, k);
        if(i<k-1)
            partialSort(v, i, fim, k);
    }
}

void quickSort(int n, int v[], int k){
    partialSort(v, 0, n-1, k);
}

int main(){
    int n, v[20], k;
    scanf("%d%d", &n, &k);
    for(int i=0; i<n; i++)
        scanf("%d", v+i);
    quickSort(n, v, k);
    for(int i=0; i<n; i++)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}
