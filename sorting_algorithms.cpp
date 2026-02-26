#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Para usar a funcao clock() e medir o desempenho

// Funcoes Auxiliares 

// Imprime o array (uso mais para debug se precisar)
void imprimirArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Garante que todo algoritmo ordene exatamente os mesmos dados desordenados
void copiarArray(int origem[], int destino[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

// Gera o array de testes com valores aleatorios de 0 a 9999
void gerarArrayAleatorio(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 10000; 
    }
}

// Criei para testar o melhor caso (array ja ordenado)
void gerarArrayCrescente(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = i;
    }
}

// Criei para testar o pior caso critico (array invertido)
void gerarArrayDecrescente(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

//  1. Bubble Sort 
// Implementei o padrao. Complexidade O(N^2), costuma ser o mais lento.
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//  2. Selection Sort 
// Busca o menor e joga pro inicio. Tambem e O(N^2).
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}

// 3. Insertion Sort 
// Insere na posicao certa (como ordenar cartas). O(N^2) no pior caso.
void insertionSort(int arr[], int n) {
    int i, j, chave;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

//  4. Quick Sort 
// Escolhi o ultimo elemento como pivo para particionar.
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j, temp;
    
    for (j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Chamada recursiva O(N log N). Geralmente o mais rapido.
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//  5. Merge Sort
// Usa arrays temporarios (L e R) para fundir as partes ordenadas.
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }

    free(L); free(R); // Boas praticas: limpando a memoria
}

// Divide recursivamente no meio. O(N log N).
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

//  6. Shell Sort 
// Evolucao do Insertion Sort dividindo os "gaps". Bem eficiente.
void shellSort(int arr[], int n) {
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// Menu e Medicao de Tempo 
// Isolei a medicao aqui para deixar o main limpo e focado no menu
void testarAlgoritmo(int opcao, int arrOriginal[], int n) {
    int *arrTeste = (int*)malloc(n * sizeof(int));
    copiarArray(arrOriginal, arrTeste, n);

    clock_t inicio, fim;
    double tempo_ms;

    printf("\nOrdenando array de %d elementos...\n", n);
    
    inicio = clock();
    switch (opcao) {
        case 1: bubbleSort(arrTeste, n); printf("Algoritmo: Bubble Sort\n"); break;
        case 2: selectionSort(arrTeste, n); printf("Algoritmo: Selection Sort\n"); break;
        case 3: insertionSort(arrTeste, n); printf("Algoritmo: Insertion Sort\n"); break;
        case 4: quickSort(arrTeste, 0, n - 1); printf("Algoritmo: Quick Sort\n"); break;
        case 5: mergeSort(arrTeste, 0, n - 1); printf("Algoritmo: Merge Sort\n"); break;
        case 6: shellSort(arrTeste, n); printf("Algoritmo: Shell Sort\n"); break;
    }
    fim = clock(); 

    tempo_ms = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %.2f ms\n", tempo_ms);

    free(arrTeste); 
}

int main() {
    srand(time(NULL));
    
    // Inicia com 20.000 para a diferenca de tempo ficar bem visivel
    int n = 20000; 
    int estado = 1; // 1-Aleatorio, 2-Crescente, 3-Decrescente
    
    // Alocacao dinamica para evitar stack overflow com arrays grandes
    int *arrOriginal = (int*)malloc(n * sizeof(int));
    gerarArrayAleatorio(arrOriginal, n);

    int opcao;
    
    do {
        printf("\n===================================\n");
        printf("       MENU DE ORDENACAO \n");
        printf("===================================\n");
        printf("Configuracao atual: N = %d | Estado = %s\n", n, 
               estado == 1 ? "Aleatorio" : (estado == 2 ? "Crescente" : "Decrescente"));
        printf("-----------------------------------\n");
        printf("1. Testar Bubble Sort\n");
        printf("2. Testar Selection Sort\n");
        printf("3. Testar Insertion Sort\n");
        printf("4. Testar Quick Sort\n");
        printf("5. Testar Merge Sort\n");
        printf("6. Testar Shell Sort\n");
        printf("7. Testar TODOS para comparar\n");
        // Opcao extra adicionada para cobrir o requisito de testar diferentes tamanhos e estados
        printf("8. Mudar TAMANHO e ESTADO do Array\n"); 
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 6) {
            testarAlgoritmo(opcao, arrOriginal, n);
        } else if (opcao == 7) {
            int i;
            printf("\n--- COMPARATIVO DE DESEMPENHO ---\n");
            for (i = 1; i <= 6; i++) {
                testarAlgoritmo(i, arrOriginal, n);
            }
        } else if (opcao == 8) {
            printf("\nDigite o novo tamanho (ex: 1000, 10000, 50000): ");
            scanf("%d", &n);
            printf("Escolha o estado inicial (1-Aleatorio, 2-Crescente, 3-Decrescente): ");
            scanf("%d", &estado);
            
            // Realoca a memoria com o novo tamanho escolhido pelo usuario
            free(arrOriginal);
            arrOriginal = (int*)malloc(n * sizeof(int));
            
            // Preenche de acordo com a escolha
            if (estado == 1) gerarArrayAleatorio(arrOriginal, n);
            else if (estado == 2) gerarArrayCrescente(arrOriginal, n);
            else if (estado == 3) gerarArrayDecrescente(arrOriginal, n);
            
            printf("Array atualizado com sucesso!\n");
        } else if (opcao != 0) {
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    free(arrOriginal); // Liberando a memoria antes de finalizar o programa
    return 0;
}
