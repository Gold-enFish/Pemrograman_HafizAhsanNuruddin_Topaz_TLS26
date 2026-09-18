#include <iostream>
using namespace std;

int main() {
    char kata[1000];
    cout << "Masukkan kata: ";
    cin.getline(kata, 1000);

    int panjang = 0;
    while (kata[panjang] != '\0') {
        panjang++;
    }

    char hasil[1000];
    hasil[0] = kata[0]; 

    int nilaiSebelumnya;
    if (kata[0] >= 'A' && kata[0] <= 'Z') {
        nilaiSebelumnya = kata[0] - 'A' + 1;
    } else if (kata[0] >= 'a' && kata[0] <= 'z') {
        nilaiSebelumnya = kata[0] - 'a' + 1;
    } else {
        nilaiSebelumnya = 0;
    }

    for (int i = 1; i < panjang; i++) {
        char huruf = kata[i];

        if (huruf >= 'A' && huruf <= 'Z') {
            int nilaiSekarang = huruf - 'A' + 1;
            int geser = (nilaiSekarang + nilaiSebelumnya - 1) % 26 + 1;
            hasil[i] = 'A' + (geser - 1);
            nilaiSebelumnya = nilaiSekarang; 
        }
        else if (huruf >= 'a' && huruf <= 'z') {
            int nilaiSekarang = huruf - 'a' + 1;
            int geser = (nilaiSekarang + nilaiSebelumnya - 1) % 26 + 1;
            hasil[i] = 'a' + (geser - 1);
            nilaiSebelumnya = nilaiSekarang;
        }
        else {
        
            hasil[i] = huruf;
        }
    }

    hasil[panjang] = '\0';

    cout << "Hasil sandi: " << hasil << endl;

    return 0;
}