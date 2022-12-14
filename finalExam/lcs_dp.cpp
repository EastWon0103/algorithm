#include <iostream>
using namespace std;
#define MAX_SIZE 1000
#define NONE 0
#define LEFT 1
#define UP 2
#define CENTER 3

int len(char str[]) {
    int l;
    for(l=0;l<MAX_SIZE;l++) {
        if(str[l] == '\0') {
            return l;
        }
    }
    return l;
}

int lcs(int **arr,int **alpha, char a[], char b[], int m, int n) {
    for(int i=0;i<=n;i++) {
        alpha[0][i] = NONE;
        arr[0][i] = 0;
    }
    for(int j=0;j<=m;j++) {
        alpha[j][0] = NONE;
        arr[j][0] = 0;
    }

    for(int i=1;i<=m;i++) {
        for(int j=1;j<=n;j++) {
            if(a[i-1] == b[j-1]) {
                arr[i][j] = arr[i-1][j-1] + 1;
                alpha[i][j] = CENTER;
            } else {
                int x = arr[i-1][j];
                int y = arr[i][j-1];
                if(x>y) {
                    arr[i][j] = x;
                    alpha[i][j] = UP;
                } else {
                    arr[i][j] = y;
                    alpha[i][j] = LEFT;
                }
                
            }
        }
    }

    return arr[m][n];
}

void printAlpha(int **alpha, int m, int n, char a[], char b[]) {
    if(m>0 && n>0) {
        int temp = alpha[m][n];
        if(temp == CENTER) {
            printAlpha(alpha, m-1, n-1,a,b);
            cout << a[m-1];
        } else if(temp==LEFT) {
            printAlpha(alpha, m, n-1,a,b);
        } else {
            printAlpha(alpha, m-1, n,a,b);
        }
        
    }
}


int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        char a[MAX_SIZE];
        char b[MAX_SIZE];
        cin >> a >> b;
        int m = len(a);
        int n = len(b);
        int **arr = new int *[m+1];
        int **alpha = new int *[m+1];
        for(int j=0;j<=m;j++) {
            arr[j] = new int[n+1];
            alpha[j] = new int [n+1];
        }
        
        int result = lcs(arr,alpha, a,b, len(a), len(b));
        cout << result << " ";
        printAlpha(alpha, len(a), len(b),a,b);
        cout << endl;

        for(int j=0;j<=m;j++) {
            delete[] arr[j];
            delete[] alpha[j];
        }
        delete[] arr;
        delete[] alpha;
    }
    return 0;
}