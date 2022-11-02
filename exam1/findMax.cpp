#include <iostream>
using namespace std;
#define MAX_SIZE 100
int findSecond(int *arr, int low, int high, bool isLast) {
    if(low==high) {
        return arr[low];
    }

    int mid = (low+high)/2;
    int a = findSecond(arr, low, mid, false);
    int b = findSecond(arr, mid+1, high, false);
    
    if(isLast) {
        if(a<b) {
            return a;
        } else {
            return b;
        }
    } else {
        if(a>=b) {
            return a;
        } else {
            return b;
        }
    }
}

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int t=0;t<numTestCase;t++) {
        int n;
        cin >> n;
        int *arr = new int[n];
        for(int i=0;i<n;i++) {
            cin >> arr[i];
        }  

        cout << findSecond(arr, 0, n-1, true) << endl;
        delete[] arr;
    }
    return 0;
}