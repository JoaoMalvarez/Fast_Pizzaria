# Como compilar e rodar a Fast Pizzaria

Guia rápido para compilar o projeto, rodar o exemplo do enunciado e executar os arquivos de teste.

## Estrutura esperada do projeto

Todos os arquivos `.c` e `.h` precisam ficar **na raiz** (não dentro de `src/`), porque o comando de compilação do enunciado só enxerga a pasta atual.

```
Fast_Pizzaria/
├── main.c
├── leitura.c
├── rota.c
├── saida.c
├── pizza.h
├── pizzaria.txt        (exemplo do enunciado, lido pela main)
├── testes/
│   ├── teste_01_exemplo_enunciado.txt
│   └── ...
├── rodar_testes.bat    (só para uso do grupo, não vai no zip)
├── .gitignore
└── README.md
```

## 1. Abrir o terminal na pasta do projeto

No VS Code: menu **Terminal → New Terminal**. Ele já abre na pasta do projeto.

Confira se está no lugar certo com:

```
dir
```

Tem que listar `main.c`, `pizza.h`, `pizzaria.txt` e os demais arquivos.

## 2. Compilar

Use exatamente o comando do enunciado:

```
gcc -o main.exe *.c *.h
```

- Se não aparecer **erro**, o `main.exe` foi gerado.
- *Warnings* (avisos) não impedem a compilação, só **erros**.
- Se der erro, o `main.exe` antigo continua na pasta e pode enganar. Confira sempre se o `gcc` terminou sem erros antes de rodar.

## 3. Rodar o exemplo padrão

```
main.exe
```

O programa lê o arquivo `pizzaria.txt`. Para o exemplo do enunciado, a saída esperada é:

```
rota até a esquina #3: 1 4 5 6 2 3
tempo calculado para rota = 7 min.
```

## 4. Rodar um teste específico

Isso exige a versão da `main` que aceita o nome do arquivo por argumento:

```c
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
```

Sem argumento, continua lendo `pizzaria.txt`, então o comportamento exigido pelo enunciado não muda. Lembre de manter no topo do `main.c` o cabeçalho com nomes e RAs, o `#include <stdio.h>` e o `#include "pizza.h"` (é nele que `MAX` é definido).

Para rodar um teste:

```
main.exe testes\teste_06_empate.txt
```

## 5. Rodar todos os testes de uma vez

Crie o arquivo `rodar_testes.bat` na raiz do projeto:

```bat
@echo off
gcc -o main.exe *.c *.h
if errorlevel 1 (
    echo Erro de compilacao
    exit /b 1
)

for %%f in (testes\*.txt) do (
    echo ===== %%~nxf
    main.exe %%f
    echo.
)
```

E execute:

```
rodar_testes.bat
```

O script compila, e para cada `.txt` da pasta `testes` mostra o nome do arquivo e a saída do programa. Depois é só comparar com a tabela abaixo.

> O `rodar_testes.bat` é só uma ferramenta do grupo. **Não** coloque no zip de entrega.

## 6. Resultados esperados dos testes

### Casos válidos

| Arquivo | O que testa | Resultado esperado |
|---|---|---|
| `teste_01_exemplo_enunciado` | exemplo do enunciado | `1 4 5 6 2 3`, 7 min |
| `teste_02_destino1` | destino é a própria esquina 1 | `1`, 0 min |
| `teste_03_uma_esquina` | mapa com 1 esquina e nenhuma rua | `1`, 0 min |
| `teste_04_caminho_unico` | só existe um caminho | `1 2 3 4`, 12 min |
| `teste_05_atalho_pior` | rua direta (10 min) é pior que o desvio | `1 2 3`, 2 min |
| `teste_06_empate` | dois caminhos com o mesmo tempo | `1 2 4`, 4 min |
| `teste_07_mao_unica` | existe rua `2→1`, mas não `1→2` | `1 3 2`, 6 min |
| `teste_08_rua_repetida` | mesma rua duas vezes (9 e 3) | `1 2`, 3 min |
| `teste_09_ciclo` | mapa com ciclo `1→2→3→1` | `1 2 3 4`, 3 min |
| `teste_10_rota_atualizada` | o `R[]` é trocado no meio do caminho | `1 3 2 4 5`, 4 min |
| `teste_11_limite_99_esquinas` | maior mapa que o `MAX` aceita | rota `1..99`, 98 min |

