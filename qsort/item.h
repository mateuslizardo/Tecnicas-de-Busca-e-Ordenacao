#ifndef _ITEM_H
#define _ITEM_H

typedef int Item;
#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)

// Stack macros for Quick Sort Bottom Up
#define MAX_STACK 1000000
extern int stack[MAX_STACK];
extern int topo;

#define stack_init() (topo = -1)
#define push(A) (stack[++topo] = (A))
#define pop() (stack[topo--])
#define stack_empty() (topo == -1)
#define push2(A, B) push(B); push(A)

#endif