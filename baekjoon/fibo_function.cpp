#include <iostream>
using namespace std;

void fibo(int *z, int *o, int n) {
    if(n==0) {
        z[0] = 1;
        o[0] = 0;
        return;
    }

    if(n==1) {
        z[1] = 0;
        o[1] = 1;
        return;
    }

    if(z[n]!=-1){
        return;
    }

    fibo(z,o,n-1);
    fibo(z,o,n-2);
    z[n] = z[n-1] + z[n-2];
    o[n] = o[n-1] + o[n-2];
    return;
}

void init(int *a, int *b, int n) {
    for(int i=0;i<=n;i++) {
        a[i] = b[i] = -1;
    }
}
// 0은 zero 한 개 one은 0개
// 1은 

int main() {
    int testCase;
    cin >> testCase;
    for(int i=0;i<testCase;i++) {
        int n;
        cin >> n;

        int *zero = new int[n+1];
        int *one = new int[n+1];
        init(zero, one, n);
        fibo(zero, one, n);
        cout << zero[n] << " " << one[n] << "\n";
        delete[] zero;
        delete[] one;
    }
    return 0;
}