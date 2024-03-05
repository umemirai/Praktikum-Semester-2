#include <iostream>
using namespace std;

int main() {
    
    int angka = 25;
    int *ptr1 = &angka;
    int *ptr2 = ptr1;


    cout << "Nilai variabel: " << angka << endl;
    cout << "Alamat variabel: " << &angka << endl;
    cout << "Nilai pointer pertama: " << *ptr1 << endl;
    cout << "Alamat pointer pertama: " << ptr1 << endl;
    cout << "Nilai pointer kedua: " << *ptr2 << endl;
    cout << "Alamat pointer kedua: " << ptr2 << endl;

    return 0;
}
