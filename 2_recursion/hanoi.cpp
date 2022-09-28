#include <iostream>
using namespace std;

struct stack{
    int *array;
    int pos;
};
void hanoi(stack *hole3, int numDisk, int a, int b, int c);


int main() {
    int numTestcase;

    cin >> numTestcase;

    for(int i=0;i<numTestcase;i++){
        int numOfDisk;
        cin >> numOfDisk;
        stack* hole3 = new stack;
        hole3->array = new int[numOfDisk+1];
        hole3->pos = 0;
        hanoi(hole3, numOfDisk, 1, 2, 3);
        cout << endl;
        delete hole3;
    }

    return 0;
}

void hanoi(stack *hole3, int numDisk, int a, int b, int c){
    if(numDisk > 0) {
        hanoi(hole3, numDisk-1, a, c, b);
        if (c == 3){
            cout << numDisk << " ";
            hole3->pos += 1;
            hole3->array[hole3->pos] = numDisk;
        } else if (a == 3) {
            hole3->array[hole3->pos] = 0;
            hole3->pos -= 1;
            if(hole3->pos == 0){
                cout << "0" << " ";
            } else {
                cout << hole3->array[hole3->pos] << " ";
            }
        }
        hanoi(hole3, numDisk-1, b, a, c);
    }
}

//  3 1 2 3 ->
//  2 1 3 2  ->
//  1 1 2 3 => 
//  0 1 3 2 x
//  1 1 2 3: 1