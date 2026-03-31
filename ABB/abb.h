#ifndef _ABB_H
#define _ABB_H

typedef struct abb Abb;

Abb *criaAbb();
Abb *addChave(Abb *a, int c);
void destroy(Abb *a);
int altura(Abb *a);

#endif