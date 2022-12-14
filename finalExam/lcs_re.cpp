#include <iostream>
using namespace std;
#define MAX_SIZE 11

int len(char str[]) {
    int l;
    for(l=0;l<MAX_SIZE;l++) {
        if(str[l] == '\0') {
            return l;
        }
    }
    return l;
}

int lcs(char a[], char b[], int m, int n) {
    if(m==-1 || n == -1) {
        return 0;
    }

    if(a[m]==b[n]) {
        return lcs(a,b,m-1,n-1) +1;
    }
    int x = lcs(a,b,m-1,n);
    int y = lcs(a,b,m,n-1);
    if(x>y) {
        return x;
    }
    return y;
}

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        char a[MAX_SIZE];
        char b[MAX_SIZE];
        cin >> a >> b;

        int result = lcs(a,b, len(a)-1, len(b)-1);
        cout << result << endl;
    }
    return 0;
}