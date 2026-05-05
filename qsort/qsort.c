#include "item.h"
#define CUTOFF 15

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

void sort(Item *a, int lo, int hi){
    quick_sort(a, lo, hi);
}