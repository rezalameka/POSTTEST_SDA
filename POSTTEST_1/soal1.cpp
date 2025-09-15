#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int getNextPrime(int start) {
    int num = start + 1;
    while (true) {
        if (isPrime(num)) return num;
        num++;
    }
}

void reverseArray(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;
    
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        
        start++;
        end--;
    }
}

int main() {
    const int SIZE = 7;
    int arr[SIZE];
    
    int primeCount = 0;
    int multipleCount = 0;
    
    for (int i = 0; i < SIZE; i++) {
        if (i % 2 == 0) { // Ganjil (indeks dimulai dari 0)
            arr[i] = 3 * (multipleCount + 1);
            multipleCount++;
        } else { // Genap
            if (primeCount == 0) {
                arr[i] = 2;
            } else {
                arr[i] = getNextPrime(arr[i-2]);
            }
            primeCount++;
        }
    }
    
    cout << "Array sebelum dibalik: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    reverseArray(arr, SIZE);
    
    cout << "Array setelah dibalik: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}