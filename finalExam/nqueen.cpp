#include <iostream>
using namespace std;

void printQ(int *a, int n) {
    for(int i=0;i<n;i++) {
        cout << a[i]+1 << " ";
    }
    cout << endl;
}

int abs(int a) {
    if(a<0) {
        return -1*a;
    } else {
        return a;
    }
}

bool isPromissing(int *col, int row) {
    int k = 0;
    bool promise = true;
    while(k<row && promise) {
        if(col[row] == col[k] || abs(col[row]-col[k])==row-k) {
            promise = false;
        }
        k++;
    }
    return promise;
}

bool nQueen(int *col, int row, int n) {
    if(row==n) {
        return true;
    }

    bool result = false;

    for(int i=0;i<n;i++) {
        col[row] = i;
        if(isPromissing(col, row) && nQueen(col, row+1, n)) {
            result = true;
            break;
        }
    }

    return result;
}

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        int n;
        cin >> n;
        int *col = new int[n];

        if(nQueen(col, 0, n)) {
            printQ(col, n);
        } else {
            cout <<"no" << endl;
        }
        
        // for(int j=0;j<n;j++) {
        //     col[0] = j;
        //     nQueen(col, 0, n);
        // }

        delete[] col;
    }
    return 0;
}