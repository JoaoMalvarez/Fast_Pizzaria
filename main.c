/* Nome completo e RA de todos os integrantes:
   - Carolina Yamada                | RA: 10741647
   - Enzo Vasconcellos              | RA: 10736817
   - João Pedro Mazzante Alvarez    | RA: 10723837
   - Jonatas Simonton Gouveia Lage | RA: 10736320
*/

#include <stdio.h>
#include "pizza.h"

int main(int argc, char *argv[]) {
    int destino, n;
    int mapa[MAX][MAX];
    int T[MAX], R[MAX];
    const char *arquivo = "pizzaria.txt";

    if (argc > 1) {
        arquivo = argv[1];
    }

    if (!ler_mapa(arquivo, &destino, &n, mapa)) {
        printf("Erro ao ler o arquivo %s\n", arquivo);
        return 1;
    }

    rota_mais_rapida(n, mapa, T, R);
    imprimir_rota(destino, T, R);

    return 0;
}
