#ifndef _ABB_H
#define _ABB_H

typedef struct abb Abb;

Abb *criaAbb();
Abb *addChave(Abb *a, int c);
void destroy(Abb *a);
int altura(Abb *a);
void rec_preorder(Abb *t, void (*visit)(Abb*));
void rec_inorder(Abb *t, void (*visit)(Abb*));
void rec_postorder(Abb *t, void (*visit)(Abb*));

#endif