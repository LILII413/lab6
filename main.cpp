#include <iostream>
using namespace std;

const int TAM = 15;

// Funci�n para ingresar n�meros
void ingresarNumeros(int arreglo[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << "Ingrese el n�mero " << i + 1 << ": ";
        cin >> arreglo[i];
    }
}

// Funci�n para calcular el promedio
double calcularPromedio(int arreglo[], int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += arreglo[i];
    }
    return static_cast<double>(suma) / tam;
}

// Funci�n para obtener n�meros mayores al promedio
int obtenerMayoresAlPromedio(int original[], int tam, double promedio, int mayores[]) {
    int contador = 0;
    for (int i = 0; i < tam; i++) {
        if (original[i] > promedio) {
            mayores[contador] = original[i];
            contador++;
        }
    }
    return contador; // Retorna cu�ntos valores se guardaron
}

// Funci�n para imprimir un arreglo
void imprimirArreglo(int arreglo[], int tam, string titulo) {
    cout << titulo << endl;
    for (int i = 0; i < tam; i++) {
        cout << arreglo[i] << " ";
    }
    cout << "\n" << endl;
}

int main() {
    int numeros[TAM];
    int mayores[TAM]; // Este tendr� a lo mucho los mismos 15 elementos
    double promedio;
    int cantidadMayores;

    // Paso 1: Ingreso
    ingresarNumeros(numeros, TAM);

    // Paso 2: Promedio
    promedio = calcularPromedio(numeros, TAM);

    // Paso 3: Filtrar mayores
    cantidadMayores = obtenerMayoresAlPromedio(numeros, TAM, promedio, mayores);

    // Paso 4: Imprimir resultados
    imprimirArreglo(numeros, TAM, "Todos los n�meros:");
    cout << "Promedio: " << promedio << "\n" << endl;
    imprimirArreglo(mayores, cantidadMayores, "N�meros mayores al promedio:");

    return 0;
}
