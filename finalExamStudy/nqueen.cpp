#include <iostream>
using namespace std;
#define MAX 1000

int col[MAX];

int abs(int a) {
    if( a<0) {
        return -1 * a;
    }
    return a;
}

bool isPromise(int row, int n) {
    bool result = true;

    for(int i=1;i<row;i++) {
        if(col[i] == col[row] || row-i == abs(col[row]-col[i])) {
            return false;
        }
    }

    return result;
}

bool nqueen(int row, int n) {
    if(row == n+1) {
        return true;
    }

    for(int i=1;i<=n;i++) {
        col[row] = i;
        if(isPromise(row, n) && nqueen(row+1, n)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    int result = nqueen(1, n);
    if(result == false) {
        return 0;
    }

    for(int i=1;i<=n;i++) {
        cout << col[i] << " ";
    }
    cout << endl;

    return 0;
}