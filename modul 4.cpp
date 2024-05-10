#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *next = NULL;
};

struct List{
    Node *head = NULL;
    Node * tail = NULL;
};

void InsertFirst(List *senarai, char data){
    Node *node = new Node;
    node->data = data;
    if (senarai->head == NULL){
        senarai->head = senarai->tail = node;
    } else{
        node->next = senarai->head;
        senarai->head = node;
    }
}


void InsertByIndex(List *senarai, char data, int index){
    Node *node = new Node;
    node->data = data;
    if (senarai->head != NULL and index > 1){
        Node *helper = senarai->head;
        while (helper->next != NULL and index > 2){
            helper = helper->next;
            index = index - 1;
        }
        senarai->tail = (helper->next) ? senarai->tail : node;
        node->next = helper->next;
        helper->next = node;
    } else {
        node->next = senarai->head;
        senarai->head = node;
        senarai->tail = (node->next) ? senarai->tail : node;
    }
}

void DeleteFirst(List *senarai){
    Node *helper = senarai->head;
    if (senarai-> head == NULL) {
        cout << "Senarai sudah kosong" << endl;
    } else{
        senarai->head = helper->next;
        delete helper;
        helper == NULL;
    }
}

void DeleteByIndex (List *senarai, int index){
	Node *helper = senarai->head;
	if (senarai->head == NULL){
		cout << "Senarai sudah kosong" << endl;
	} else if (index < 1) {
		cout << "Index tidak valid" << endl;
	} else if (index == 1) {
		senarai->head = helper->next;
		delete helper;
		helper == NULL;
	} else {
		while (helper->next != NULL and index >2) {
			helper = helper->next;
			index = index -1;
		}
		if (helper->next == NULL){
			cout <<"Index tidak valid" << endl;
		} else {
			Node *temp = helper->next;
			helper->next = helper->next->next;
			delete temp;
			temp == NULL;
		}
	}
}
void DeleteLast(List *senarai){
    Node *helper = senarai->head;
    if (senarai->head == NULL) {
        cout << "Senarai sudah kosong" << endl;
    } else if (helper->next != NULL){
        while (helper->next != senarai->tail){
            helper = helper->next;
        }
        delete helper->next;
        helper->next = NULL;
        senarai->tail = helper;
    } else if (helper->next == NULL){
        delete helper;
        helper = NULL;
        senarai->head = senarai->tail = NULL;
    }
}

void View(List *senarai){
    Node *helper = senarai->head;
    if (helper == NULL){
        cout << "Senarai kosong";
    }else if (helper != NULL){
        while (helper != NULL){
            cout << helper->data << " ";
            helper = helper->next;
        }
    }
    cout << endl;
}

int main(){
    int option = -1;
    List *senarai = new List;
    int index; // Deklarasi variabel index
    while (option != 0){
        system("cls");
        View(senarai);
        cout << "Menu Pilihan : " << endl;
        cout << "1. Tambah simpul awal" << endl;
        cout << "2. Tambah simpul tengah" << endl;
        cout << "3. Hapus simpul By Index" << endl;
        cout << "0. Keluar program" << endl;
        cout << "Silakan pilih (0 - 3) : ";
        cin >> option;

        switch (option) {
            case 1:
                char data;
                cout << "Masukkan data : ";
                cin >> data;
                InsertFirst(senarai, data);
                break;

            case 2:
                char data2;
                cout << "Masukkan data : ";
                cin >> data2;
                cout << "Masukkan index : ";
                cin >> index; 
                InsertByIndex(senarai, data2, index); 
                break;

            case 3:
                cout << "Masukkan index : ";
                cin >> index; 
                DeleteByIndex(senarai, index); 
                break;
        }
    }
    delete senarai;
    return 0;
}

