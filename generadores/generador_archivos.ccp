#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>
#include <filesystem> 
#include <random> 

namespace fs = std::filesystem;

void generarAscendente(const std::string& nombreArchivo, size_t cantidad) {
    // Crear carpeta "datos" si no existe
    fs::create_directory("datos");

    std::string rutaArchivo = "datos/" + nombreArchivo;
    std::ofstream archivo(rutaArchivo, std::ios::binary);
    if (!archivo) {
        std::cerr << "Error: No se pudo abrir el archivo " << rutaArchivo << " para escribir." << std::endl;
        return;
    }

    for (size_t i = 0; i < cantidad; ++i) {
        int32_t numero = static_cast<int32_t>(i); // orden ascendente
        archivo.write(reinterpret_cast<const char*>(&numero), sizeof(int32_t));
    }

    archivo.close();
    std::cout << "Archivo generado: " << rutaArchivo << " (" << cantidad << " números)" << std::endl;
}

void generarDescendente(const std::string& nombreArchivo, size_t cantidad) {
    fs::create_directory("datos");

    std::string rutaArchivo = "datos/" + nombreArchivo;
    std::ofstream archivo(rutaArchivo, std::ios::binary);
    if (!archivo) {
        std::cerr << "Error: No se pudo abrir el archivo " << rutaArchivo << " para escribir." << std::endl;
        return;
    }

    for (size_t i = 0; i < cantidad; ++i) {
        int32_t numero = static_cast<int32_t>(cantidad - i - 1); // orden descendente
        archivo.write(reinterpret_cast<const char*>(&numero), sizeof(int32_t));
    }

    archivo.close();
    std::cout << "Archivo generado: " << rutaArchivo << " (" << cantidad << " números descendentes)" << std::endl;
}

void generarAleatorio(const std::string& nombreArchivo, size_t cantidad, int32_t minValor = 0, int32_t maxValor = 1000000) {
    fs::create_directory("datos");

    std::string rutaArchivo = "datos/" + nombreArchivo;
    std::ofstream archivo(rutaArchivo, std::ios::binary);
    if (!archivo) {
        std::cerr << "Error: No se pudo abrir el archivo " << rutaArchivo << " para escribir." << std::endl;
        return;
    }

    std::random_device rd;  // Para obtener semilla verdadera
    std::mt19937 gen(rd()); // Motor Mersenne Twister
    std::uniform_int_distribution<int32_t> distrib(minValor, maxValor);

    for (size_t i = 0; i < cantidad; ++i) {
        int32_t numero = distrib(gen);
        archivo.write(reinterpret_cast<const char*>(&numero), sizeof(int32_t));
    }

    archivo.close();
    std::cout << "Archivo generado: " << rutaArchivo << " (" << cantidad << " números aleatorios)" << std::endl;
}

void generarParcialmenteOrdenado(const std::string& nombreArchivo, size_t cantidad, double porcentajeOrdenado = 0.7) {
    fs::create_directory("datos");

    std::string rutaArchivo = "datos/" + nombreArchivo;
    std::ofstream archivo(rutaArchivo, std::ios::binary);
    if (!archivo) {
        std::cerr << "Error: No se pudo abrir el archivo " << rutaArchivo << " para escribir." << std::endl;
        return;
    }

    size_t cantidadOrdenada = static_cast<size_t>(cantidad * porcentajeOrdenado);
    size_t cantidadAleatoria = cantidad - cantidadOrdenada;

    // Generador aleatorio para la parte desordenada
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int32_t> distrib(0, 1000000);

    // Primera parte ordenada ascendente
    for (size_t i = 0; i < cantidadOrdenada; ++i) {
        int32_t numero = static_cast<int32_t>(i);
        archivo.write(reinterpret_cast<const char*>(&numero), sizeof(int32_t));
    }

    // Segunda parte aleatoria
    for (size_t i = 0; i < cantidadAleatoria; ++i) {
        int32_t numero = distrib(gen);
        archivo.write(reinterpret_cast<const char*>(&numero), sizeof(int32_t));
    }

    archivo.close();
    std::cout << "Archivo generado: " << rutaArchivo << " (" << cantidad << " números, "
              << porcentajeOrdenado * 100 << "% ordenados)" << std::endl;
}

