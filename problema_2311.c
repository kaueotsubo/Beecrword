#include <stdio.h>
#include <string.h>

void encontrarMaiorMenor(double notas[], int n, double* maior, double* menor){
    int i;
    *maior = notas[0];
    *menor = notas[0];
    for(i=1; i<n; i++){
        if (notas[i] > *maior) {
            *maior = notas[i];
        }
        if (notas[i] < *menor) {
            *menor = notas[i];
        }
    }
}

double somatudo(double notas[], int n){
    double soma = 0.0;
    int i;
    for(i=0; i<n;i++){
        soma += notas[i];
    }
    return soma;
}

int main() {
    char nome[250];
    int i, n, j;
    double notas[7], maior, menor, grau, somadas7, somafinal, total;

    scanf("%d", &n);

    for(i=0;i<n;i++){
        scanf("%s ", nome);
        scanf("%lf", &grau);
        for(j=0; j < 7; j++){
            scanf("%lf", &notas[j]);
        }

        encontrarMaiorMenor(notas, 7, &maior, &menor);

        somadas7 = somatudo(notas, 7);

        somafinal = somadas7 - maior - menor;
        total = somafinal * grau;


        printf("%s %.2lf\n", nome, total);
    }

    return 0;
}
