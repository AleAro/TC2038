#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Función para convertir un número entero a una cadena hexadecimal de dos dígitos
string toHex(int num) {
    const char *hexDigits = "0123456789ABCDEF";
    string hexStr = "00";
    hexStr[1] = hexDigits[num % 16];
    hexStr[0] = hexDigits[(num >> 4) % 16];
    return hexStr;
}

// Función que realiza el hasheo del archivo
string hashFile(const string &filename, int n) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << filename << endl;
        return "";
    }

    vector<char> chars;
    char ch;
    while (file.get(ch)) {
        chars.push_back(ch);
    }
    file.close();

    // Rellenar el último renglón si es necesario
    while (chars.size() % n != 0) {
        chars.push_back(n);
    }

    // Calcular la suma ASCII para cada columna
    vector<int> sums(n, 0);
    for (size_t i = 0; i < chars.size(); i++) {
        sums[i % n] += chars[i];
        sums[i % n] %= 256;  // Asegurarnos de que la suma no exceda 255
    }

    // Convertir las sumas a hexadecimal
    string hexOutput;
    for (int sum : sums) {
        hexOutput += toHex(sum);
    }

    return hexOutput;
}

int main() {
    string filename;
    int n;

    cout << "Introduce el nombre del archivo: ";
    cin >> filename;
    cout << "Introduce el valor de n (debe ser un múltiplo de 4 y estar entre 16 y 64): ";
    cin >> n;

    if (n < 16 || n > 64 || n % 4 != 0) {
        cerr << "Valor de n inválido." << endl;
        return 1;
    }

    cout << "Hash del archivo: " << hashFile(filename, n) << endl;
    return 0;
}
