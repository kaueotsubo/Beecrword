#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nome[250];
    char cor[10];
    char tamanho;
}blusas;

int comparar(const void *a, const void *b){
    blusas *blusaA = (blusas *)a;
    blusas *blusaB = (blusas *)b;

    int cmpcor = strcmp(blusaA->cor, blusaB->cor);

    if(cmpcor != 0){
        return cmpcor;
    }

    if (blusaA->tamanho < blusaB->tamanho){
        return 1;
    }
    if (blusaA->tamanho > blusaB->tamanho){
        return -1;
    }

    return strcmp(blusaA->nome, blusaB->nome);    
}

void ordenarBlusas(blusas lista[], int total){
    qsort(lista, total, sizeof(blusas), comparar);
}

int main() {
    int i, n, j;
    int caso = 1;
    while(scanf("%d", &n) != EOF && n != 0){
        if (!caso) {
            printf("\n"); 
        }
        caso = 0;
        blusas turma[n];
        for(i=0;i<n;i++){
            scanf(" %[^\n]", turma[i].nome); 
            scanf("%s %c", turma[i].cor, &turma[i].tamanho);
        }
        ordenarBlusas(turma, n);

        for(i=0; i<n; i++){
            printf("%s %c %s\n", turma[i].cor, turma[i].tamanho, turma[i].nome);
        }

    }
    return 0;
}
