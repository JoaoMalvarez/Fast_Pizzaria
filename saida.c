/* Nome completo e RA de todos os integrantes:
   - Carolina Yamada                | RA: 10741647
   - Enzo Vasconcellos              | RA: 10736817
   - João Pedro Mazzante Alvarez    | RA: 10723837
   - Jonatas Simonton Gouveia Lage | RA: 10736320
*/

#include <stdio.h>
#include "pizza.h"

void imprimir_rota(int destino, int T[], int R[]) {
    /* TODO (Pessoa 3):
       1. se T[destino] == INFINITO, imprimir que não há rota e retornar
       2. montar um vetor com a rota seguindo R[] de trás para frente:
          comece em destino e vá em R[destino], R[R[destino]]... até chegar na esquina 1
       3. imprimir o vetor invertido (da esquina 1 até o destino) no formato:
            rota até a esquina #3: 1 4 5 6 2 3
            tempo calculado para rota = 7 min. */
      int rota[MAX];
      int tam = 0;
      int atual, i;

      // 1. Se não dá para chegar: 
      if(T[destino] == INFINITO) {
         printf("Não há rotas para a esquina #%d.\n", destino);
         return;
      }

      // 2. Montar o vetor:
      atual = destino;
      while (atual != -1) {
         rota[tam] = atual;
         tam++;
         atual = R[atual];
      }

      // 3. Imprime a lista:
      printf("rota até a esquina #%d:", destino);
      for(i = tam - 1; i >= 0; i--) {
         printf(" %d", rota[i]);
      }
      printf("\n");

      // 4. Imprime o tempo:
      printf("tempo calculado para rota = %d min.\n", T[destino]);
}


