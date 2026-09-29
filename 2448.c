/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Miguel Matosinhos Machado
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 18/09/2026
Objetivo    : esse codigo deve conter uma função de busca binária e dois vetores (um para as casas e um para as cartas) 
e percorrer o vetor das cartas procurando cada um de seus valores no vetor casas e adicionando mais tempo.
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */
#include <stdio.h>
#define MAX 45000

int busca(int casas[], int tam, int alvo) {
    int esquerda = 0, direita = tam - 1;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        if (casas[meio] == alvo) {
            return meio;
        }
        if (casas[meio] <= alvo) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return - 1;
}

int main() {
    int n, m, casas[MAX], cartas[MAX], posicao, tempo = 0, inicio, distancia;
    scanf ("%d %d", n, m);
    int i, j;
    for (i = 0; i < n; i++) {
        scanf ("%d", &casas[i]);
    }
    for (j = 0; j < m; j++) {
        scanf ("%d", &cartas[j]);
    }
    for (j = 0; j < m; j++) {
        posicao = busca(casas, n, cartas[j]);
        if (posicao == -1) {
            return 1;
        }
        if (j == 0) {
            inicio = posicao;
        } else {
            distancia = posicao - inicio;
            tempo += distancia;
        }
    }
    printf ("%d", tempo);
    return 0;
}