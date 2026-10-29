# Fast_Pizzaria

## 1 Descrição

O senhor Pedro e a dona Maria abriram a Fast Pizzaria. O horário de funcionamento é das 8:00 ás 23:59, de terça a domingo. As entregas são feitas por um motoboy, que só pode atender no bairro e nas regiões mais próximas. 

Para ter uma previsão estimada do tempo de entrega, o senhor Pedro marcou num mapa o tempo estimado para ir de uma esquina até outra. Uma característica interessante é que, no bairro e nas regiões de atendimento, todas as ruas são de mão única. Quando um pedido é feito por algum cliente, o senhor Pedro anota os dados do pedido e o local de entrega. Dona Maria prepara a pizza e envia para o motoboy realizar a entrega do pedido.

Para atender o pedido dentro do tempo estimado, o motoboy gostaria de receber não somente a esquina de entrega, como também, a rota mais rápida da pizzaria até a esquina onde se deve entregar o pedido.
Como o senhor Pedro é muito curioso, ele começou a procurar na internet uma maneira de criar um programa de computador para planejar rotas eficientes para os locais de entrega. Depois de horas pesquisando, o senhor Pedro finalmente encontrou um algoritmo para otimizar a logística de entrega.
O algoritmo considera que as esquinas de um mapa são identificadas por um números inteiros positivos, com a pizzaria sempre na esquina 0.

### Algoritmo Rota-mais-rapida(M)
> Entrada: o mapa M do bairro e regiões, as suas interligações e tempo para ir de uma esquina a outra.
> Saída: os tempos (vetor T[]) e as rotas mais rápidas (vetor R[]) para ir da esquina 1 até todas as esquinas do mapa M.
> Estrutura auxiliar: Conjunto E que armazena as esquinas do mapa M.
```
    inicializar E com as esquinas de M
    para cada esquina e em E faça
        T[e] = INFINITO
    T[1] = 0 // tempo gasto para ir da esquina 1 até a esquina 1
    enquanto E não estiver vazio faça
        v = uma esquina em E com menor custo no vetor T[]
        E = E - {v} // remova a esquina v de E
    para toda esquina interligada v → e, tal que e eseja em E faça
        se T[e] > T[v] + tempo para ir de v até e então
            T[e] = T[v] + tempo para ir de v até e
    retorna T[]
```

Agora, o senhor Pedro precisa implementar esse algoritmo. Porém, ele não tem a menor ideia de como isso pode ser feito. Você vai ter que ajudá-lo a construir esse programa para encontrar a rota mais rápida.

Observe que o algoritmo não encontra a rota mais rápida (vetor R[]), será necessário modificá-lo, de forma que além do tempos para ir da esquina 1 até as outras esquinas do mapa, o algoritmo agora calcula também a rota mais rápida (vetor R[]).

## 2 Entrada do programa

No seu programa as informações referentes ao bairro e regiões são informadas por um arquivo de entrada, que contém a informação do local de entrega e as informações sobre as vias que não estão interditadas.

> Exemplo de entrada: pizzaria.txt
```
3
6
4 6 3
5 2 4
2 3 1
1 4 2
3 5 1
1 5 4
4 5 1
5 6 1
1 3 8
6 2 2
0
```

A primeira linha do arquivo de entrada consiste em um único inteiro que representa o número da esquina onde deve ser realizada a entrega. Na linha seguinte o número de esquinas que constam no mapa. As linhas seguintes consistem em triplas de inteiros positivos (maiores que zero) separados por espaços em branco que são as esquinas adjacentes das ruas e tempo gasto para ir de uma esquina para outra.

Por exemplo, se a tripla 4 6 3 estiver em uma linha do arquivo, então existe uma rua no sentido da esquina 4 para esquina 6, e para ir da esquina 4 para 6 gasta-se 3 minutos. Como as ruas no mapa são de mão única, assim só podemos ir da esquina 4 para esquina 6, no sentido contrário não é possível. Na última linha do arquivo temos um único 0, indicando que a sequência de ruas foi finalizada.

## 3 Saída do programa

A saída do programa deve listar (na tela do computador) a rota mais rápida da esquina #1 até a esquina onde ocorre a entrega (no exemplo a esquina #3) e informar também qual é o tempo total da rota.

> Exemplo de saída:

<pre>
rota até a esquina #3: 1 4 5 6 2 3
tempo calculado para rota = 7 min.
</pre>

## 4 Compilação

O código-fonte será compilado com o compilador gcc da seguinte forma:
```gcc -o main.exe *.c *.h```

O código compilado será executado na plataforma Windows da seguinte forma:
```main.exe```

> Não é necessário o uso de headers (.h) da linguagem C.

## 5 Observações

O programa entregue será avaliado de acordo com os seguintes itens:
- Grupo: A atividade deve ser realizada em grupo de 2 a 4 pessoas.
- Siga fielmente o enunciado proposto implementado o Algoritmo Rota mais rápida(M) conforme apresentado no enunciado.
- Inclua a identificação do grupo (nome completo e RA de cada integrante) no início de cada arquivo de código, como comentário.
- Inclua todas as referências (livros, artigos, sites, vídeos, entre outros) consultadas para solucionar a atividade como comentário no arquivo .c que contém a main().
- Caso ChatGPT e similares seja usado, incluir como comentário no arquivo '.c' que contém a main() o(s) link(s) de compartilhamento das interações com o serviço.
- Todos os fontes devem necessariamente conter os nomes dos integrantes do grupo.

## 6 Entrega

Compacte o código-fonte (somente arquivos *.c e *.h) no formato zip.

No mesmo arquivo zip, inclua os arquivos de teste que o grupo criou para testar e validar a implementação do programa.

> Atenção: O arquivo zip não deve conter arquivos intermediários e/ou pastas geradas pelo compilador/IDE (ex. arquivos *.exe, replit.nix, etc.).
> Dica do João: use um .gitignore para remover os arquivos intermediários (qualquer dúvida chame o mesmo)

## 7 Avaliação 

A nota da atividade é calculada de acordo com os critérios da tabela a seguir:

| Item Avaliado | Pontuação Máxima |
| --- | --- |
| Execução do programa | até 1,0 ponto |
| Questionário | até 9,0 ponto |
> Tabela 1 - Critérios de avaliação 
---

A tabela a seguir contém critérios de avaliação que podem reduzir a nota final da atividade:

| Item indesejável | Redução de Nota |
| --- | --- |
| O projeto é copia de outro projeto | Projeto é zerado |
| O programa não executa e não gera o executável | Projeto é zerado |
| O programa exige algum arquivo adicional que não está presente | -0,5 pontos  |
| Há erros de compilação e/ou o programa trava durante a execução | -0,5 pontos |
| Não há identificação do grupo no código-fonte. Arquivos enviados em formatos incorretos. Arquivos e/ou pastas intermediárias que são criadas no processo de compilação foram enviadas junto com o código-fonte | Até -1,0 ponto |
> Tabela 2 - Critérios de avaliação 

> Sobre erros de compilação: considere apenas erros. Não há problema se o projeto tiver warnings (embora warnings podem avisar sobre possíveis travamentos em tempo de execução, como loop infinito, divisão por zero, etc.).