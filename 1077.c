/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Miguel Matosinhos Machado
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 01/10/2026
Objetivo    : Ler uma operação no formatp infixo e transformar em posfixo.
Dificuldade : 
Uso de IA   : 
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct simbolo {
    char caractere;
    struct simbolo *proximo;
} simbolo;

typedef struct pilha{
    simbolo *topo;
} pilha;

void push(pilha *p, char s) {
    simbolo *novo = (simbolo*)malloc(sizeof(simbolo));
    if (novo == NULL) {
        return;
    }
    novo->caractere = s;
    novo->proximo = p->topo;
    p->topo = novo;
}

//pop que registra o caractere retirado
int pop(pilha *p) {
    char s;
    simbolo *antigo;
    if (p->topo == NULL) {
        return 0;
    }
    s = p->topo->caractere;
    antigo = p->topo;
    p->topo = p->topo->proximo;
    free(antigo);
    return s;
}

//regula a prioridade dos sinais e numeros
int prioridade(char sinal) {
    if (sinal == '^') {
        return 3;
    } else if (sinal == '*' || sinal == '/') {
        return 2;
    } else if (sinal == '+' || sinal == '-') {
        return 1;
    } else {
        return 0; 
    }
}

int main() {
    int i, j, n, tam;
    char expressao[302], caractere;
    pilha pilha;
    scanf ("%d", &n);
    getchar();
    for (i = 0; i < n; i++) {
        pilha.topo = NULL;
        fgets (expressao, sizeof(expressao), stdin);
        tam = strlen(expressao);
        //retira o \n do final da expressao
        if (tam > 0 && expressao[tam - 1] == '\n') {
            expressao[tam - 1] = '\0';
            tam--;
        }
        for (j = 0; j < tam; j++) {
            // imprime o caractere imediatamente se for um numero ou letra
            if (isalpha(expressao[j]) || isdigit(expressao[j])) {
                printf ("%c", expressao[j]);
            } else if (expressao[j] == '(') { //guarda o ( como barreira até achar o )
                push(&pilha, expressao[j]);
            } else if (expressao[j] == '^' || expressao[j] == '*' || expressao[j] == '/' || expressao[j] == '+' || expressao[j] == '-') { //imprime o sinal segundo a ordem de prioridade
                while (pilha.topo != NULL && (expressao[j] != '^' && prioridade(expressao[j]) <= prioridade(pilha.topo->caractere)) 
                || (expressao[j] == '^' && prioridade(expressao[j]) < prioridade(pilha.topo->caractere))) {
                    caractere = pop(&pilha);
                    printf ("%c", caractere);
                } push(&pilha, expressao[j]);
            } else if (expressao[j] == ')') {
                while (pilha.topo != NULL && pilha.topo->caractere != '(') {
                    caractere = pop(&pilha);
                    printf ("%c", caractere);
                } if (pilha.topo != NULL && pilha.topo->caractere == '(') {
                    pop(&pilha);
                }
            }
        }
        //limpa o restante da pilha
        while (pilha.topo != NULL) {
            caractere = pop(&pilha);
            printf ("%c", caractere);
        }
        printf ("\n");
    }
    return 0;
}