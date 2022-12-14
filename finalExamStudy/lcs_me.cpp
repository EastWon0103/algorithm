#include <iostream>
using namespace std;
#define MAX 1000

int L[MAX][MAX];
#define UNMARK -1

int len(char a[]) {
    int i;
    for(i=0;i<MAX;i++) {
        if(a[i]=='\0') {
            break;
        }
    }
    return i;
}

void initL(int n, int m) {
    for(int i=0;i<=n;i++) {
        for(int j = 0; j<=m;j++) {
            L[i][j] = UNMARK;
        }
    }
}

int find(char a[], char b[], int lenA, int lenB) {
    if(lenA == 0 || lenB == 0) {
        return 0;
    }

    if(L[lenA][lenB] != UNMARK) {
        return L[lenA][lenB];
    }

    if(a[lenA-1] == b[lenB-1]) {
        L[lenA][lenB] = find(a,b,lenA-1,lenB-1)+1;
        return L[lenA][lenB];
    }

    int x = find(a,b,lenA-1, lenB);
    int y = find(a,b,lenA, lenB-1);

    if(x>y) {
        L[lenA][lenB] = x;
        return x;
    }
    L[lenA][lenB] = y;
    return y;
}


int main() {
    char a[MAX], b[MAX];
    cin >> a >> b;
    int lenA = len(a);
    int lenB = len(b);
    initL(lenA, lenB);

    cout << find(a,b,lenA, lenB) << endl;

    return 0;
}