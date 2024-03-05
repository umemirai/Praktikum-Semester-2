#include <iostream>
using namespace std;

main(){

    int x[5] = {10, 20, 30, 40, 50};
    int *ptr;
    for (int i=0; i<5; i++){
        ptr = &x[i];
        cout << *ptr << " " << ptr << endl;
    }
}