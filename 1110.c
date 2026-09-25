/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Miguel Matosinhos Machado
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 21/09/2026
Objetivo    : fila de cartas
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct carta {
    int valor;
    struct carta *proximo;
} carta;

typedef struct baralho {
    carta *inicio;
    carta *fim;
    int tamanho;
} baralho;

void push(baralho *p, int n) {
    carta *novo = (carta*) malloc(sizeof(carta));
    if (novo == NULL) {
        return;
    }
    novo->valor = n;
    novo->proximo = NULL;
    if (p->inicio == NULL) {
        p->inicio = novo;
        p->fim = novo;
    } else {
        p->fim->proximo = novo;
        p->fim = novo;
    }
    p->tamanho++;
}

int pop(baralho *p) {
    int valor;
    carta *antigo;
    antigo = p->inicio;
    valor = p->inicio->valor;
    p->inicio = p->inicio->proximo;
    free(antigo);
    return valor;
}

int main() {
    int n, i,tamanho, valor = 1, descarte, movida;
    baralho baralho;
    while (n != 0) {
        scanf ("%d", &n);
        for (i = 0; i < n; i++) {
            push(&baralho, valor);
            valor++;
            tamanho++;
        }
        printf ("Discarded cards: ");
        while (tamanho > 2) {
            descarte = pop(&baralho);
            printf ("%d, ", descarte);
            tamanho--;
            movida = pop(&baralho);
            push(&baralho, movida);
        }
        if (tamanho == 2) {
            descarte = pop(&baralho);
            printf ("%d\n", descarte);
            tamanho--;
        } 
        if (tamanho == 1) {
            descarte = pop(&baralho);
            printf ("Remaining card: %d\n", descarte);
        }
    }
}