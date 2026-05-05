#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void sort(Item *a, int lo, int hi);

int main(int argc, char *argv[]){
    int n = atoi(argv[argc - 1]);
    Item *itens = calloc(n, sizeof(Item));
    
    for(int i=0; i<n; i++){
        scanf("%d%*c", &itens[i]);
    }

    clock_t inicio = clock();
    sort(itens, 0, n);
    clock_t fim = clock();
    double tempo = (double) (fim - inicio) / CLOCKS_PER_SEC;
    printf("%.4lf\n", tempo);

    /*for(int i=0; i<n; i++){
        printf("%d\n", itens[i]);
    }*/

    free(itens);

    return 0;
}