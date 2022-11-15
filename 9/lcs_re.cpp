#include <iostream>
using namespace std;
#define MAX_STR 11

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

int lcs(char a[], char b[], int aN, int bN) {
    if(aN == -1 || bN == -1) {
        return 0;
    }

    if(a[aN] == b[bN]) {
        return lcs(a,b,aN-1,bN-1) +1;
    }
    
    return max(lcs(a,b,aN-1,bN), lcs(a,b,aN,bN-1));
}

int main() {
    int numTestCase;
    cin>> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        char aStr[MAX_STR];
        char bStr[MAX_STR];
        cin >> aStr >> bStr;

        cout << lcs(aStr, bStr, len(aStr)-1, len(bStr)-1) << "\n";
    }
    return 0;
}