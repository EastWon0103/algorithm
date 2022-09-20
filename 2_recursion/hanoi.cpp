#include <iostream>
#include <stack>
using namespace std;

void hanoi(int numDisk, int a, int b, int c);
static bool empty = false;

stack <int> hole_3;

int main() {
    int numTestcase;

    cin >> numTestcase;

    for(int i=0;i<numTestcase;i++){
        int numOfDisk;
        cin >> numOfDisk;
        hanoi(numOfDisk, 1, 2, 3);
        hole_3 = stack<int>();
        cout << endl;
    }

    return 0;
}

void hanoi(int numDisk, int a, int b, int c){
    if(numDisk == 1){
        if (c == 3){
            cout << numDisk << " ";
        } else if (a == 3) {
           cout << numDisk << " ";
        }
    } else {
        hanoi(numDisk-1, a, c, b);
        if (c == 3){
            cout << numDisk << " ";
        } else if (a == 3) {
           cout << numDisk-1 << " ";
        }
        hanoi(numDisk-1, b, a, c);
    }
}