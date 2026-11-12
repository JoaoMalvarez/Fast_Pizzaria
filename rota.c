/* Nome completo e RA de todos os integrantes */
#include <stdio.h>
#include "pizza.h"

void rota_mais_rapida(int n, int mapa[MAX][MAX], int T[], int R[]) {
    /* TODO (Pessoa 2), seguindo o pseudocódigo do enunciado:
       1. criar o conjunto E com as esquinas 1..n (ex.: vetor em_E[])
       2. para cada esquina e: T[e] = INFINITO e R[e] = -1
       3. T[1] = 0
       4. enquanto E não estiver vazio:
            - v = esquina em E com menor T[v]
            - remover v de E
            - para cada e em E com mapa[v][e] > 0 (existe rua v -> e):
                se T[e] > T[v] + mapa[v][e]:
                    T[e] = T[v] + mapa[v][e]
                    R[e] = v      <- linha nova que guarda a rota
       Cuidado: se o menor T[v] for INFINITO, as esquinas restantes são
       inalcançáveis e dá para parar o laço. */
}