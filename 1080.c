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
