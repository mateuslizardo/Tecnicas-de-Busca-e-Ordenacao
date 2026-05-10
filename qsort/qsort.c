#include "item.h"
#include <sys/time.h>
#include <stdlib.h>
#define CUTOFF 15

// Definição das variáveis da pilha
int stack[MAX_STACK];
int topo = -1;

int median_of_3(Item *a, int lo, int hi) {
    int mid = lo + (hi - lo)/2;

    if (less(a[mid], a[lo]))
        exch(a[mid], a[lo]);

    if (less(a[hi], a[lo]))
        exch(a[hi], a[lo]);

    if (less(a[hi], a[mid]))
        exch(a[hi], a[mid]);

    return mid;
}

void insert_sort(Item *a, int lo, int hi){
    for(int i=lo+1; i<hi; i++){
        for(int j=i; j > lo; j--){
            compexch(a[j-1], a[j]);
        }
    }
}

int partition(Item *a, int lo, int hi){
    int i=lo, j=hi+1;
    Item v = a[lo];
    while(1){
        while(less(a[++i], v))
            if(i == hi) break;
        while(less(v, a[--j]))
            if(j == lo) break;
        
        if(i >= j) break;
        exch(a[i], a[j]);
    }
    exch(a[lo], a[j]);
    return j;
}

void quick_sort(Item *a, int lo, int hi){
    if(hi <= lo + CUTOFF - 1){
        insert_sort(a, lo, hi);
        return;
    } 

    int median = median_of_3(a, lo, hi);
    exch(a[lo], a[median]);
    int j = partition(a, lo, hi);
    quick_sort(a, lo, j-1);
    quick_sort(a, j+1, hi);
}

void quick_sort_bottom_up(Item *a, int lo, int hi){
    stack_init();
    push2(lo, hi);
    while(!stack_empty()){
        lo = pop(); hi = pop();
        if(hi <= lo + CUTOFF - 1) {
            insert_sort(a, lo, hi);
            continue;
        }
        int median = median_of_3(a, lo, hi);
        exch(a[lo], a[median]);
        int i = partition(a, lo, hi);
        if(i-lo > hi-i){
            push2(lo, i-1);
            push2(i+1, hi);
        } else {
            push2(i+1, hi);
            push2(lo, i-1);
        }
    }
}

void shuffle(Item *a,int N){
    struct timeval tv; gettimeofday(&tv,NULL);
    srand48(tv.tv_usec);
    for(int i=N-1;i>0;i--){
        int j=(unsigned int)(drand48()*(i+1));
        exch(a[i],a[j]);
    }
}

void quick_sort_3_way(Item *a,int lo,int hi){
    if(hi<=lo) return;
    Item v=a[lo];
    int lt=lo,gt=hi,i=lo;
    while (i<=gt){
        if (a[i]<v){
            exch(a[lt],a[i]);
            lt++;i++;
        } else if (a[i]>v){
            exch(a[i],a[gt]);
            gt--;
        } else{
            i++;
        }
    }
    quick_sort(a,lo,lt-1);
    quick_sort(a,gt+1,hi);
}

void sort(Item *a, int lo, int hi){
    quick_sort_3_way(a, lo, hi);
}