#include "str.h"
typedef struct suffix Suffix;
struct suffix {
    String *s;
    int index;
};
Suffix *cria_sufixo(String *s, int index);
void imprime_sufixo(Suffix *s);
int cmp_suffix(const void *a, const void *b);