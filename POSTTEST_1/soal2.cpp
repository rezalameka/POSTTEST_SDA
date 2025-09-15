#include <iostream>
using namespace std;

int main() {
    const int ROWS = 3;
    const int COLS = 3;
    int matrix[ROWS][COLS];
    
    cout << "Masukkan elemen matriks 3x3:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << "Elemen [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    
    cout << "\nMatriks:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // Hitung jumlah diagonal utama + diagonal sekunder
    int sum = 0;
    for (int i = 0; i < ROWS; i++) {
        sum += matrix[i][i]; // Diagonal utama
        sum += matrix[i][ROWS - 1 - i]; // Diagonal sekunder
    }
    
    // Karena elemen tengah dihitung dua kali, kurangi sekali
    sum -= matrix[ROWS/2][COLS/2];
    
    cout << "\nJumlah diagonal utama + diagonal sekunder: " << sum << endl;
    
    return 0;
}