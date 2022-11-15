#include <iostream>
using namespace std;

int chainMatrix(int n, int *d, int **M, int **P) {
    for(int i=1;i<=n;i++) {
        M[i][i] = 0;
    }

    for(int dia=1;dia<=n-1;dia++) {
        for(int i=1;i<=n-dia;i++) {
            int j=i+dia;
            
            int min = M[i][i] + M[i+1][j]+ d[i-1]*d[i]*d[j];
            int minPos = i;
            for(int k=i+1;k<j;k++) {
                int temp = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j];
                if(min>temp) {
                    min = temp;
                    minPos = k;
                }
            }
            M[i][j] = min;
            P[i][j] = minPos;
        }
    }

    return M[1][n];
}

void order(int i, int j, int **P) {
    if(i==j) {
        cout <<"M" << i;
    } else {
        int k = P[i][j];
        cout << "(";
        order(i,k, P);
        order(k+1,j, P);
        cout << ")";
    }
}

void print(int **M, int n) {
    for(int i=0;i<=n;i++) {
        for (int j=0;j<=n;j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

int main () {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        int n;
        cin >> n;
        int *matrix = new int[n+1];
        int **M = new int *[n+1];
        int **P = new int *[n+1];
        for(int j=0;j<=n;j++){
            M[j] = new int[n+1];
            P[j] = new int[n+1];
        }

        for(int j=0;j<=n;j++) {
            cin >> matrix[j];
        }
        int result = chainMatrix(n, matrix, M, P);
        //print(M,n);
        order(1,n, P);
        cout << endl;
        cout << result << endl;
        
        for(int j=0;j<=n;j++) {
            delete[] M[j];
            delete[] P[j];
        }
        delete[] M;
        delete[] P;
        delete[] matrix;
    }
    return 0;
}