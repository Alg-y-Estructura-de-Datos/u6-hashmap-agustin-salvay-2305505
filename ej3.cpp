#include <iostream>
#include <string>
#include "HashMap/HashMapList.h"
#include "HashMap/HashMap.h"

using namespace std;

// Función hash simple para cadenas


int main() {
    unsigned int tamanoTabla = 11; // Tamaño de la tabla hash
    HashMap<int, string> diccionario(tamanoTabla);

    int opcion;
    string  significado;
    int dni;

    do {
        cout << "1. Agregar dni del votante\n";
        cout << "2. Buscar votant\n";
        cout << "3. Eliminar empleado\n";
        cout << "4. Ver todas los empleados\n";
        cout << "0. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el dni: ";
                cin >> dni;
                cout << "Ingrese el nombre: ";
                cin.ignore(); // Para ignorar el salto de línea
                getline(cin, significado);
                try{
                    diccionario.put(dni, significado);
                    cout << "usuario agregado correctamente.\n";
                }catch(int e){
                    if(e==409)
                        cout << "colision, intente otro.\n";
                }


                break;

            case 2:
                cout << "Ingrese el dni del empleado a buscar: ";
                cin >> dni;;
                try {
                    significado = diccionario.get(dni);
                    cout << "nombre de " << dni << ": " << significado << endl;
                } catch (int e) {
                    if (e == 404) {
                        cout << "Palabra no encontrada.\n";
                    } else {
                        cout << "Error: Conflicto en la búsqueda.\n";
                    }
                }
                break;

            case 3:
                cout << "Ingrese el dni del usuario a eliminar: ";
                cin >> dni;
            try {
                diccionario.remove(dni);
                cout << "Palabra eliminada correctamente (si existia).\n";
            }catch (int e) {
                if( e==404) {
                    cout << "palabra no encontrada" << endl;
                }
            }
                break;

            case 4:
                cout << "Todas las palabras en el diccionario:\n";
                diccionario.print(); // Imprimir todas las entradas
                break;

            case 0:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida. Intenta de nuevo.\n";
        }

        cout << endl;

    } while (opcion != 0);

    return 0;
}
