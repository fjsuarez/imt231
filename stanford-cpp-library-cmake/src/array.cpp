#include <iostream>

using namespace std;

int main() {
    const size_t elementos = 5;
    int arr[elementos] = {1, 2, 3, 4, 5};
    int otraVariable = 100;
    int* ptr = arr;
    
    cout << "Direccion de otraVariable: " << &otraVariable << endl;
    cout << "otraVariable: " << otraVariable << endl;

    for (int i = 0; i < 8; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "Direccion de arr: " << arr << endl;
    cout << "Direccion de arr[0]: " << &arr[0] << endl;
    cout << "ptr: " << ptr << endl;
    cout << "Valor de ptr: " << *ptr << endl;
    cout << "Direccion de ptr+1: " << (ptr + 1) << endl;
    cout << "Valor de ptr+1: " << *(ptr + 1) << endl;
    cout << "Direccion de ptr+10: " << (ptr + 10) << endl;
    cout << "Valor de ptr+10: " << *(ptr + 10) << endl;

    cout << sizeof(arr)/sizeof(arr[0]) << endl;

    arr[8] = 10;
    cout << arr[8] << endl;
    cout << &arr[8] << endl;

    int arr2[10];
    for (int i = 0; i < elementos; i++) {
        arr2[i] = arr[i];
    }

    cout << "otraVariable: " << otraVariable << endl;

    cout << "Tamaño de arr: " << sizeof(arr) << endl;

    return 0;
}