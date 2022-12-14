#include <iostream>
using namespace std;
#define MAX_SIZE 1000

int len(char str[]) {
    int l;
    for(l=0;l<MAX_SIZE;l++) {
        if(str[l] == '\0') {
            return l;
        }
    }
    return l;
}

int lcs(int **arr, char a[], char b[], int m, int n) {
    if(m==0 || n == 0) {
        arr[m][n] = 0;
        return 0;
    }

    if(a[m-1]==b[n-1]) {
        return lcs(arr, a,b,m-1,n-1) +1;
    }

    if(arr[m][n] != -1) {
        return arr[m][n];
    }

    int x = lcs(arr,a,b,m-1,n);
    int y = lcs(arr,a,b,m,n-1);
    if(x>y) {
        return x;
    }
    return y;
}

void init(int **arr, int m, int n) {
    for(int i=0;i<=m;i++) {
        for(int j=0;j<=n;j++) {
            arr[i][j] = -1;
        }
    }
}

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        char a[MAX_SIZE];
        char b[MAX_SIZE];
        cin >> a >> b;
        int m = len(a);
        int n = len(b);
        int **arr = new int *[m+1];
        for(int j=0;j<=m;j++) {
            arr[j] = new int[n+1];
        }
        
        init(arr, m, n);
        int result = lcs(arr, a,b, len(a), len(b));
        cout << result << endl;

        for(int j=0;j<=m;j++) {
            delete[] arr[j];
        }
        delete[] arr;
    }
    return 0;
}