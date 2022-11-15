#include <iostream>
using namespace std;
#define MAX_STR 101
// int S[MAX_STR][MAX_STR];

int max(int a, int b) {
    if(a>b) {
        return a;
    } else {
        return b;
    }
}

int len(char str[]) {
    int i;
    for(i=0;i<MAX_STR;i++) {
        if(str[i] == '\0') {
            break;
        }
    }
    return i;
}

int lcs(int **S, char a[], char b[], int aN, int bN) {
    if(aN == 0 || bN == 0) {
        S[aN][bN] = 0;
        return 0;
    }

    if(S[aN][bN] != -1) {
        return S[aN][bN];
    }

    if(a[aN-1] == b[bN-1]) {
        S[aN][bN] = lcs(S,a,b,aN-1,bN-1) + 1;
        return S[aN][bN];
    }
    
    S[aN][bN] = max(lcs(S,a,b,aN-1,bN), lcs(S,a,b,aN,bN-1));
    return S[aN][bN];
}

void init(int **S, int m, int n) {
    for(int i=0;i<=m;i++) {
        for(int j=0;j<=n;j++) {
            S[i][j] = -1;
        }
    }
}

int main() {
    int numTestCase;
    cin>> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        char aStr[MAX_STR];
        char bStr[MAX_STR];
        cin >> aStr >> bStr;

        int aN = len(aStr);
        int bN = len(bStr);

        int **S = new int*[aN+1];
        for(int j=0;j<=aN;j++) {
            S[j] = new int[bN+1];
        }

        init(S, aN, bN);

        cout << lcs(S, aStr, bStr, aN, bN) << "\n";

        for(int j=0;j<=aN;j++) {
            delete[] S[j];
        }
        delete[] S;
    }
    return 0;
}