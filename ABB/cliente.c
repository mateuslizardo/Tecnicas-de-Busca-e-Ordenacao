#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "abb.h"

void cliente(int n){
    Abb *a = criaAbb();
    srand(time(NULL)); // should only be called once

    for(int i=0; i<n; i++){
        int r = rand(); // returns a pseudo-random integer between 0 and RAND_MAX
        a = addChave(a, r);
    }
    printf("%d\n", altura(a));
}

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    cliente(n);
    return 0;
}