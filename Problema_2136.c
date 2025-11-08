#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nome[250];
    int ordem;
}inscrito;

int compararnome(const void *a, const void *b){
    inscrito *ia = (inscrito *)a;
    inscrito *ib = (inscrito *)b;
    return strcmp(ia->nome, ib->nome);    
}

int compararstring(const void *a, const void *b){
    const int TAMANHO_NOME = 250;
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    const int MAX_nome = 250;
    const int MAX_inscrito = 1000;

    inscrito sim[MAX_inscrito];
    char nao[MAX_inscrito][MAX_nome];
    char nome[MAX_nome];
    char escolha[10];
    int simcount = 0, naocount = 0, ordemIns = 0, i;

    while(scanf("%s", nome) == 1 && strcmp(nome, "FIM") != 0){
        scanf("%s ", escolha);

        if(strcmp(escolha, "YES") == 0){
            strcpy(sim[simcount].nome, nome);
            sim[simcount].ordem = ordemIns;
            simcount++;
        }
        else if(strcmp(escolha, "NO") == 0){
            strcpy(nao[naocount], nome);
            naocount++;
        }

        ordemIns++;
    }

    inscrito vencedor = sim[0];

    for(i=1;i<simcount;i++){
        inscrito atual = sim[i];

        if(strlen(atual.nome) > strlen(vencedor.nome)){
            vencedor = atual;
        }
        else if(strlen(atual.nome) == strlen(vencedor.nome)){
            if(atual.ordem < vencedor.ordem){
                vencedor = atual;
            }
        }
    }

    qsort(sim, simcount, sizeof(inscrito), compararnome);
    
    qsort(nao, naocount, sizeof(char[MAX_nome]),compararstring);

    if(simcount > 0){
        printf("%s\n", sim[0].nome);
    }

    for(i=1;i<simcount;i++){
        if(strcmp(sim[i].nome, sim[i-1].nome) != 0){
            printf("%s\n", sim[i].nome);
        }
    }

    for(i=0; i<naocount; i++){
        printf("%s\n", nao[i]);
    }

    printf("\n");
    printf("Amigo do Habay:\n");
    printf("%s\n", vencedor.nome);
    
    return 0;
}
