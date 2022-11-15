#include <iostream>
using namespace std;
#define MAX_STR 1001

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

int lcs(int **L, int **S, char a[], char b[], int aN, int bN) {
    for(int i=0;i<=aN;i++) {
        for(int j=0;j<=bN;j++) {
            if(i==0 || j==0) {
                L[i][j] = 0;
            } else if (a[i-1]==b[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
                S[i][j] = 0;
            } else {
                L[i][j] = max(L[i-1][j], L[i][j-1]);
                if(L[i][j] == L[i][j-1]) {
                    S[i][j] = 1;
                } else {
                    S[i][j] = 2;
                }
            }
        }
    }

    return L[aN][bN];
}

void printLCS(char s[], char t[], int m, int n, int **S)
{
    if(m==0 || n==0)
        return;
    if(S[m][n] == 0)
    {
        printLCS(s, t, m-1, n-1,S);
        cout << s[m-1];
    }
    else if(S[m][n] == 1)
        printLCS(s, t, m, n-1,S);
    else if(S[m][n] == 2)
        printLCS(s, t, m-1, n,S);
}

void print(int **S, int m, int n) {
    for(int i=0;i<=m;i++) {
        for(int j=0;j<=n;j++) {
            cout << S[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int numTestCase =1;
    for(int i=0;i<numTestCase;i++) {
        char aStr[MAX_STR];
        char bStr[MAX_STR];
        cin >> aStr >> bStr;

        int aN = len(aStr);
        int bN = len(bStr);

        int **S = new int*[aN+1];
        int **L = new int*[aN+1];
        for(int j=0;j<=aN;j++) {
            S[j] = new int[bN+1];
            L[j] = new int[bN+1];
        }

        cout << lcs(L, S, aStr, bStr, aN, bN) << "\n";
        //printLCS(aStr, bStr, aN, bN, S);
        //cout << endl; 
        // print(L,aN,bN);
        // print(S, aN, bN);
        /*
        1
        def efg 
        2 
        */
        
        for(int j=0;j<=aN;j++) {
            delete[] S[j];
            delete[] L[j];
        }
        delete[] S;
        delete[] L;
    }
    return 0;
}