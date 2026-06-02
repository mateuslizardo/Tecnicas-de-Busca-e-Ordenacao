#include "str.h"
#include "suffix.h"
#include <stdlib.h>
#include <string.h>


Suffix *cria_sufixo(String *s, int index){
    Suffix *novo = calloc(1, sizeof(Suffix));
    novo->s = s;
    novo->index = index;
    return novo;
}

void imprime_sufixo(Suffix *s){
    str_print(s->s, s->index);
}

int cmp_suffix(const void *a, const void *b) {
    Suffix *sa = *(Suffix **)a;
    Suffix *sb = *(Suffix **)b;
    return strcmp(sa->s->data + sa->index, sb->s->data + sb->index);
}