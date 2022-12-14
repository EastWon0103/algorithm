#include <iostream>
using namespace std;
#define MAX_SIZE 100
int M[MAX_SIZE][MAX_SIZE];
int P[MAX_SIZE][MAX_SIZE];

int chained(int *d,int n) {
    for(int i=1;i<=n;i++) {
        M[i][i] = 0;
    }

    //digonal 계산
    for(int dia=1;dia<=n-1;dia++) {
        // 행렬 i(row);
        for(int i=1;i<=n-dia;i++) {
            // j 계산
            int j=i+dia;

            int k=i;
            int min = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j];
            int minPos = i;
            // k계산
            for(k+=1;k<j;k++) {
                int tmp = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j];
                if(min > tmp) {
                    min = tmp;
                    minPos = k;
                }
            }

            M[i][j] = min;
            P[i][j] = minPos;
        }
    }

    return M[1][n];
}

void print(int n) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

void init(int n) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            M[i][j] = 0;
        }
    }
}

void order(int i, int j) {
    if(i==j) {
        cout << "M" <<i;
    } else {
        int k = P[i][j];
        cout << "(";
        order(i,k);
        order(k+1,j);
        cout << ")";
    }
}

int main() {
    int numTestCase;
    cin>> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        int n;
        cin >> n;
        int *item = new int [n+1];
        for(int j=0;j<=n;j++) {
            cin >> item[j];
        }

        init(n);
        int result = chained(item,n);
        cout << result << endl;
        order(1,n);
        cout << endl;
        print(n);
        delete[] item;
        
    }
    return 0;
}