void generarConRepetidos(const std::string& nombreArchivo, size_t cantidad, size_t cantidadValoresUnicos = 10) {
    fs::create_directory("datos");

    std::string rutaArchivo = "datos/" + nombreArchivo;
    std::ofstream archivo(rutaArchivo, std::ios::binary);
    if (!archivo) {
        std::cerr << "Error: No se pudo abrir el archivo " << rutaArchivo << " para escribir." << std::endl;
        return;
    }

    // Creamos un pequeño conjunto de valores únicos
    std::vector<int32_t> valoresUnicos;
    for (size_t i = 0; i < cantidadValoresUnicos; ++i) {
        valoresUnicos.push_back(static_cast<int32_t>(i * 100));  // ej: 0, 100, 200, ...
    }

    // Escribimos los valores repetidos en el archivo, rotando entre los valores únicos
    for (size_t i = 0; i < cantidad; ++i) {
        int32_t numero = valoresUnicos[i % cantidadValoresUnicos];
        archivo.write(reinterpret_cast<const char*>(&numero), sizeof(int32_t));
    }

    archivo.close();
    std::cout << "Archivo generado: " << rutaArchivo << " (" << cantidad << " números con " << cantidadValoresUnicos << " valores únicos)" << std::endl;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Para automatizar el nombre de los archivos para que incluyan el tamaño (como ascendente_1MB.bin, aleatorio_10MB.bin, etc.)
std::string generarNombreConTamano(const std::string& base, size_t cantidadNumeros) {
    size_t bytes = cantidadNumeros * sizeof(int32_t);
    std::string sufijo;

    if (bytes >= 104857600)       sufijo = "_100MB";
    else if (bytes >= 52428800)   sufijo = "_50MB";
    else if (bytes >= 10485760)   sufijo = "_10MB";
    else                          sufijo = "_1MB";

    return base + sufijo + ".bin";
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
int main() {
    // Tamaños comunes para cantidadNumeros (número de enteros 32-bit)
    // 1 MB  ≈ 1,048,576 bytes / 4 bytes por int = 262144
    // 10 MB ≈ 10,485,760 bytes /  = 2621440
    // 50 MB ≈ 52,428,800 bytes /  = 13107200
    // 100 MB ≈ 104,857,600 bytes /  = 26214400

    size_t cantidadNumeros = 262144; // 1 MB por defecto, cambia aquí para probar otros tamaños

    std::string nombreAsc = generarNombreConTamano("ascendente", cantidadNumeros);
    std::string nombreDesc = generarNombreConTamano("descendente", cantidadNumeros);
    std::string nombreAle = generarNombreConTamano("aleatorio", cantidadNumeros);
    std::string nombreParc = generarNombreConTamano("parcial", cantidadNumeros);
    std::string nombreRep = generarNombreConTamano("repetidos", cantidadNumeros);

    // 1. Ascendente
    generarAscendente(nombreAsc, cantidadNumeros);
    std::cout << "Archivo generado: " << nombreAsc << std::endl;

    // 2. Descendente
    generarDescendente(nombreDesc, cantidadNumeros);
    std::cout << "Archivo generado: " << nombreDesc << std::endl;

    // 3. Aleatorio (marcar rango de los numeros: ejm desde 0 hasta 1000000)
    generarAleatorio(nombreAle, cantidadNumeros, 0, 1000000);
    std::cout << "Archivo generado: " << nombreAle << std::endl;

    // 4. Parcialmente ordenado (marcar % ordenado: ejm 70% ordenado)
    generarParcialmenteOrdenado(nombreParc, cantidadNumeros, 0.7);
    std::cout << "Archivo generado: " << nombreParc << std::endl;

    // 5. Muchos repetidos (marcar los valores unicos: ejm solo 10 valores se repetiran en todo el listado)
    generarConRepetidos(nombreRep, cantidadNumeros, 10);
    std::cout << "Archivo generado: " << nombreRep << std::endl;


    return 0;
}

