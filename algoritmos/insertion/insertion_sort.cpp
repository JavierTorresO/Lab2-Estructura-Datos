//contiene la implementación
#include <iostream>
#include "insertion_sort.h"

void insertionSort(std::vector<int32_t>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int32_t key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}

//Insertion Sort: recorre el arreglo y en cada paso toma un elemento y lo inserta en la posición correcta dentro de la parte ya ordenada a su izquierda, comparando hacia atrás y desplazando elementos si es necesario
//Mejor caso: arreglo ordenado ascendente( O(n) )
//Peor caso: arreglo ordenado descendente( O(n^2) )