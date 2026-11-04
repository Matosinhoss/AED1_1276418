/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Miguel Matosinhos Machado
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1095
Data        : 03/11/2026
Objetivo    : sequencia de j
Dificuldade : 0
Uso de IA   : 0
-------------------------------------------------------------------------- */
#include <stdio.h>

int main() {
    int i = 1, j = 60;
    while (j >= 0) {
        printf ("I=%d J=%d\n", i, j);
        i += 3;
        j -= 5;
    }
}