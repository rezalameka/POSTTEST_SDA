#include <iostream>
using namespace std;

void swapWithDoublePointer(int **a, int **b) {
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main() {
    int a, b;
    
    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;
    
    cout << "\nSebelum pertukaran:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    
    int *ptrA = &a;
    int *ptrB = &b;
    
    swapWithDoublePointer(&ptrA, &ptrB);
    
    cout << "\nSetelah pertukaran:" << endl;
    cout << "a = " << a << ", b = " << b << endl;
    
    return 0;
}