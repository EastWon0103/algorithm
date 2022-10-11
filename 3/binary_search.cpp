#include <iostream>
using namespace std;

int binarySearch(int array[], int start, int end, int target);

int main() {
    int numTestCase;
    cin >> numTestCase;

    for(int i=0;i<numTestCase;i++) {          
        int length, findData;
        cin >> length >> findData;
        int array[length];
        
        for(int j=0;j<length;j++) {
            cin >> array[j];
        }

        cout << binarySearch(array, 0, length-1, findData) << endl;
        

    }
    return 0;
}

int binarySearch(int array[], int start, int end, int target){

    int mid = (end-start+1)/2 + start;
    int compareTarget = array[mid];

    if(start >= end && compareTarget != target) {
        return -1;
    }

    if(compareTarget == target) {
        return mid;
    } else if(target < compareTarget) {
        return binarySearch(array, start, mid-1, target);
    } else {
        return binarySearch(array, mid+1, end, target);
    }

}