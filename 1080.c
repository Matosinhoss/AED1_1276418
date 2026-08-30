#include <stdio.h>
int main() {
    int vetor[100], i, maior = 0, posicao = 0;
    for (i = 0; i < 100; i++) {
        scanf ("%d", &vetor[i]);
        if (maior < vetor[i]) {
            maior = vetor[i];
            posicao = i + 1;
        }
    }
    printf ("%d\n", maior);
    printf ("%d\n", posicao);
    return 0;
}