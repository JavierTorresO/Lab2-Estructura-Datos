#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include <algorithm> //para el std::sort, no necesita carpeta adicional

#include "insertion/insertion_sort.h"
#include "merge/merge_sort.h"
#include "nuestro/nuestro_algoritmo.h"
#include "quick/quick_sort.h"
#include "heap/heap_sort.h"

void leerArchivoBinario(const std::string &nombreArchivo, std::vector<int32_t> &datos)
{
    std::ifstream archivo(nombreArchivo, std::ios::binary);
    if (!archivo)
    {
        std::cerr << "Error: no se pudo abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    int32_t numero;
    while (archivo.read(reinterpret_cast<char *>(&numero), sizeof(int32_t)))
    {
        datos.push_back(numero);
    }
    archivo.close();
}

int main()
{
    std::cout << "\nSeleccione el algoritmo de ordenamiento:\n";
    std::cout << "1. Insertion Sort\n";
    std::cout << "2. Merge Sort\n";
    std::cout << "3. Quick Sort\n";
    std::cout << "4. Heap Sort\n";
    std::cout << "5. std::sort (biblioteca)\n";
    std::cout << "6. Nuestro algoritmo\n";
    std::cout << "Opcion: ";

    int opcion;
    std::cin >> opcion;

    if (opcion < 1 || opcion > 6)
    {
        std::cerr << "Opción no válida." << std::endl;
        return 1;
    }

    std::string nombreArchivo;
    std::cout << "Nombre del archivo binario (ej: generadores/datos/ascendente_1MB.bin): ";
    std::cin >> nombreArchivo;

    std::cout << "Cargando datos desde el archivo...\n";
    std::vector<int32_t> datos;
    leerArchivoBinario(nombreArchivo, datos);

    if (datos.empty())
    {
        std::cerr << "No se pudieron cargar datos desde el archivo." << std::endl;
        return 1;
    }

    auto datosCopia = datos;

    auto inicio = std::chrono::high_resolution_clock::now();

    switch (opcion)
    {
    case 1:
        insertionSort(datosCopia);
        break;

    case 2:
        mergeSort(datosCopia, 0, datosCopia.size() - 1);
        break;
    case 3:
        quickSort(datosCopia, 0, datosCopia.size() - 1);
        break;
    case 4:
        heapSort(datosCopia);
        break;
    case 5:
        std::sort(datosCopia.begin(), datosCopia.end());
        break;
    case 6:
        propioSort(datosCopia);
        break;
    }

    auto fin = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracion = fin - inicio;

    std::cout << "Ordenamiento completado en " << duracion.count() << " segundos.\n";

    return 0;
}

// correr con: g++ algoritmos/main.cpp algoritmos/insertion/insertion_sort.cpp algoritmos/merge/merge_sort.cpp algoritmos/quick/quick_sort.cpp algoritmos/heap/heap_sort.cpp algoritmos/nuestro/nuestro_algoritmo.cpp  -o programa        ->   ./programa
