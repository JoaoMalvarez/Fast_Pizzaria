/* Nome completo e RA de todos os integrantes:
   - Carolina Yamada                | RA: 10741647
   - Enzo Vasconcellos              | RA: 10736817
   - João Pedro Mazzante Alvarez    | RA: 10723837
   - Jonatas Simonton Gouveia Lage | RA: 10736320
*/
#include <stdio.h>
#include "pizza.h"

int ler_mapa(const char *arquivo, int *destino, int *n, int mapa[MAX][MAX]) {
   
   FILE *f;
   int i, j;
   int origem, dest, tempo;
   int linha = 2;

   *destino = 0;
   *n = 0;
   
   // 1. Abrir o arquivo com fopen (tratar arquivo inexistente)
   f = fopen(arquivo, "r");
   if (f == NULL) {
      fprintf(stderr, "Erro: não foi possivel abrir o arquivo '%s'.\n", arquivo);
      return 0;
   }

   // 2. Ler o destino (1ª linha) e n (2ª linha)
   if (fscanf(f, "%d", destino) != 1 || fscanf(f, "%d", n) != 1) {
      fprintf(stderr, "Erro: cabeçalho inválido (Esperado: destino e número de esquinas).\n");
      fclose(f);
      return 0;
   }
   if (*n < 1 || *n >= MAX) {
      fprintf(stderr, "Erro: número de esquinas inválido (%d). Deve estar entre 1 e %d.\n", *n, MAX - 1);
      fclose(f);
      return 0;
   }
   if (*destino < 1 || *destino > *n) {
      fprintf(stderr, "Erro: esquina de entrega %d fora do intervalo 1..%d.\n", *destino, *n);
      fclose(f);
      return 0;
   }

   // 3. Zerar a matriz mapa
      for (i = 0; i < MAX; i++) {
         for (j = 0; j < MAX; j++) {
            mapa[i][j] = 0;
      }
   }

   // 4. Ler triplas "origem destino tempo" até encontrar o 0 final e fazer mapa[origem][destino] = tempo
      while (1) {
         linha++;
         if (fscanf(f, "%d", &origem) != 1) {
            fprintf(stderr, "Erro: fim inesperado do arquivo (faltou o 0 final?) perto da linha %d.\n", linha);
            fclose(f);
            return 0;
         }
         if (origem == 0) {
            break; // Fim da lista de ruas
         }
         if (fscanf(f, "%d %d", &dest, &tempo) != 2) {
            fprintf(stderr, "Erro: tripla incompleta ou inválida na linha %d.\n", linha);
            fclose(f);
            return 0;
         }
         if (origem < 1 || origem > *n || dest < 1 || dest > *n) {
            fprintf(stderr, "Erro: esquina fora do intervalo 1..%d na linha %d (%d %d %d).\n", *n, linha, origem, dest, tempo);
            fclose(f);
            return 0;
         }
         if (tempo <= 0) {
            fprintf(stderr, "Erro: o tempo deve ser maior que zero na linha %d.\n", linha);
            fclose(f);
            return 0;
         }

         // Se a mesma rua aparecer repetida, fica com o menor tempo
         if (mapa[origem][dest] == 0 || tempo < mapa[origem][dest]) {
            mapa[origem][dest] = tempo;
         }
      }

   // 5. fechar o arquivo com fclose
   fclose(f);
   
   // 6. retornar 1 se deu certo, 0 se deu erro
   return 1;
}
