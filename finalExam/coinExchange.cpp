#include <iostream>
using namespace std;
#define NONE -1

void printArr(int **arr, int n, int k) {
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=k;j++) {
            cout << arr[i][j] <<  " ";
        }
        cout << "\n";
    }
}

void init(int **arr, int n, int k) {
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=k;j++) {
            arr[i][j] = NONE;
        }
    }

}

//memorization
int coinExchange(int *coin, int **arr, int n, int k) {
    if(n==0 && k>0) {
        arr[n][k] = 0;
        return 0;
    }

    if(k==0) {
        arr[n][k] = 1;
        return 1;
    }

    if(k<0) {
        return 0;
    }

    if(arr[n][k] != -1) {
        return arr[n][k];
    }
    //[n-1][k] + [n][k-cn];

    int a = coinExchange(coin, arr, n-1, k);
    int b = coinExchange(coin, arr, n, k-coin[n-1]);

    arr[n][k] = a+b;
    
    return arr[n][k];
}

// bottom ups
int coinExchange2(int *coin, int **arr, int n, int k) {
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=k;j++) {
            if(i==0 && j>0) {
                arr[i][j] = 0;
            } else if (j==0) {
                arr[i][j] = 1;
            } else {
                int tmp = j-coin[i-1];
                int numbComb = arr[i-1][j];
                if(tmp >= 0) {
                    numbComb += arr[i][tmp];
                }

                arr[i][j] = numbComb;
            }
        }
    }
    return arr[n][k];
}

int main() {
    int numTestCase;
    cin >> numTestCase;

    for(int i=0;i<numTestCase;i++) {
        int n,k;
        cin >> n >> k;

        int *coin = new int[n];
        for(int j=0;j<n;j++) {
            cin >> coin[j];
        }

        int **arr = new int *[n+1];
        for(int j=0;j<=n;j++) {
            arr[j] = new int[k+1];
        }

        init(arr, n, k);
        // memorization + recursion
        int result = coinExchange(coin, arr, n, k);
        cout << result << endl;
        init(arr, n, k);

        // bottom up
        result = coinExchange2(coin, arr, n, k);
        cout << result << endl;
        printArr(arr,n,k);


        delete[] coin;
        for(int j=0;j<=n;j++) {
            delete[] arr[j];
        }
        delete[] arr;
    }
    return 0;
}