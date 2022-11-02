#include <iostream>
using namespace std;

void init(int **arr, int n, int k) {
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=k;j++) {
            if(j==0 || i==j) {
                arr[i][j] = 1;
            } else {
                arr[i][j] = 0;
            }
        }
    }
}
void print(int **a, int n, int k) {
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=k;j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
int binom(int **arr, int n, int k) {
    if(k==0) {
        return 1;
    }
    if(n==k) {
        return 1;
    }
    if(arr[n][k] != 0) {
        return arr[n][k];
    }

    int result = binom(arr, n-1, k-1) + binom(arr, n-1, k);
    arr[n][k] = result%1000;
    return result%1000;
}

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        int n,k;
        cin >> n >> k;
        int **arr = new int*[n+1];
        for(int i=0;i<=n;i++) {
            arr[i] = new int[k+1];
        }
        init(arr,n,k);
        // print(arr,n,k);
        cout << binom(arr, n,k)<<endl;

        for(int i=0;i<=n;i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
    return 0;
}