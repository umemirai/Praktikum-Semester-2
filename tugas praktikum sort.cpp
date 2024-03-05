#include <iostream>
#include <vector>

using namespace std;

// Fungsi merge untuk menggabungkan dua bagian dari vektor
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Buat vektor sementara untuk dua bagian
    vector<int> L(n1), R(n2);

    // Salin data ke vektor sementara L dan R
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Gabungkan dua vektor sementara ke dalam vektor utama
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Salin sisa elemen (jika ada) dari L
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Salin sisa elemen (jika ada) dari R
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fungsi merge sort
void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        // Temukan titik tengah
        int m = l + (r - l) / 2;

        // Rekursif pada dua bagian
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Gabungkan dua bagian yang terurut
        merge(arr, l, m, r);
    }
}

int main() {
    int n;

    // Input jumlah elemen
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    // Input elemen-elemen
    vector<int> data(n);
    cout << "Masukkan elemen-elemen: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Panggil fungsi merge sort untuk mengurutkan secara descending
    mergeSort(data, 0, n - 1);

    // Tampilkan hasil pengurutan
    cout << "Data setelah diurutkan secara descending: ";
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";
    }

    return 0;
}
