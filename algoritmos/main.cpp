#include <iostream>
#include <vector>
#include "insertion/insertion_sort.h" 

int main() {
    std::vector<int32_t> datos = {5, 2, 9, 1, 5, 6};
    insertionSort(datos);

    std::cout << "Datos ordenados: ";
    for (int32_t num : datos) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

//correr con: g++ main.cpp insertion/insertion_sort.cpp -o programa

