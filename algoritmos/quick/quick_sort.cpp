#include <iostream>
#include "quick_sort.h"

static int particion(std::vector<int32_t> &arr, int left, int right)
{
    int mid = left + (right - left) / 2;

    // Ordenamos temp arr[left], arr[mid], arr[right] para sacar la mediana
    if (arr[left] > arr[mid])
        std::swap(arr[left], arr[mid]);
    if (arr[left] > arr[right])
        std::swap(arr[left], arr[right]);
    if (arr[mid] > arr[right])
        std::swap(arr[mid], arr[right]);
    // ahora mid es la mediana

    std::swap(arr[mid], arr[right]); // ponemos right como pivote
    int32_t pivot = arr[right];

    int i = left - 1; // Índice del elemento más pequeño
    for (int j = left; j <= right - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++; // Incrementa el índice del elemento más pequeño
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[right]); // Coloca el pivote en su lugar correcto
    return i + 1;
}

void quickSort(std::vector<int32_t> &arr, int left, int right)
{
    if (left < right)
    {
        // Se obtiene el índice de partición
        int pi = particion(arr, left, right);
        // Ordenar los elementos antes y después de la partición
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}