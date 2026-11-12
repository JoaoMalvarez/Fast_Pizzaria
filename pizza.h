/* Nome completo e RA de todos os integrantes */

#ifndef PIZZA_H
#define PIZZA_H

#define MAX 100           /* esquinas vão de 1 até n, com n < MAX */
#define INFINITO 1000000

/* Pessoa 1 (leitura.c)
   Lê o arquivo, preenche destino, n e a matriz mapa.
   mapa[i][j] = tempo de i para j (0 = não existe rua).
   Retorna 1 se leu com sucesso e 0 se deu erro. */
int ler_mapa(const char *arquivo, int *destino, int *n, int mapa[MAX][MAX]);

/* Pessoa 2 (rota.c)
   Algoritmo Rota-mais-rapida: preenche T[] (tempos a partir da esquina 1)
   e R[] (predecessor de cada esquina na rota mais rápida). */
void rota_mais_rapida(int n, int mapa[MAX][MAX], int T[], int R[]);

/* Pessoa 3 (saida.c)
   Reconstrói a rota do destino até a esquina 1 usando R[] e imprime
   no formato do enunciado. */
void imprimir_rota(int destino, int T[], int R[]);

#endif