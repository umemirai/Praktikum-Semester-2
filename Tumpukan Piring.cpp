#include <iostream>
#include <stack>

using namespace std;

class PlateStack {
private:
    stack<int> plates;

public:
    // Menambahkan piring ke rak
    void addPlate(int plateNumber) {
        plates.push(plateNumber);
        cout << "Piring " << plateNumber << " ditambahkan ke rak." << endl;
    }

    // Mengambil piring dari rak
    void removePlate() {
        if (plates.empty()) {
            cout << "Rak sudah kosong." << endl;
            return;
        }
        int topPlate = plates.top();
        plates.pop();
        cout << "Piring " << topPlate << " diambil dari rak." << endl;
    }

    // Menampilkan jumlah piring di rak
    void displaySize() {
        cout << "Jumlah piring di rak: " << plates.size() << endl << endl;
    }

    // Menampilkan piring teratas di rak
    void displayTopPlate() {
        if (plates.empty()) {
            cout << "Rak sudah kosong." << endl << endl;
            return;
        }
        cout << "Piring teratas di rak: " << plates.top() << endl;
    }
};

int main() {
    PlateStack plateRack;

    // Menambahkan piring ke rak
    plateRack.addPlate(1);
    plateRack.addPlate(2);
    plateRack.addPlate(3);

    // Menampilkan jumlah piring di rak
    plateRack.displaySize();

    // Menampilkan piring teratas di rak
    plateRack.displayTopPlate();

    // Mengambil piring dari rak
    plateRack.removePlate();
    plateRack.removePlate();
    plateRack.removePlate();
    plateRack.removePlate(); // Coba mengambil dari rak kosong

    return 0;
}

