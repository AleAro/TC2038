#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


string toHex8Bit(uint8_t num) {
    const char *hexDigits = "0123456789ABCDEF";
    string hexStr = "00";
    for (int i = 1; i >= 0; i--) {
        hexStr[i] = hexDigits[num % 16];
        num >>= 4;
    }
    return hexStr;
}

string hashFile(const string &filename, int n) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << filename << endl;
        return "";
    }

    vector<char> chars;
    char ch;
    while (file.get(ch)) {
        chars.push_back(ch);
    }
    file.close();

    if (chars.empty()) {
        cerr << "Archivo vacio" << endl;
        return "";
    }


    while (chars.size() % n != 0) {
        chars.push_back(n);
    }


    vector<int> sums(n, 0);
    for (size_t i = 0; i < chars.size(); i++) {
        sums[i % n] += chars[i];
        sums[i % n] %= 256;
    }


    string hexOutput;
    for (int sum : sums) {
        hexOutput += toHex8Bit(sum);
    }

    return hexOutput;
}

int main() {
    string filename;
    int n;

    cout << "Nombre del archivo: ";
    cin >> filename;
    cout << "n: ";
    cin >> n;

    if (n < 16 || n > 64 || n % 4 != 0) {
        cerr << "Valor de n invalido" << endl;
        return 1;
    }

    cout << "Hash: " << hashFile(filename, n).substr(0, n/4) << endl; 
    return 0;
}
