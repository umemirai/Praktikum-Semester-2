#include <iostream>

using namespace std;

struct PlateStack {
    int plates[100];
    int top;

    PlateStack() {
        top = -1;
    }

    // Menambahkan piring ke rak
    void push(int plateNumber) {
        if (isFull()) {
            cout << "Rak sudah penuh." << endl;
            return;
        }
        plates[++top] = plateNumber;
        cout << "Piring " << plateNumber << " ditambahkan ke rak." << endl;
    }

    // Mengambil piring dari rak
    void pop() {
        if (isEmpty()) {
            cout << "Rak sudah kosong." << endl;
            return;
        }
        int topPlate = plates[top--];
        cout << "Piring " << topPlate << " diambil dari rak." << endl;
    }

    // Menampilkan jumlah piring di rak
    void displaySize() {
        cout << "Jumlah piring di rak: " << (top + 1) << endl << endl;
    }

    // Menampilkan piring teratas di rak
    void displayTopPlate() {
        if (isEmpty()) {
            cout << "Rak sudah kosong." << endl << endl;
            return;
        }
        cout << "Piring teratas di rak: " << plates[top] << endl;
    }

    // Memeriksa apakah rak sudah kosong
    bool isEmpty() {
        return top == -1;
    }

    // Memeriksa apakah rak sudah penuh
    bool isFull() {
        return top >= 99;
    }
};

int main() {
    PlateStack plateRack;

    // Menambahkan piring ke rak
    plateRack.push(1);
    plateRack.push(2);
    plateRack.push(3);

    // Menampilkan jumlah piring di rak
    plateRack.displaySize();

    // Menampilkan piring teratas di rak
    plateRack.displayTopPlate();

    // Mengambil piring dari rak
    plateRack.pop();
    plateRack.pop();
    plateRack.pop();
    plateRack.pop(); // Coba mengambil dari rak kosong

    return 0;
}

