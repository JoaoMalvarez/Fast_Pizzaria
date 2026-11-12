/* Nome completo e RA de todos os integrantes */
#include <stdio.h>
#include "pizza.h"

int ler_mapa(const char *arquivo, int *destino, int *n, int mapa[MAX][MAX]) {
    /* TODO (Pessoa 1):
       1. abrir o arquivo com fopen (tratar arquivo inexistente)
       2. ler o destino (1ª linha) e n (2ª linha)
       3. zerar a matriz mapa
       4. ler triplas "origem destino tempo" até encontrar o 0 final
          e fazer mapa[origem][destino] = tempo
       5. fechar o arquivo com fclose
       6. retornar 1 se deu certo, 0 se deu erro */

    *destino = 0;
    *n = 0;
    return 1;
}