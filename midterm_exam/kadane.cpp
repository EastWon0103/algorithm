#include <iostream>
using namespace std;

int kadane(int *a, int len, int *start, int *end) {
    int pos;
    int max=0;
    int sum=0;
    *start = -1;
    *end = -1;
    bool isCount = false;
    int minStart = *start;
    for(pos=0;pos<len;pos++) {
        if(a[pos] == 0) {
            continue;
        }
        if(!isCount) {
            *start = pos;
            isCount = !isCount; 
        }

        sum+=a[pos];
        if(sum < 0) {
            sum = 0;
            *start = -1;
            isCount = false;
        } else if(max<sum) {
            max = sum;
            minStart = *start;
            *end = pos;
        }
    }

    *start = minStart;

    return max;
}

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        int len;
        cin >> len;
        int *arr = new int[len];
        for(int j=0;j<len;j++) {
            cin >> arr[j];
        }
        int start,end;
        int sum = kadane(arr, len, &start, &end);

        cout << sum << " " << start << " " << end << endl;

        delete[] arr;
    }
    return 0;
}