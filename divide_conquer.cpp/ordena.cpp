#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Función para leer datos desde un archivo
vector<int> leeDatos(const string& nombreArchivo) {
    vector<int> datos; // Vector para almacenar los datos
    ifstream archivo(nombreArchivo); // Objeto para leer el archivo

    if (!archivo.is_open()) { // Verifica si el archivo se abrió correctamente
        cout << "Error al abrir el archivo." << endl;
        return datos;
    }

    int N, numero; // N: número de datos, numero: dato leído
    archivo >> N;  // Lectura del número de datos

    for (int i = 0; i < N; ++i) {  // Limita la cantidad de datos a N
        if (archivo >> numero) {
            datos.push_back(numero);
        } else {
            cout << "Error en la lectura de datos, leídos menos de " << N << " números." << endl;
            break;
        }
    }

    archivo.close(); // Cierra el archivo
    return datos; // Devuelve el vector con los datos
}


// Función para imprimir los datos
void imprimeDatos(const vector<int>& datos) {
    for (const auto& numero : datos) {
        cout << numero << " ";
    }
    cout << endl;
}

// Función Merge Sort
vector<int> mergeSort(const vector<int>& arr) {
    int n = arr.size(); 
    vector<int> temp(n); // Vector temporal para almacenar los datos ordenados
    vector<int> result(arr); // Vector para almacenar los datos ordenados

    if (n <= 1) return result; // Caso base

    int m = n / 2; // Mitad del vector
    vector<int> left(arr.begin(), arr.begin() + m); // Vector con la primera mitad
    vector<int> right(arr.begin() + m, arr.end()); // Vector con la segunda mitad

    left = mergeSort(left); // Ordena la primera mitad
    right = mergeSort(right); // Ordena la segunda mitad

    int l = 0, r = 0, i = 0; // Variables para recorrer los vectores
    while (l < m && r < n - m) { // Mientras no se llegue al final de alguno de los vectores
        if (left[l] <= right[r]) {
            result[i++] = left[l++];
        } else {
            result[i++] = right[r++];
        }
    }

    while (l < m) { // Si quedan elementos en el vector izquierdo
        result[i++] = left[l++];
    }

    while (r < n - m) { // Si quedan elementos en el vector derecho
        result[i++] = right[r++];
    }

    return result;
}

// Función auxiliar para el Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) { // Recorre el vector
        if (arr[j] < pivot) { // Si el elemento es menor al pivote
            i++; 
            swap(arr[i], arr[j]); // Intercambia los elementos
        }
    }
    swap(arr[i + 1], arr[high]); 
    return (i + 1);
}

// Función Quick Sort
vector<int> quickSort(vector<int> arr, int low, int high) { 
    if (low < high) { // Si el índice bajo es menor al alto
        int pi = partition(arr, low, high); // Obtiene el índice del pivote

        arr = quickSort(arr, low, pi - 1); // Ordena la primera mitad
        arr = quickSort(arr, pi + 1, high); // Ordena la segunda mitad
    }
    return arr;
}
  
int main() { 
    string nombreArchivo = "datos.txt"; 
    vector<int> datos = leeDatos(nombreArchivo); 

    cout << "Datos leídos del archivo:" << endl; 
    imprimeDatos(datos);

    vector<int> datosOrdenadosMS = mergeSort(datos);
    cout << "Datos ordenados (Merge Sort):" << endl;
    imprimeDatos(datosOrdenadosMS);

    vector<int> datosOrdenadosQS = quickSort(datos, 0, datos.size() - 1);
    cout << "Datos ordenados (Quick Sort):" << endl;
    imprimeDatos(datosOrdenadosQS);

    return 0;
}
