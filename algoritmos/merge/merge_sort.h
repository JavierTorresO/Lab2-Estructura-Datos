#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <vector>
#include <cstdint>

/**
 * Merge Sort (ordenamiento por mezcla).
 * divide el vector arr entre las posiciones [left..right] y lo ordena in-place.
 */
void mergeSort(std::vector<int32_t> &arr, int left, int right);

#endif // MERGE_SORT_H