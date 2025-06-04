#include <iostream>
#include "nuestro_algoritmo.h"

/* Decidimos implementar el algoritmo Radix sort como nuestro algoritmo personalizado.
 * Este algoritmo es eficiente para ordenar números enteros y funciona bien con datos
 * que tienen un rango limitado, como los números de 32 bits.
 *
 * Radix sort es un algoritmo no comparativo que ordena los números dígito por dígito,
 * comenzando desde el dígito menos significativo hasta el más significativo.
 *
 * Aquí se implementa una versión básica de Radix sort.
 */

static void coutingSortPorByte(std::vector<int32_t> &arr, int byteIdx)
{
    const int Radix = 256;
    int n = static_cast<int>(arr.size());
    std::vector<int> output(n);
    int count[Radix] = {0};

    // Contar ocurrencias de cada valor en el byte actual
    for (int i = 0; i < n; i++)
    {
        int byteValue = (arr[i] >> (8 * byteIdx)) & 0xFF; // Extraer el byte correspondiente
        ++count[byteValue];
    }

    // acumular contadores
    for (int i = 1; i < Radix; ++i)
    {
        count[i] += count[i - 1];
    }

    // Construir el arreglo de salida (atras a delante)
    for (int i = n - 1; i >= 0; i--)
    {
        int byteValue = (arr[i] >> (8 * byteIdx)) & 0xFF; // Extraer el byte correspondiente
        output[count[byteValue] - 1] = arr[i];
        --count[byteValue];
    }
    // Copiar el arreglo de salida al arreglo original
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void propioSort(std::vector<int32_t> &arr)
{
    // Radix Sort: 4 pasadas de Counting Sort sobre cada byte
    for (int byteIdx = 0; byteIdx < 4; ++byteIdx)
    {
        coutingSortPorByte(arr, byteIdx);
    }
}