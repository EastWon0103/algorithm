#include <iostream>
using namespace std;

int chainMatrix(int i, int j, int *d) {
    if (i==j) {
        return 0;
    }

    int min = chainMatrix(i,i,d) + chainMatrix(i+1,j,d)+d[i-1]*d[i]*d[j];
    for (int k=i+1;k<j;k++) {
        int temp = chainMatrix(i,k,d) + chainMatrix(k+1,j,d)+d[i-1]*d[k]*d[j];
        if(min>temp) {
            min = temp;
        }
    }
    
    return min;
}

int main () {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        int n;
        cin >> n;
        int *matrix = new int[n+1];
        for(int j=0;j<=n;j++) {
            cin >> matrix[j];
        }
        cout << chainMatrix(1,n, matrix) << endl;
        delete[] matrix;
    }
    return 0;
}