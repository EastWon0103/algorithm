#include <iostream>
using namespace std;

int abs(int a) {
    if(a<0) {
        return -1*a;
    }
    return a;
}

bool isPromising(int *col, int row) {
    int k = 0;
    bool promising = true;
    while(k<row && promising) {
        // col(x) 가 같으면 아니면 대각선()이면 못놈
        if(col[row] == col[k] || abs(col[row]-col[k]) == row-k) {
            promising = false;  
        }
        k++;
    }

    return promising;
}

int nQueen(int *col, int row, int n) {
    if(row == n) {
        return 1;
    }

    int result = -1;
    for(int i=1;i<=n;i++) {
        col[row] = i;
        if(isPromising(col, row)){
            result = nQueen(col,row+1,n);
            if(result==1) {
                break;
            }
        }
        col[row] = -1;
    }

    return result;
}

int main() {
    int numTestCase=1;

    for(int i=0;i<numTestCase;i++) {
        int n;
        cin >> n;
        int *col = new int[n];
        nQueen(col,0,n);
        for(int j=0;j<n;j++) {
            cout << col[j] << "\n";
        }
        delete[] col;
    }
    return 0;
}