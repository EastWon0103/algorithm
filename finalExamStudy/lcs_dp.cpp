#include <iostream>
using namespace std;
#define MAX 1000
#define UP 1
#define LEFT 2
#define COR 3
#define NO 4

int L[MAX][MAX];
int P[MAX][MAX];

int len(char a[]) {
    int i;
    for(i=0;i<MAX;i++) {
        if(a[i]=='\0') {
            break;
        }
    }
    return i;
}

int lcs(char a[], char b[], int lenA, int lenB) {
    for(int i=0;i<=lenA;i++){
        L[i][0] = 0;
        P[i][0] = NO;
    }
    for(int i=0;i<=lenB;i++){
        L[0][i] = 0;
        P[i][0] = NO;
    }

    for(int i=1;i<=lenA;i++) {
        for(int j=1;j<=lenB;j++) {
            if(a[i-1] == b[j-1]) {
                L[i][j] = L[i-1][j-1]+1;
                P[i][j] = COR; 
            } else if (L[i][j-1] > L[i-1][j]){
                L[i][j] = L[i][j-1];
                P[i][j] = LEFT;
            } else {
                L[i][j] = L[i-1][j];
                P[i][j] = UP;
            }
        }
    }

    return L[lenA][lenB];
}

void order(char b[], int i, int j) {
    if(i!=0 && j!=0) {
        if(P[i][j] == COR) {
            order(b, i-1,j-1);
            cout << b[j-1];
        } else if(P[i][j] == UP) {
            order(b, i-1,j);
        } else {
            order(b, i,j-1);
        }
    }
}

int main() {
    char a[MAX], b[MAX];
    cin >> a >> b;
    int lenA = len(a);
    int lenB = len(b);

    int result = lcs(a,b,lenA, lenB);
    cout << result << endl;
    order(b,lenA, lenB);
    cout << endl;

    return 0;
}