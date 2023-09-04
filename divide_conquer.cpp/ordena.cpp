#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> leeDatos(const string& nombreArchivo) {
    vector<int> datos;
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return datos;
    }

    int numero;
    while (archivo >> numero) {
        datos.push_back(numero);
    }

    archivo.close();
    return datos;
}

void mergeSort(vector<int>& datos, int l, int r, vector<int>& temp) {  
    if (l < r) {
        int m = l + (r - l) / 2;

        // Ordenar primera y segunda mitad
        mergeSort(datos, l, m, temp);
        mergeSort(datos, m + 1, r, temp);

        // Mezclar las mitades ordenadas
        int i = l, j = m + 1, k = l;

        while (i <= m && j <= r) {
            if (datos[i] <= datos[j]) {
                temp[k] = datos[i];
                i++;
            } else {
                temp[k] = datos[j];
                j++;
            }
            k++;
        }

        while (i <= m) {
            temp[k] = datos[i];
            i++;
            k++;
        }

        while (j <= r) {
            temp[k] = datos[j];
            j++;
            k++;
        }

        for (int i = l; i <= r; i++) {
            datos[i] = temp[i];
        }
    }
}

int main() {
    string nombreArchivo = "datos.txt";
    vector<int> datos = leeDatos(nombreArchivo);
    vector<int> temp(datos.size());

    if (!datos.empty()) {
        cout << "Datos leídos del archivo:" << endl;
        for (const auto& numero : datos) {
            cout << numero << " ";
        }
        cout << endl;
    } else {
        cout << "El archivo no pudo ser leído o está vacío." << endl;
    }

    mergeSort(datos, 0, datos.size() - 1, temp);  

    cout << "Datos ordenados:" << endl;
    for (const auto& numero : datos) {  
        cout << numero << " ";
    }
    cout << endl;

    return 0;
}
