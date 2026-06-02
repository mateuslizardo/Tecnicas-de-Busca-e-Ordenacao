#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"

String* str_create(const char *s) {
    String *novo = malloc(sizeof(String));
    novo->length = strlen(s);
    novo->data   = malloc(novo->length + 1);
    strcpy(novo->data, s);
    return novo;
}

void str_append(String *s, const char *t) {
    int tlen    = strlen(t);
    s->data     = realloc(s->data, s->length + tlen + 1);
    strcpy(s->data + s->length, t);
    s->length  += tlen;
}

void str_print(String *s, int index) {
    if (index < 0 || index >= s->length) return;
    printf("%s", s->data + index);
}

void str_destroy(String *s) {
    free(s->data);
    free(s);
}

int compare(String *s, String *t) {
    return compare_from(s, t, 0);
}

int compare_from(String *s, String *t, int d) {
    
    int min = s->length < t->length ? s->length : t->length;
    for (int i = d; i < min; i++) {
    if (s->data[i] < t->data[i]) { return -1; }
    if (s->data[i] > t->data[i]) { return 1; }
    }
    return s->length - t->length;
}
