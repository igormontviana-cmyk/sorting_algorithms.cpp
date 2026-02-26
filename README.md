# Análise de Algoritmos de Ordenação em C

Implementação e comparação de desempenho de seis métodos de ordenação clássicos, desenvolvidos para a disciplina de Estrutura de Dados/Algoritmos.

## 📊 Resultados de Desempenho (N = 20.000)

Os algoritmos ordenaram exatamente o mesmo vetor desordenado contendo 20.000 números inteiros aleatórios.

| Algoritmo | Complexidade | Tempo de Execução |
|---|---|---|
| **Bubble Sort** | O(N²) | 395.00 ms |
| **Selection Sort** | O(N²) | 194.00 ms |
| **Insertion Sort** | O(N²) | 138.00 ms |
| **Merge Sort** | O(N log N) | 4.00 ms |
| **Shell Sort** | Intermediária | 3.00 ms |
| **Quick Sort** | O(N log N) | 2.00 ms |

## 💡 Conclusão
A diferença de desempenho entre algoritmos quadráticos e logarítmicos é gritante em grandes volumes de dados. Enquanto o Bubble Sort levou quase 400ms fazendo trocas constantes, o Quick Sort e o Shell Sort ordenaram a mesma quantidade de dados quase instantaneamente (2 a 3ms).