### Destino inalcançável (mensagem de "sem rota")

| Arquivo | O que testa |
|---|---|
| `teste_12_inalcancavel` | nenhuma rua chega na esquina 4 |
| `teste_13_sem_ruas` | o arquivo só tem o `0` final |
| `teste_14_so_chega_voltando` | a única rua vai no sentido contrário (`3→2`) |

### Entradas inválidas (mensagem de erro, sem travar)

| Arquivo | O que testa |
|---|---|
| `teste_15_erro_sem_zero_final` | falta o `0` final |
| `teste_16_erro_destino_fora` | destino 9 num mapa de 6 esquinas |
| `teste_17_erro_esquina_fora` | rua com esquina 7 num mapa de 3 |
| `teste_18_erro_tempo_zero` | tempo igual a zero |
| `teste_19_erro_tempo_negativo` | tempo negativo |
| `teste_20_erro_n_invalido` | número de esquinas igual a 0 |
| `teste_21_erro_tripla_incompleta` | tripla sem o tempo (`1 2`) |
| `teste_22_erro_arquivo_vazio` | arquivo vazio |

Nos testes de erro aparecem duas mensagens: a de `leitura.c` (o motivo) e a da `main` (aviso geral). Isso é esperado.

## 7. Problemas comuns

| Problema | Causa provável | Solução |
|---|---|---|
| `gcc` não é reconhecido | compilador não instalado ou fora do PATH | Instale o MinGW/MSYS2 ou adicione a pasta `bin` dele ao PATH do Windows |
| `main.exe` não é reconhecido | terminal na pasta errada | Use `cd` até a pasta do projeto |
| Erro ao ler o arquivo | `pizzaria.txt` fora da pasta de execução | Mantenha o `pizzaria.txt` na raiz e rode de lá |
| `MAX` não está definido | `#include "pizza.h"` faltando, comentário de cabeçalho sem `*/`, ou `pizza.h` em outra pasta | Confira o topo do `main.c` e a localização do `pizza.h` |
| Sublinhado vermelho no VS Code, mas o `gcc` compila | IntelliSense desatualizado | Recarregue: `Ctrl+Shift+P` → "Developer: Reload Window" |
| Acentos quebrados (`atÃ©`, `at?`) | codificação do terminal | Rode `chcp 65001` antes do `main.exe` |
| Rota com número estranho no começo, ou saída toda numa linha | bugs no `saida.c` (`for` começando em `tam`, `"/n"` no lugar de `"\n"`) | Corrija o `saida.c` (veja abaixo) |

### Trecho correto do `saida.c`

```c
// 3. Imprime a lista:
printf("rota até a esquina #%d:", destino);
for (i = tam - 1; i >= 0; i--) {
    printf(" %d", rota[i]);
}
printf("\n");

// 4. Imprime o tempo:
printf("tempo calculado para rota = %d min.\n", T[destino]);
```

E a mensagem de destino inalcançável, também com `\n` no final:

```c
printf("Não há rotas para a esquina #%d.\n", destino);
```

## 8. Checklist antes de entregar

- [ ] Cabeçalho com **nome completo e RA** de todos em cada arquivo `.c` e `.h`
- [ ] Referências e links de IA como comentário no `main.c`
- [ ] `gcc -o main.exe *.c *.h` compila sem **erros**
- [ ] `main.exe` com o `pizzaria.txt` do enunciado imprime exatamente a saída esperada
- [ ] Todos os testes de `testes/` rodam sem travar
- [ ] Zip com **somente** `*.c`, `*.h`, `pizzaria.txt` e a pasta `testes/`
- [ ] Sem `main.exe`, `.gitignore`, `.git`, `README.md`, `rodar_testes.bat` nem pastas de IDE dentro do zip
- [ ] Todo mundo do grupo entende o código inteiro (9 dos 10 pontos vêm do questionário)