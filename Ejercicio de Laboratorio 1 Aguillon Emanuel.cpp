#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void genArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int searchSeq(int arr[], int n, int elem) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == elem) {
            return i;
        }
    }
    return -1;
}

void sortArr(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int arrOrig[SIZE];
    int arrUnord[SIZE];
    int elem, index;

    genArr(arrOrig, SIZE);
    for (int i = 0; i < SIZE; i++) {
        arrUnord[i] = arrOrig[i];
    }

    printf("Arreglo original:\n");
    printArr(arrOrig, SIZE);

    clock_t start, end;

    // Medir el tiempo de ejecución para la búsqueda secuencial en el arreglo original
    start = clock();
    elem = arrOrig[0];
    index = searchSeq(arrOrig, SIZE, elem);
    end = clock();
    
    if (index != -1) {
        printf("Elemento %d encontrado en la posición %d\n", elem, index);
    } else {
        printf("Elemento %d no encontrado en el arreglo\n", elem);
    }

    double tiempoBusquedaSecuencial = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo de búsqueda secuencial en el arreglo original: %f segundos\n", tiempoBusquedaSecuencial);

    // Medir el tiempo de ejecución para ordenar el arreglo original
    start = clock();
    sortArr(arrOrig, SIZE);
    end = clock();

    printf("\nArreglo ordenado:\n");
    printArr(arrOrig, SIZE);

    double tiempoOrdenamiento = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo de ordenamiento del arreglo original: %f segundos\n", tiempoOrdenamiento);

    // Medir el tiempo de ejecución para la búsqueda secuencial en el arreglo ordenado con entrada del usuario
    do {
        printf("Ingrese un número para buscar en el arreglo ordenado: ");
        scanf("%d", &elem);

        start = clock();
        index = searchSeq(arrOrig, SIZE, elem);
        end = clock();

        if (index != -1) {
            printf("Elemento %d encontrado en la posición %d\n", elem, index);
        } else {
            printf("Elemento %d no encontrado en el arreglo ordenado. Por favor, ingrese otro número.\n", elem);
        }

        double tiempoBusquedaSecuencialUsuario = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Tiempo de búsqueda secuencial en el arreglo ordenado (con entrada del usuario): %f segundos\n", tiempoBusquedaSecuencialUsuario);

    } while (index == -1);

    // Medir el tiempo de ejecución para la búsqueda secuencial en el arreglo desordenado con entrada del usuario
    printf("\nArreglo desordenado:\n");
    printArr(arrUnord, SIZE);

    do {
        printf("Ingrese un número para buscar en el arreglo desordenado: ");
        scanf("%d", &elem);

        start = clock();
        index = searchSeq(arrUnord, SIZE, elem);
        end = clock();

        if (index != -1) {
            printf("Elemento %d encontrado en la posición %d\n", elem, index);
        } else {
            printf("Elemento %d no encontrado en el arreglo desordenado. Por favor, ingrese otro número.\n", elem);
        }

        double tiempoBusquedaSecuencialUsuarioDesordenado = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Tiempo de búsqueda secuencial en el arreglo desordenado (con entrada del usuario): %f segundos\n", tiempoBusquedaSecuencialUsuarioDesordenado);

    } while (index == -1);

    return 0;
}

