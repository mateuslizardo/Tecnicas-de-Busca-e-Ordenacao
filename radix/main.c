#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.h"
#include "suffix.h"

String* ler_e_limpar(const char *nome_arquivo, int *n) {
    FILE *f = fopen(nome_arquivo, "r");
    if (!f) {
        fprintf(stderr, "Erro: nao foi possivel abrir o arquivo '%s'\n", nome_arquivo);
        return NULL;
    }

    String *resultado = str_create("");  /* string vazia inicial */
    char palavra[1024];
    int primeiro = 1;
    fscanf(f, "%d\n", n);

    /* fscanf com %s ignora espacos, tabs e quebras de linha automaticamente */
    while (fscanf(f, "%s", palavra) == 1) {
        if (!primeiro) {
            str_append(resultado, " ");  /* separa palavras com um unico espaco */
        }
        str_append(resultado, palavra);
        primeiro = 0;
    }

    fclose(f);
    return resultado;
}

int busca_binaria(Suffix **vetor, int n, String *query) {
    int lo = 0, hi = n - 1, result = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int cmp = strncmp(vetor[mid]->s->data + vetor[mid]->index,
                          query->data,
                          query->length);
        if (cmp == 0) {
            result = mid;   /* achou, mas continua procurando para a esquerda */
            hi = mid - 1;
        } else if (cmp < 0) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return result;  /* -1 se não encontrou */
}

void imprime_contexto(Suffix *suf, int context) {
    int inicio = suf->index - context;
    int fim    = suf->index + context;

    if (inicio < 0) inicio = 0;
    if (fim >= suf->s->length) fim = suf->s->length - 1;

    for (int i = inicio; i <= fim; i++) {
        printf("%c", suf->s->data[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }
    int n;
    int context = atoi(argv[2]);
    String *texto = ler_e_limpar(argv[1], &n);
    if (!texto) return 1;

    Suffix **vetor = calloc(n, sizeof(Suffix*));
    for(int i=0; i<n; i++){
        vetor[i] = cria_sufixo(texto, i);
    }
    qsort(vetor, n, sizeof(Suffix*), cmp_suffix);

    char q[100];
    scanf("%s%*c", q);

    String *query = str_create(q);


    int pos = busca_binaria(vetor, n, query);
    imprime_contexto(vetor[pos], context);
    /*while (pos < n &&
        strncmp(vetor[pos]->s->data + vetor[pos]->index,
                query->data,
                query->length) == 0) {
     imprime_contexto(vetor[pos], context);
     pos++;
    }*/
    return 0;
}
