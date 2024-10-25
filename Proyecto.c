#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para generar números aleatorios en un rango específico
int generarNumeroAleatorio(int rangoMin, int rangoMax) {
    return rand() % (rangoMax - rangoMin + 1) + rangoMin;
}

// Función para imprimir una lista de números
/*void imprimirLista(int lista[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}
*/


// Implementación del algoritmo Counting Sort
void countingSort(int lista[], int n, int rangoMax) {
    int* contador = (int*)malloc((rangoMax + 1) * sizeof(int));
    int* resultado = (int*)malloc(n * sizeof(int));

    for (int i = 0; i <= rangoMax; i++) {
        contador[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        contador[lista[i]]++;
    }

    for (int i = 1; i <= rangoMax; i++) {
        contador[i] += contador[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        resultado[contador[lista[i]] - 1] = lista[i];
        contador[lista[i]]--;
    }

    for (int i = 0; i < n; i++) {
        lista[i] = resultado[i];
    }

    free(contador);
    free(resultado);
}

// Implementación del algoritmo Insertion Sort
void insertionSort(int lista[], int n) {
    for (int i = 1; i < n; i++) {
        int valorActual = lista[i];
        int j = i - 1;

        while (j >= 0 && lista[j] > valorActual) {
            lista[j + 1] = lista[j];
            j--;
        }

        lista[j + 1] = valorActual;
    }
}

// Implementación del algoritmo Selection Sort
void selectionSort(int lista[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int indiceMinimo = i;

        for (int j = i + 1; j < n; j++) {
            if (lista[j] < lista[indiceMinimo]) {
                indiceMinimo = j;
            }
        }

        int temp = lista[i];
        lista[i] = lista[indiceMinimo];
        lista[indiceMinimo] = temp;
    }
}

// Implementación del algoritmo Bubble Sort
void bubbleSort(int lista[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

// Función auxiliar para el Quick Sort
int partition(int lista[], int low, int high) {
    int pivote = lista[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (lista[j] < pivote) {
            i++;
            int temp = lista[i];
            lista[i] = lista[j];
            lista[j] = temp;
        }
    }

    int temp = lista[i + 1];
    lista[i + 1] = lista[high];
    lista[high] = temp;

    return i + 1;
}

// Implementación del algoritmo Quick Sort
void quickSort(int lista[], int low, int high) {
    if (low < high) {
        int indicePivote = partition(lista, low, high);
        quickSort(lista, low, indicePivote - 1);
        quickSort(lista, indicePivote + 1, high);
    }
}

int main() {
    int rangoMin = 0;
    int rangoMax = 1000;
    int n = 1000;

    // Crear lista de números aleatorios
    int* lista = (int*)malloc(n * sizeof(int));

    // Generar números aleatorios en la lista
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        lista[i] = generarNumeroAleatorio(rangoMin, rangoMax);
    }

    /*
    printf("Lista original:\n");
    imprimirLista(lista, n);
    */

    clock_t inicio, fin;
    double tiempo;

    // Counting Sort
    inicio = clock();
    countingSort(lista, n, rangoMax);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("\nCounting Sort:\n");
    /*
    imprimirLista(lista, n);
    */

    printf("Tiempo: %.6f segundos\n", tiempo);

   
    for (int i = 0; i < n; i++) {
        lista[i] = generarNumeroAleatorio(rangoMin, rangoMax);
    }
    // Insertion Sort
    inicio = clock();
    insertionSort(lista, n);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("\nInsertion Sort:\n");

   /* imprimirLista(lista, n); */
    printf("Tiempo: %.6f segundos\n", tiempo);

   
    for (int i = 0; i < n; i++) {
        lista[i] = generarNumeroAleatorio(rangoMin, rangoMax);
    }
    // Selection Sort
    inicio = clock();
    selectionSort(lista, n);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("\nSelection Sort:\n");
    
    /*imprimirLista(lista, n);*/

    printf("Tiempo: %.6f segundos\n", tiempo);

    for (int i = 0; i < n; i++) {
        lista[i] = generarNumeroAleatorio(rangoMin, rangoMax);
    }
    // Bubble Sort
    inicio = clock();
    bubbleSort(lista, n);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("\nBubble Sort:\n");

    /*imprimirLista(lista, n);*/
    printf("Tiempo: %.6f segundos\n", tiempo);

    for (int i = 0; i < n; i++) {
        lista[i] = generarNumeroAleatorio(rangoMin, rangoMax);
    }
    // Quick Sort
    inicio = clock();
    quickSort(lista, 0, n - 1);
    fin = clock();
    tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;
    printf("\nQuick Sort:\n");
    /*imprimirLista(lista, n);*/
    
    printf("Tiempo: %.6f segundos\n", tiempo);

    free(lista);

    return 0;
}