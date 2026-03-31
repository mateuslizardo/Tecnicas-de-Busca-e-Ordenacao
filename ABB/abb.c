#include "abb.h"
#include <stdlib.h>

struct abb {
    Abb *esq, *dir;
    int chave;
};

Abb *criaAbb(){
    return NULL;
}

Abb *addChave(Abb *a, int c){
    if(a == NULL){
        a = calloc(1, sizeof(Abb));
        a->esq = a->dir = NULL;
        a->chave = c;
    } else if(c < a->chave){
        a->esq = addChave(a->esq, c);
    } else if(c > a->chave){
        a->dir = addChave(a->dir, c);
    }
    return a;
}

void destroy(Abb *a){
    if(a->esq != NULL){
        destroy(a->esq);
    } 
    if(a->dir != NULL) {
        destroy(a->dir);
    }
    free(a);
}

int altura(Abb *a){
    if(a == NULL){
        return -1;
    }
    int tamEsq = altura(a->esq);
    int tamDir = altura(a->dir);
    return tamEsq > tamDir ? tamEsq + 1 : tamDir + 1;
}

void rec_preorder(Abb *t, void (*visit)(Abb*)){
    if(t != NULL){
        visit(t);
        rec_preorder(t->esq, visit);
        rec_preorder(t->dir, visit);
    }
}

void rec_inorder(Abb *t, void (*visit)(Abb*)){
    if(t != NULL){
        rec_preorder(t->esq, visit);
        visit(t);
        rec_preorder(t->dir, visit);
    }
}

void rec_postorder(Abb *t, void (*visit)(Abb*)){
    if(t != NULL){
        rec_preorder(t->esq, visit);
        rec_preorder(t->dir, visit);
        visit(t);
    }
}