#include <iostream>
#include "merge_sort.h"

// Funcion aux que mexcla dos subarrays ordenados arr[l..m] y arr[m+1..r]
static void merge(std::vector<int32_t> &arr, int l, int m, int r)
{
    int n1 = m - l + 1; // Tamaño del subarray izquierdo
    int n2 = r - m;     // Tamaño del subarray derecho

    // creo los vectores temp
    std::vector<int32_t> L(n1);
    std::vector<int32_t> R(n2);

    // Copiamos los datos a L y R
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l; // Índice inicial del subarray mezclado

    // Mezclamos los subarrays L y R
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    // Copiamos los elementos restantes de L, si los hay
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    // Copiamos los elementos restantes de R, si los hay
    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

void mergeSort(std::vector<int32_t> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // Encuentra el punto medio
        // Ordena la primera y segunda mitad
        mergeSort(arr, left, mid);      // Ordena la mitad izq
        mergeSort(arr, mid + 1, right); // Ordena la mitad derecha
        merge(arr, left, mid, right);   // Mezcla las dos mitades ordenadas
    }
}