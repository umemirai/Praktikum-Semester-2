#include <iostream>
using namespace std;

struct Biodata{
    string nama;
    int tinggi_badan;
    int umur;
    char goldar;
};

void tampil(Biodata bio){
    cout << endl;
    cout << "BIODATA" << endl;
    cout << "Nama         :" << bio.nama << endl;
    cout << "Tinggi Badan :" << bio.tinggi_badan << " CM" << endl;
    cout << "Umur         :" << bio.umur << endl;
    cout << "Goldar       :" << bio.goldar << endl;
}

main(){
    int menu;
    cout << "MENU " << endl;
    cout << "1. Program Biodata" << endl;
    cout << "0. Exit Program" << endl;
    cout << "Masukkan pilihan Anda :";
    cin >> menu;

    if (menu == 1){
        cout << "Program Biodata" << endl;

        Biodata bio1, bio2;
        
        cout << "Data Pertama" << endl;
        cin.ignore();
        cout << "Nama         : ";
        getline(cin, bio1.nama);
        cout << "Tinggi Badan : ";
        cin >> bio1.tinggi_badan;
        cout << "Umur         : ";
        cin >> bio1.umur;
        cout << "Goldar       : ";
        cin >> bio1.goldar;
        cout << endl;

        cout << "Data kedua" << endl;
        cin.ignore();
        cout << "Nama         : ";
        getline(cin, bio2.nama);
        cout << "Tinggi Badan : ";
        cin >> bio2.tinggi_badan;
        cout << "Umur         : ";
        cin >> bio2.umur;
        cout << "Goldar       : ";
        cin >> bio2.goldar;
        
        tampil(bio1);
        cout << endl;
        tampil(bio2);

    }
    else if (menu == 0){
        cout << "Exit program.";
    }
    else {
        cout << "Menu yang Anda masukkan tidak valid.";
    }
    return 0;
}