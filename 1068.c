/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Miguel Matosinhos Machado
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 27/09/2026
Objetivo    : verificar se o numero de parentes em uma operação matematica esta correto.
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    char parentese;
    struct No *proximo;
} No;

typedef struct pilha {
    No *topo;
} pilha;

void push(pilha *p, char c) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        return;
    }
    novo->parentese = c;
    novo->proximo = p->topo;
    p->topo = novo;
}

bool pop(pilha *p) {
    No *antigo;
    if (p->topo == NULL) {
        return false;
    } else {
        antigo = p->topo;
        p->topo = p->topo->proximo;
        free(antigo);
    }
    return true;
}

int main() {
    int i;
    char expressao[10002];
    pilha pilha;
    while (scanf ("%s", expressao) != EOF) {
        pilha.topo = NULL;
        bool erro = false;
        for (i = 0; expressao[i] != '\0'; i++) {
            if (expressao[i] == '(') {
                push(&pilha, expressao[i]);
            } else if (expressao[i] == ')') {
                if (!pop(&pilha)) {
                    erro = true;
                    break;
                }
            }
        } 
        if (erro == true && pilha.topo == NULL) {
            printf ("correct\n");
        } else {
            printf ("incorrect\n");
            while (pilha.topo != NULL) {
                pop(&pilha);
            }
        }
    }
    return 0;
}