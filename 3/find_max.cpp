#include <iostream>
using namespace std;

int findMax(int array[], int start, int end);

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        int input_length;
        cin >> input_length;

        int array[input_length];
        for(int j=0;j<input_length;j++) {
            cin >> array[i];
        }

        cout << findMax(array, 0, input_length-1) << endl;
    }
    return 0;
}

int findMax(int array[], int start, int end) {
    int a,b;
    if(start == end){
        return array[start];
    } else if(end-start == 1){
        a = array[start];
        b = array[end];
    } else {
        int mid = (end-start) / 2 + start;
        a = findMax(array, start, mid);
        b = findMax(array, mid+1, end);
    }

    
    if(a>b){
        return a;
    } else {
        return b;
    }
}