#include <iostream>
using namespace std;

struct Menara {
	int arr[3];
	int top = 0;
	
	Menara *next;
	Menara *prev;
};

Menara *head, *tail, *curr, *newNode, *del, *curr1, *curr2;
int maks = 3;
int batu[3] = {100, 75, 50};

bool isEmpty(){
	if(head == NULL){
		return true;
	} else {
		return false;
	}
}

void displayData(int step){
	int ascii = 65;
	curr = head;
	cout << "Step " << step << "\n";
	cout << "==============\n";
	while(curr!=NULL){
		int count = 0;
		cout << "Menara " << char(ascii) << " : ";
		for(int i=0;i<3;i++){
			if(curr->arr[i] == 0){
				count++;
				continue;
			}
			cout << curr->arr[i] << " ";
		}
		if(count == 3){
			cout << "kosong";
		}
		cout << endl;
		curr = curr->next;
		ascii++;
	}
	cout << endl;
}

void addNode(){
	if(isEmpty()){
		head = new Menara();
		for(int i=0;i<3;i++){
			head->arr[i] = batu[i];
		}
		head->top = 3;
		head->next = NULL;
		head->prev = NULL;
		tail = head;
	} else {
		newNode = new Menara();
		newNode->arr[newNode->top] = 0;
		newNode->next = NULL;
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
}

void pushData(int poss1, int poss2){
	curr1 = head;
	for(int i=1; i<=poss1-1; i++){
		curr1 = curr1->next;
	}
	curr2 = head;
	for(int i=1;i<=poss2-1;i++){
		curr2 = curr2->next;
	}
	curr2->arr[curr2->top] = curr1->arr[curr1->top-1];
	curr1->arr[curr1->top-1] = 0;
	curr2->top++;
	curr1->top--;
}

main(){
	for(int i=1;i<=3;i++){
		addNode();
	}
	pushData(1, 2);
	displayData(1);
	
	pushData(1, 3);
	displayData(2);

	pushData(2, 3);
	displayData(3);
	
	pushData(1, 2);
	displayData(4);

	pushData(3, 1);
	displayData(5);
	
	pushData(3, 2);
	displayData(6);
	
	pushData(1, 2);
	displayData(7);
}
