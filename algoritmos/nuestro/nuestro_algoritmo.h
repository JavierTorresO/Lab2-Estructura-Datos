#ifndef NUESTRO_ALGORITMO_H
#define NUESTRO_ALGORITMO_H

#include <vector>
#include <cstdint>

/**
 * Radix Sort para enteros de 32 bits (LSD, base 256).
 * Recibe un vector arr y lo ordena in-place usando 4 pasadas de Counting Sort sobre cada byte.
 */

void propioSort(std::vector<int32_t> &arr);

#endif // NUESTRO_ALGORITMO_H
