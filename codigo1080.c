#include <stdio.h>

int main() 
{
    int vetor[100], i, maior = 0, posicao = 0;
    printf ("digite 100 valores inteiros:\n");
    for (i = 0; i < 100; i++) {
        scanf ("%d", &vetor[i]);
        if (maior < vetor[i]) {
            maior = vetor[i];
            posicao = i;
        }
    }
    printf ("%d %d\n", maior, posicao);
    return 0;
}