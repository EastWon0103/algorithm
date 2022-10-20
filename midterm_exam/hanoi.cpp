#include <iostream>
using namespace std;

#define MAX_SIZE 10

struct stack {
    int *array;
    int pos;
};

void push(stack *s, int n) {
    (s->pos) = (s->pos)+1;
    (s->array)[s->pos] = n;
}

bool empty(stack *s) {
    if((s->pos)==-1) {
        return true;
    }
    return false;
}

int pop(stack *s) {
    return (s->array)[(s->pos)--];
}

int peek(stack *s) {
    if(empty(s)) {
        return 0;
    } else {
        return (s->array)[s->pos];
    }
}

void hanoi(stack *hole3, int n, int a, int b, int c) {
    if(n>0) {
        hanoi(hole3, n-1, a, c, b);
        if(c==3) {
            push(hole3, n);
            cout << n << " ";
        } else if(a==3){
            pop(hole3);
            if(empty(hole3)) {
                cout << 0 << " ";
            } else {
                cout << peek(hole3)<< " ";
            }
        }
        hanoi(hole3, n-1, b, a, c);
    }
}

int main() {
    int numTestCase;
    cin >> numTestCase;
    
    for (int i=0;i<numTestCase;i++) {
        int n;
        cin >> n;
        stack *hole3 = new stack;
        (hole3->array) = new int[MAX_SIZE];
        (hole3->pos) = -1;
        hanoi(hole3, n, 1,2,3);
        cout << endl;
        delete hole3;
    }
    return 0;
}