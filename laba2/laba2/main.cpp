#include <iostream>
#include <string>
#include "sortapp.h"
using namespace std;

void fillArr(int* arr, int length) {
    for (int i = 0; i < length; ++i) {
        cin >> arr[i];
    }
}

int main() {
    int length;
    cin >> length;
    int* arr = new int[length];
    fillArr(arr, length);
    int usingnumber = 0;

    while (usingnumber > 0 && usingnumber < 6) {
        cin >> usingnumber;
        switch (usingnumber) {
        case 1:
            sortapp::bubble(arr, length);
            
        case 2:
            sortapp::choice(arr, length);
           
        case 3:
            sortapp::insert(arr, length);
            
        case 4:
            sortapp::counting(arr, length);
            
        case 5:
            sortapp::digital(&arr, &length);
            
        case 6:
            break;
        }
    }

    delete[] arr; 
    return 0;
}