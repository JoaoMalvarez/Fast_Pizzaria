/* Nome completo e RA de todos os integrantes:
   - Carolina Yamada                | RA: 10741647
   - Enzo Vasconcellos              | RA: 10736817
   - João Pedro Mazzante Alvarez    | RA: 10723837
   - Jonatas Simonton Gouveia Lage | RA: 10736320
*/

#include <stdio.h>
#include "pizza.h"

/* Algoritmo Rota-mais-rapida(M) do enunciado (na prática, o algoritmo de Dijkstra).

   Parâmetros:
     n     -> número de esquinas do mapa (esquinas vão de 1 até n)
     mapa  -> matriz de adjacência: mapa[i][j] = tempo para ir de i até j
              (0 significa que NÃO existe rua de i para j; as ruas são de mão única)
     T     -> (saída) T[e] = menor tempo para ir da esquina 1 até a esquina e
     R     -> (saída) R[e] = esquina anterior a e na rota mais rápida
              (R[e] == -1 se e é a esquina 1 ou se e é inalcançável)

   Observação: apesar do texto do enunciado falar que a pizzaria fica na esquina 0,
   o algoritmo parte da esquina 1 (T[1] = 0), conforme o pseudocódigo. */
void rota_mais_rapida(int n, int mapa[MAX][MAX], int T[], int R[]) {
    /* Conjunto E do pseudocódigo: em_E[e] == 1 significa que a esquina e
       ainda está em E (ainda não foi "fechada"); 0 significa que já saiu de E. */
    int em_E[MAX];
    int restantes;   /* quantidade de esquinas que ainda estão em E */
    int e, v, i;

    /* "inicializar E com as esquinas de M": todas as esquinas 1..n entram em E.
       "para cada esquina e em E faça T[e] = INFINITO":
       ainda não conhecemos nenhum caminho, então o custo é infinito.
       R[e] = -1 indica "sem predecessor" (linha nova para guardar a rota). */
    restantes = 0;
    for (e = 1; e <= n; e++) {
        em_E[e] = 1;
        T[e] = INFINITO;
        R[e] = -1;
        restantes++;
    }

    /* T[1] = 0: o tempo para ir da esquina 1 até ela mesma é zero. */
    T[1] = 0;

    /* "enquanto E não estiver vazio faça" */
    while (restantes > 0) {

        /* v = uma esquina em E com menor custo no vetor T[].
           Busca linear: percorre só as esquinas que ainda estão em E. */
        v = -1;
        for (i = 1; i <= n; i++) {
            if (em_E[i] && (v == -1 || T[i] < T[v])) {
                v = i;
            }
        }

        /* Se o menor T entre as esquinas restantes é INFINITO, nenhuma delas
           pode ser alcançada a partir da esquina 1, então não há mais o que
           relaxar e podemos parar o laço. */
        if (T[v] == INFINITO) {
            break;
        }

        /* E = E - {v}: remove v do conjunto. O T[v] dele já é o definitivo. */
        em_E[v] = 0;
        restantes--;

        /* Para toda esquina e interligada por uma rua v -> e, com e ainda em E:
           tentamos "relaxar" a aresta, isto é, ver se passar por v é mais rápido. */
        for (e = 1; e <= n; e++) {
            if (em_E[e] && mapa[v][e] > 0) {      /* existe rua v -> e */
                if (T[e] > T[v] + mapa[v][e]) {
                    T[e] = T[v] + mapa[v][e];     /* novo menor tempo até e */
                    R[e] = v;                     /* LINHA NOVA: guarda que chegamos em e vindo de v */
                }
            }
        }
    }
}
