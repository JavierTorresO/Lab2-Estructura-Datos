# Proyecto: Comparación de Algoritmos de Ordenamiento

## Integrantes

- Martin Gonzalez
- Javier Torres
- Joaquin Quintana

---

Este proyecto consiste en la implementación y comparación de diferentes algoritmos de ordenamiento sobre archivos binarios de números enteros de 32 bits. El objetivo es analizar el rendimiento de cada algoritmo bajo distintos escenarios de datos (ascendente, descendente, aleatorio, parcialmente ordenado y con repetidos).

## Algoritmos implementados

- Insertion Sort
- Merge Sort
- Quick Sort
- Heap Sort
- std::sort (de la biblioteca estándar de C++)
- Radix Sort (implementado como "nuestro algoritmo")

## Estructura del proyecto

- `algoritmos/`: Contiene el código fuente de los algoritmos y el programa principal.
- `generadores/`: Scripts para generar archivos binarios de prueba con diferentes características.
- `datos/`: Carpeta donde se guardan los archivos binarios generados.

## Uso

1. **Compilar el programa principal**  
   Desde la raíz del proyecto, ejecuta:

   ```sh
   g++ algoritmos/main.cpp algoritmos/insertion/insertion_sort.cpp algoritmos/merge/merge_sort.cpp algoritmos/quick/quick_sort.cpp algoritmos/heap/heap_sort.cpp algoritmos/nuestro/nuestro_algoritmo.cpp algoritmos/sorting/sorting_biblioteca.cpp -o programa
   ```

2. **Ejecutar el programa**

   ```sh
   ./programa
   ```

   El programa solicitará el algoritmo a utilizar y el nombre del archivo binario con los datos a ordenar.

3. **Generar archivos de prueba**  
   Puedes compilar y ejecutar el generador de archivos en la carpeta `generadores` para crear archivos binarios de diferentes tamaños y características.
