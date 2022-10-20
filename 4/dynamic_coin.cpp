#include <iostream>
using namespace std;

#define NUM_OF_COiN 5
int coin[] = {1,5,10,21,25};
int initBag(int *a, int len);

int printBag(int *a, int len);
int min(int a[NUM_OF_COiN]) {
    int min = a[0];
    for(int i=1;i<NUM_OF_COiN;i++) {
        if(min > a[i]) {
            min = a[i];
        }
    }

    return min;
}

void dynamicCoin(int *a, int change);

int main() {
    int change;
    cin >> change;
    int *bag = new int[change];
    initBag(bag, change);
    printBag(bag, change);
    delete[] bag;

    return 0;
}

int initBag(int *a, int len) {
    for(int i=0;i<len;i++) {
        a[i] = -1;
    }
}

void coinExchange(int change) {
}

int printBag(int *a, int len) {
    for(int i=0;i<len;i++) {
        if(a[i]== -1) {
            break;
        }
        cout << a[i] << " ";
    }
    cout << endl;
}