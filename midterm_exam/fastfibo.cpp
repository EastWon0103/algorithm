#include <iostream>
using namespace std;

int F[2][2] = {{1,1},{1,0}};

void mul(int m1[2][2], int m2[2][2]) {
    int a = m1[0][0]*m2[0][0] + m1[0][1] * m2[1][0];
    int b = m1[0][0]*m2[1][0] + m1[0][1] * m2[1][1];
    int c = m1[1][0]*m2[0][0] + m1[1][1] * m2[1][0];
    int d = m1[1][0]*m2[1][0] + m1[1][1] * m2[1][1];

    m2[0][0] = a%1000;
    m2[0][1] = b%1000;
    m2[1][0] = c%1000;
    m2[1][1] = d%1000;
}

void pow(int m1[2][2]) {
    int newA[2][2];
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            newA[i][j] = m1[i][j];
        }
    }

    mul(newA, m1);
}

void fastfibo(int n, int a[2][2]) {
    if(n==1) {
        a[1][1] = 0;
        a[1][0] = 1;
        a[0][1] = 1;
        a[0][0] = 1;
    } else if(n==0){
        a[1][1] = 0;
        a[1][0] = 0;
        a[0][1] = 1;
        a[0][0] = 1;
    } else {
        int result;
        int tmp;
        if(n%2==0) {
            fastfibo((n)/2,a);
            pow(a);
        } else {
            fastfibo((n-1)/2,a);
            pow(a);
            mul(F,a); 
        }
        
    }
}

void print(int m[2][2]) {
    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int nt;
    cin >> nt;
    for(int i=0;i<nt;i++) {
        int n;
        cin >> n;
        int a[2][2] = {{1,1},{1,0}};
        fastfibo(n, a);
        cout << a[1][0] << endl;
    }

    return 0;
}