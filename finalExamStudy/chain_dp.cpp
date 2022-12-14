#include <iostream>
using namespace std;
#define MAX 10000
#define INF 100000

int M[MAX][MAX];
int K[MAX][MAX];

int chainedMatrix(int n, int *d) {
    for(int i=1;i<=n;i++) {
        M[i][i] = 0;
    }

    for(int dia=1;dia<=n-1;dia++) {
        for(int i=1;i<=n-dia;i++) {
            int j=i+dia;

            int min = INF;
            int minPos;
            for(int k=i;k<=j-1;k++) {
                int tmp = M[i][k]+M[k+1][j]+ d[i-1]*d[k]*d[j];
                if(min>tmp) {
                    min = tmp;
                    minPos = k;
                }
            }

            M[i][j] = min;
            K[i][j] = minPos;
        }
    }

    return M[1][n];
}

void order(int i, int j) {
    if(i==j) {
        cout << "M" << i;
    } else {
        int k = K[i][j];
        cout <<"(";
        order(i,k);
        order(k+1,j);
        cout <<")";
    }
}

int main() {
    int n;
    int *d = new int[n+1];
    cin >> n;
    for(int i=0;i<=n;i++) {
        cin >> d[i];
    }

    int result = chainedMatrix(n,d);
    cout << result << endl;
    order(1, n);
    cout << endl;

    delete[] d;
    return 0;
}