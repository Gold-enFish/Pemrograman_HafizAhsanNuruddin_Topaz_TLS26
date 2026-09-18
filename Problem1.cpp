#include <iostream>
using namespace std;

int main() {
    int N, K;

    cout << "Masukkan jumlah astronot (N) : ";
    cin >> N;
    cout << "Masukkan nilai K awal       : ";
    cin >> K;

    if (N < 1 || N > 1000 || K < 1) {
        cout << "Input tidak valid." << endl;
        return 0;
    }

   
    bool status[1000];
    for (int i = 0; i < N; i++) {
        status[i] = true;
    }

    int sisa = N;    
    int posisi = 0;  

    cout << "\n--- Proses Eliminasi ---" << endl;

    while (sisa > 1) {
        
        int hitung = 0;
        while (true) {
            if (status[posisi] == true) {
                hitung = hitung + 1;
            }
            if (hitung == K) {
                break;        
            }
            posisi = posisi + 1;
            if (posisi == N) {  
                posisi = 0;
            }
        }

        int nomor = posisi + 1;
        status[posisi] = false;
        sisa = sisa - 1;

        cout << "K = " << K << " -> astronot " << nomor << " dieliminasi";

    
        if (nomor % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;
        }
        if (K < 2) {
            K = 2;
        }

        cout << ", K berikutnya = " << K << endl;

     
        posisi = posisi + 1;
        if (posisi == N) {
            posisi = 0;
        }
    }


    int bertahan = 0;
    for (int i = 0; i < N; i++) {
        if (status[i] == true) {
            bertahan = i + 1;
        }
    }

    cout << "\nAstronot yang bertahan: " << bertahan << endl;
    return 0;
}


