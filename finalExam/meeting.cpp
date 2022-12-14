#include <iostream>
#include <algorithm>
using namespace std;

struct Meeting {
    int num;
    int start;
    int end;  
};

bool compare(Meeting a, Meeting b) {
    return a.end < b.end;
}

int greedy(Meeting *arr, Meeting *A, int n) {
    int j = 0;
    A[0] = arr[j];
    int index = 1;
    cout << "greedy" << endl;
    for(int i=1;i<n;i++) {
        if(arr[i].start >= arr[j].end) {
            j = i;
            A[index] = arr[j];
            index++;
        }
        cout << endl;
    }

    return index;
}


int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        int n;
        cin >> n;

        Meeting *mArr = new Meeting[n];
        for(int j=0;j<n;j++) {
            int s,e;
            cin >> s >> e;
            mArr[j] = (Meeting) {j+1, s, e};
        }

        sort(mArr, mArr+n, compare);
        
        Meeting *a = new Meeting[n];
        int index = greedy(mArr, a, n);
        cout << "배정된 회의 개수: " << index << endl;
        for(int j=0;j<index;j++) {
            cout << a[j].start<< " ";
            cout << a[j].end << endl;
        }
        delete[] mArr;
        delete[] a;
    }
    return 0;
}