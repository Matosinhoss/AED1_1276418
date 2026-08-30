/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Miguel Matosinhos Machado
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 30/08/2026
Objetivo    : Verificar se uma solução de sudoku está correta.
Dificuldade : o real desafio foi entender como percorrer os blocos do sudoku.
Uso de IA   : utilizei a IA para ter algumas ideias para atingir a lógica do programa, além de corrigir certos erros e tentar ideias de codigo. 
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdbool.h>

bool verifica_linha(int sudoku[9][9]) {
    int i, j, k, referencia;
    for (i = 0; i < 9; i++) {
        for (k = 0; k < 9; k++) {
            referencia = sudoku[i][k];
            for (j = k + 1; j < 9; j++) {
                if (referencia == sudoku[i][j]) {
                return false;
                }
            }
        }
    }
    return true;
}
bool verifica_coluna(int sudoku[9][9]) {
    int i, j, k, referencia;
    for (j = 0; j < 9; j++) {
        for (k = 0; k < 9; k++) {
            referencia = sudoku[k][j];
            for (i = k + 1; i < 9; i++) {
                if (referencia == sudoku[i][j]) {
                    return false;
                }
            } 
        }
    }
    return true;
}
bool verifica_bloco (int m[9][9]){
    int i, j, n, x, b, a, d, c;
    for (c=0; c<9; c = c+3){
        for (b=0; b<9; b = b+3){
            for (x=b; x<b+3; x++){ 
                for (a=c; a<c+3; a++){
                    n = m[x][a];
                    for (d=b; d<b+3; d++){
                        for (j=c; j<c+3; j++){
                            if (n == m[d][j] && !(d == x && j == a)) {
                                return false;
                            }    
                        }
                    }
                }
            }
        }
    }
    return true;
}
bool verifica_sudoku(int sudoku[9][9]) {
    return verifica_linha(sudoku) && verifica_coluna(sudoku) && verifica_bloco(sudoku);
}
bool preenche_verifica(int sudoku[9][9]) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            scanf ("%d", &sudoku[i][j]);
            if (sudoku[i][j] < 0 || sudoku[i][j] > 9) {
                return false;
            }
        }
    }
    if (verifica_sudoku(sudoku)) {
        return true;
    }
    return false;
}
int main() {
    int i, n = 0, sudoku[9][9];
    while (n <= 0) {
        scanf ("%d", &n);
    }
    for (i = 1; i <= n; i++) {
        if (preenche_verifica(sudoku)) {
            printf ("Instancia %d\nSIM\n\n", i);
        } else {
            printf ("Instancia %d\nNAO\n\n", i);
        }
    }
    return 0;
}
