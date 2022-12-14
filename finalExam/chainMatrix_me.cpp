#include <iostream>
using namespace std;
#define MAX_SIZE 100
int M[MAX_SIZE][MAX_SIZE];

int chained(int *d,int i,int j) {
    if(i==j) {
        M[i][j] = 0;
        return 0;
    }

    if(M[i][j] != -1) {
        return M[i][j];
    }

    int min = chained(d,i,i) + chained(d,i+1,j)+d[i-1]*d[i]*d[j];
    for(int k=i+1;k<j;k++) {
        int tmp = chained(d,i,k) + chained(d,k+1,j)+d[i-1]*d[k]*d[j];
        if(min > tmp) {
            min = tmp;
        }
    }

    M[i][j] = min;
    return min;
}

void init(int m, int n) {
    for(int i=0;i<=m;i++) {
        for(int j=0;j<=n;j++) {
            M[i][j] = -1;
        }
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

        init(n,n);
        int result = chained(item,1,n);
        cout << result << endl;

        delete[] item;
        
    }
    return 0;
}