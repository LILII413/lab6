#include <iostream>
using namespace std;

const int TAM = 15;

// Función para ingresar números
void ingresarNumeros(int arreglo[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> arreglo[i];
    }
}

// Función para calcular el promedio
double calcularPromedio(int arreglo[], int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += arreglo[i];
    }
    return static_cast<double>(suma) / tam;
}

// Función para obtener números mayores al promedio
int obtenerMayoresAlPromedio(int original[], int tam, double promedio, int mayores[]) {
    int contador = 0;
    for (int i = 0; i < tam; i++) {
        if (original[i] > promedio) {
            mayores[contador] = original[i];
            contador++;
        }
    }
    return contador; // Retorna cuántos valores se guardaron
}

// Función para imprimir un arreglo
void imprimirArreglo(int arreglo[], int tam, string titulo) {
    cout << titulo << endl;
    for (int i = 0; i < tam; i++) {
        cout << arreglo[i] << " ";
    }
    cout << "\n" << endl;
}

int main() {
    int numeros[TAM];
    int mayores[TAM]; // Este tendrá a lo mucho los mismos 15 elementos
    double promedio;
    int cantidadMayores;

    // Paso 1: Ingreso
    ingresarNumeros(numeros, TAM);

    // Paso 2: Promedio
    promedio = calcularPromedio(numeros, TAM);

    // Paso 3: Filtrar mayores
    cantidadMayores = obtenerMayoresAlPromedio(numeros, TAM, promedio, mayores);

    // Paso 4: Imprimir resultados
    imprimirArreglo(numeros, TAM, "Todos los números:");
    cout << "Promedio: " << promedio << "\n" << endl;
    imprimirArreglo(mayores, cantidadMayores, "Números mayores al promedio:");

    return 0;
}
