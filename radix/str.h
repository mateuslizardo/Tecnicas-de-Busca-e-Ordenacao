#ifndef STR_H
#define STR_H

typedef struct string {
    char *data;
    int length;
} String;

typedef String* Item;

String* str_create(const char *s);
void    str_append(String *s, const char *t);
void    str_print(String *s, int index);
void    str_destroy(String *s);
int     compare(String *s, String *t);
int     compare_from(String *s, String *t, int d);

#define less(A, B)        (compare(A, B) < 0)
#define less_from(A, B,d) (compare_from(A, B, d) < 0)
#define exch(A, B)        { Item t = A; A = B; B = t; }

#endif
