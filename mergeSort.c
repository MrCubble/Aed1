#include <stdio.h>
#include <stdlib.h>
void mergeSort(int n, int v[]){
    if(n == 1)
        return;
    int meio = n/2;
    if(n%2==1)
        meio += 1;
    int *v1, *v2;
    v1 = (int *)malloc(meio*sizeof(int));
    v2 = (int *)malloc((n-meio)*sizeof(int));
    for(int i=0; i<meio; i++)
        v1[i] = v[i];
    for(int i=meio; i<n; i++)
        v2[i-meio] = v[i];
    mergeSort(meio, v1);
    mergeSort(n-meio, v2);
    int i=0, j=0, k=0;
    while(i<meio && j<(n-meio)){
        if(v1[i]>v2[j]){
            v[k] = v1[i];
            i++, k++;
        }
        else{
            v[k] = v2[j];
            j++, k++;
        }
    }
    while(i<meio){v[k] = v1[i]; k++; i++;}
    while(j<(n-meio)){v[k] = v2[j]; k++; j++;}
    free(v1);
    free(v2);
}

int main(){
    int n;
    scanf("%d", &n); 
    int v[1010];
    for(int i=0; i<n; i++)
        scanf("%d", v+i);
    mergeSort(n, v);
    for(int i=0; i<n; i++)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}
