/* Nome completo e RA de todos os integrantes */

/* REFERÊNCIAS CONSULTADAS:
   - (livros, artigos, sites, vídeos...)

   LINKS DE COMPARTILHAMENTO DE IA (ChatGPT, Claude etc.):
   - (colar os links aqui)
*/

#include <stdio.h>
#include "pizza.h"

int main(void) {
    int destino, n;
    int mapa[MAX][MAX];
    int T[MAX], R[MAX];

    if (!ler_mapa("pizzaria.txt", &destino, &n, mapa)) {
        printf("Erro ao ler o arquivo pizzaria.txt\n");
        return 1;
    }

    rota_mais_rapida(n, mapa, T, R);
    imprimir_rota(destino, T, R);

    return 0;
}