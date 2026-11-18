/* Nome completo e RA de todos os integrantes:
   - Carolina Yamada                | RA: 10741647
   - Enzo                           | RA: 
   - João Pedro Mazzante Alvarez    | RA: 10723837
   - Jonatas Simonton Gouveira Lage | RA: 10736320
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