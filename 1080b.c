/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Miguel Matosinhos Machado
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 30/08/2026
Objetivo    : Encontrar o maior valor em um vetor e sua posição.
Dificuldade : nenhum desafio maior
Uso de IA   : não utilizei
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
int main() {
    int *vetor, tamanho, i, maior, posicao;
    scanf ("%d", &tamanho);
    vetor = malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        return 1;
    }
    for (i = 0; i < tamanho; i++) {
        scanf ("%d", &vetor[i]);
        if (i == 0) {
            maior = vetor[i];
            posicao = 1;
        }else if (maior < vetor[i]) {
            maior = vetor[i];
            posicao = i + 1;
        }
    }
    printf ("%d\n", maior);
    printf ("%d\n", posicao);
    free (vetor);
    return 0;
}
