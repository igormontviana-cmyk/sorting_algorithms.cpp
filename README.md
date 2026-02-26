# Análise de Algoritmos de Ordenação em C

Implementação e comparação de desempenho de seis métodos de ordenação clássicos, desenvolvidos para a disciplina de Estrutura de Dados/Algoritmos. O código conta com um menu interativo que permite gerar arrays dinâmicos variando o **tamanho** (N) e o **estado inicial** (Aleatório, Crescente, Decrescente).

## Resultados de Desempenho (Estado Aleatório)

Os testes abaixo comprovam na prática o custo computacional. Ao dobrar o tamanho do vetor (de 10k para 20k), nota-se que os algoritmos O(N²) quadruplicam seu tempo de execução, enquanto os logarítmicos se mantêm estáveis.

| Algoritmo | Complexidade | Tempo N = 10.000 | Tempo N = 20.000 |
|---|---|---|---|
| **Quick Sort** | O(N log N) | 0.00 ms | 2.00 ms |
| **Merge Sort** | O(N log N) | 1.00 ms | 3.00 ms |
| **Shell Sort** | Intermediária | 2.00 ms | 2.00 ms |
| **Insertion Sort** | O(N²) | 36.00 ms | 146.00 ms |
| **Selection Sort** | O(N²) | 50.00 ms | 197.00 ms |
| **Bubble Sort** | O(N²) | 91.00 ms | 419.00 ms |

## Conclusão
A diferença de desempenho entre algoritmos quadráticos e logarítmicos é extrema em grandes volumes de dados. Enquanto o Bubble Sort escalou mal (batendo 419ms), o Quick Sort, Merge Sort e Shell Sort ordenaram 20.000 números de forma quase instantânea.
