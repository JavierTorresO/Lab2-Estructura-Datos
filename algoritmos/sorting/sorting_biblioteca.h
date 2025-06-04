#ifndef SORTING_BIBLIOTECA_H
#define SORTING_BIBLIOTECA_H

#include <vector>
#include <cstdint>

/**
 * Wrapper para std::sort de la STL de C++.
 * Recibe un vector de int32_t y lo ordena de forma ascendente in-place.
 */
void sortingBiblioteca(std::vector<int32_t> &arr);

#endif // SORTING_BIBLIOTECA_H