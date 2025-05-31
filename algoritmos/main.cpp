#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <chrono>
#include "/insertion/insertion_sort.h" 

std::vector<int32_t> leerBinario(const std::string& ruta) {
    std::ifstream archivo(ruta, std::ios::binary);
    std::vector<int32_t> datos;

    if (!archivo) {
        std::cerr << "Error al abrir archivo: " << ruta << std::endl;
        return datos;
    }

    int32_t numero;
    while (archivo.read(reinterpret_cast<char*>(&numero), sizeof(numero))) {
        datos.push_back(numero);
    }

    return datos;
}

int main() {
    std::string rutaArchivo = "/generadores/datos/ascendente_1MB.bin"; // ajustar el .bin segun el orden y tamaño
    auto datos = leerBinario(rutaArchivo);

    if (datos.empty()) {
        std::cerr << "No se cargaron datos." << std::endl;
        return 1;
    }

    auto inicio = std::chrono::high_resolution_clock::now();
    insertionSort(datos);
    auto fin = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duracion = fin - inicio;
    std::cout << "Tiempo de ordenamiento: " << duracion.count() << " segundos" << std::endl;

    // mostrar primeros 10 valores para verificar
    std::cout << "Primeros 10 elementos ordenados:\n";
    for (size_t i = 0; i < std::min<size_t>(10, datos.size()); ++i) {
        std::cout << datos[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

//correr con: g++ main.cpp insertion/insertion_sort.cpp -o programa        ->   ./programa