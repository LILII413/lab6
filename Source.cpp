#include <iostream>
#include <string>

using namespace std;

class CuentaBancaria {
private:
    string titular;
    double saldo;
    bool activa;
    int intentosFallidos;
    int mesesInactivo;

public:
    // Constructor
    CuentaBancaria(string titular, double saldoInicial) {
        this->titular = titular;
        this->saldo = saldoInicial;
        this->activa = true;
        this->intentosFallidos = 0;
        this->mesesInactivo = 0;
    }

    // Método para depositar dinero
    void depositar(double monto) {
        if (!activa) {
            cout << "No se puede realizar el depósito." << endl;
        }
        else {
            saldo += monto;
            cout << "Depósito exitoso. Nuevo saldo: " << saldo << endl;
            if (saldo < 100) {
                cout << "IMPORTANTE: El saldo ha caído por debajo de 100." << endl;
            }
        }
    }

    // Método para retirar dinero
    void retirar(double monto) {
        if (!activa) {
            cout << "No se puede realizar el retiro, la cuenta está bloqueada." << endl;
            return;
        }

        if (monto > saldo) {
            cout << "Fondos insuficientes" << endl;
            intentosFallidos++;
            if (intentosFallidos >= 3) {
                activa = false;
                cout << "¡La cuenta ha sido bloqueada por 3 intentos fallidos!" << endl;
            }
        }
        else {
            saldo -= monto;
            cout << "Retiro exitoso. Nuevo saldo: " << saldo << endl;
            intentosFallidos = 0; // Reiniciar intentos fallidos
        }

        if (saldo < 100) {
            cout << "Advertencia: El saldo ha caído por debajo de 100." << endl;
        }
    }

    // Método para consultar el saldo
    void consultarSaldo() {
        if (!activa) {
            cout << "La cuenta está bloqueada" << endl;
            return;
        }
        cout << "Saldo actual: " << saldo << endl;
    }

    // Método para simular la inactividad de la cuenta
    void inactividad(int meses) {
        mesesInactivo += meses;
        if (mesesInactivo >= 6) {
            activa = false;
            cout << "La cuenta ha sido bloqueada por inactividad más de 6 meses." << endl;
        }
    }

    // Método para mostrar el estado de la cuenta
    void mostrarEstado() {
        cout << "Titular: " << titular << endl;
        cout << "Saldo: " << saldo << endl;
        cout << "Estado: " << (activa ? "Activa" : "Bloqueada") << endl;
        cout << "Intentos fallidos: " << intentosFallidos << endl;
        cout << "Meses de inactividad: " << mesesInactivo << endl;
    }
};

int main() {
    string nombre;
    double saldoInicial;
    cout << "Ingrese el nombre del titular: ";
    getline(cin, nombre);
    cout << "Ingrese el saldo inicial de la cuenta: ";
    cin >> saldoInicial;

    // Crear una cuenta bancaria
    CuentaBancaria cuenta(nombre, saldoInicial);

    int opcion;
    double monto;
    int meses;

    do {
        cout << "\n--- Menu de operaciones ---\n";
        cout << "1. Depositar dinero\n";
        cout << "2. Retirar dinero\n";
        cout << "3. Consultar saldo\n";
        cout << "4. Ver estado de la cuenta\n";
        cout << "5. Inactividad\n";
        cout << "6. Salir\n";
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese el monto a depositar: ";
            cin >> monto;
            cuenta.depositar(monto);
            break;

        case 2:
            cout << "Ingrese el monto a retirar: ";
            cin >> monto;
            cuenta.retirar(monto);
            break;

        case 3:
            cuenta.consultarSaldo();
            break;

        case 4:
            cuenta.mostrarEstado();
            break;

        case 5:
            cout << "Ingrese la cantidad de meses de inactividad: ";
            cin >> meses;
            cuenta.inactividad(meses);
            break;

        case 6:
            cout << "Gracias por usar el sistema bancario." << endl;
            break;

        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
            break;
        }
    } while (opcion != 6);

    return 0;
}
