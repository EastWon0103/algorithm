#include <iostream>
using namespace std;

void init(int **m, int n) {
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            m[i][j] = -1;
        }
    }
}

int chainMatrix(int i, int j, int *d, int **M) {
    if (i==j) {
        M[i][j] = 0;
        return 0;
    }
    
    if (M[i][j] != -1) {
        return M[i][j];
    }

    int min = chainMatrix(i,i,d,M) + chainMatrix(i+1,j,d,M)+d[i-1]*d[i]*d[j];
    for (int k=i+1;k<j;k++) {
        int temp = chainMatrix(i,k,d,M) + chainMatrix(k+1,j,d,M)+d[i-1]*d[k]*d[j];
        if(min>temp) {
            min = temp;
        }
    }
    
    M[i][j] = min;
    return min;
}

int main () {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        int n;
        cin >> n;
        int *matrix = new int[n+1];
        int **M = new int *[n+1];
        for(int j=0;j<=n;j++){
            M[j] = new int[n+1];
        }

        for(int j=0;j<=n;j++) {
            cin >> matrix[j];
        }
        init(M,n);
        cout << chainMatrix(1,n, matrix, M) << endl;
        
        for(int j=0;j<=n;j++) {
            delete[] M[j];
        }
        delete[] M;
        delete[] matrix;
    }
    return 0;
}