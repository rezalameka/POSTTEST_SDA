#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int SIZE = 5;
    Mahasiswa mhs[SIZE];
    
    cout << "Input data 5 mahasiswa:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "\nMahasiswa " << i+1 << ":" << endl;
        cout << "Nama: ";
        cin.ignore();
        getline(cin, mhs[i].nama);
        cout << "NIM: ";
        getline(cin, mhs[i].nim);
        cout << "IPK: ";
        cin >> mhs[i].ipk;
    }
    
    // Cari mahasiswa dengan IPK tertinggi
    int maxIndex = 0;
    for (int i = 1; i < SIZE; i++) {
        if (mhs[i].ipk > mhs[maxIndex].ipk) {
            maxIndex = i;
        }
    }
    
    cout << "\nMahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama: " << mhs[maxIndex].nama << endl;
    cout << "NIM: " << mhs[maxIndex].nim << endl;
    cout << "IPK: " << mhs[maxIndex].ipk << endl;
    
    return 0;
}