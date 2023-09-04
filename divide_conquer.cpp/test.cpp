

#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> mergeSort (vector<int> datos) {
    if (datos.size() <= 1) {
        return datos;
    }

    vector<int> izq, der;
    for (int i = 0; i < datos.size(); i++) {
        if (i < datos.size() / 2) {
            izq.push_back(datos[i]);
        } else {
            der.push_back(datos[i]);
        }
    }

    izq = mergeSort(izq);
    der = mergeSort(der);

    vector<int> resultado;
    int i = 0, j = 0;
    while (i < izq.size() && j < der.size()) {
        if (izq[i] < der[j]) {
            resultado.push_back(izq[i]);
            i++;
        } else {
            resultado.push_back(der[j]);
            j++;
        }
    }

    while (i < izq.size()) {
        resultado.push_back(izq[i]);
        i++;
    }

    while (j < der.size()) {
        resultado.push_back(der[j]);
        j++;
    }

    return resultado;
}

vector<int> quickSort(vector<int> datos) {
    if (datos.size() <= 1) {
        return datos;
    }

    int pivote = datos[0];
    vector<int> izq, der;
    for (int i = 1; i < datos.size(); i++) {
        if (datos[i] < pivote) {
            izq.push_back(datos[i]);
        } else {
            der.push_back(datos[i]);
        }
    }

    izq = quickSort(izq);
    der = quickSort(der);

    izq.push_back(pivote);
    izq.insert(izq.end(), der.begin(), der.end());

    return izq;
}