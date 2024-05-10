#include <iostream>
#include <cstdlib> // untuk fungsi rand()
#include <ctime>   // untuk fungsi time()

using namespace std;

const int NUM_BLOCKS = 10; // Jumlah blok kayu dalam permainan Jenga

// Struktur Node untuk merepresentasikan blok kayu
struct Block {
    int number;
    Block* next;
};

// Struktur Stack untuk merepresentasikan tumpukan blok kayu
struct Stack {
    Block* top;

    // Konstruktor untuk inisialisasi stack
    Stack() : top(NULL) {}

    // Fungsi untuk menambahkan blok kayu ke atas tumpukan
    void push(int num) {
        Block* newBlock = new Block;
        newBlock->number = num;
        newBlock->next = top;
        top = newBlock;
    }

    // Fungsi untuk menghapus blok kayu dari atas tumpukan
    void pop() {
        if (isEmpty()) {
            cout << "Tumpukan sudah kosong." << endl;
            return;
        }
        Block* temp = top;
        top = top->next;
        delete temp;
    }

    // Fungsi untuk memeriksa apakah tumpukan kosong
    bool isEmpty() {
        return top == NULL;
    }

    // Fungsi untuk menampilkan tumpukan blok kayu saat ini
    void display() {
        cout << "Tumpukan Blok Kayu Saat Ini:" << endl;
        Block* current = top;
        while (current != NULL) {
            cout << current->number << endl;
            current = current->next;
        }
        cout << "===============" << endl;
    }
};

int main() {
    Stack jengaStack;

    // Inisialisasi tumpukan blok kayu dengan nomor 1 hingga NUM_BLOCKS
    for (int i = 1; i <= NUM_BLOCKS; ++i) {
        jengaStack.push(i);
    }

    cout << "Selamat datang di Permainan Jenga!" << endl;
    jengaStack.display();

    // Mainkan Jenga
    while (true) {
        // Pilih secara acak untuk menghapus blok kayu dari atas atau bawah tumpukan
        int choice = rand() % 2; // 0 untuk atas, 1 untuk bawah

        if (choice == 0) {
            // Hapus blok kayu dari atas tumpukan
            cout << "Hapus blok kayu dari atas tumpukan." << endl;
            jengaStack.pop();
        } else {
            // Hapus blok kayu dari atas tumpukan
            cout << "Hapus blok kayu dari atas tumpukan." << endl;
            jengaStack.pop(); // Hapus blok kayu dari atas tumpukan
        }

        // Tampilkan tumpukan blok kayu saat ini
        jengaStack.display();

        // Periksa apakah permainan selesai (tumpukan kosong atau hanya satu blok)
        if (jengaStack.isEmpty() || jengaStack.top->next == NULL) {
            cout << "Permainan selesai!" << endl;
            break;
        }

        // Menunggu sejenak sebelum langkah selanjutnya
        cout << "Tekan Enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
    }

    return 0;
}

