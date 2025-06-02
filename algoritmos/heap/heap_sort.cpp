#include "heap_sort.h"
#include <algorithm> //Esto para el std::swap
#include <vector>
#include <cstdint> // Para el tipo int32_t

// Se reajusta el subarbol con raiz en i en un arreglo de tamaño n
// para que cumpla la propiedad de max-heap

static void heapify(std::vector<int32_t> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;  // Indice del hijo izquierdo
    int right = 2 * i + 2; // Indice del hijo derecho

    // Si el hijo izquierdo es mayor que el nodo actual
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    // Si el hijo derecho es mayor que el nodo actual
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    // Si el nodo actual no es el mayor, intercambiamos y continuamos heapificando
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int32_t> &arr)
{
    int n = static_cast<int>(arr.size());

    // Construimos el max-heap
    // Comenzamos desde el ultimno nodo padre hacia atras
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Extraemos los elementos del heap uno por uno
    for (int i = n - 1; i >= 0; i--)
    {
        // Mover el nodo actual a la posicion final
        std::swap(arr[0], arr[i]);

        // Llamamos heapify en el heap reducido
        heapify(arr, i, 0);
    }
}