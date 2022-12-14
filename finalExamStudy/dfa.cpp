#include <iostream>
using namespace std;
#define MAX 10000
#define ALPHA 3
int DFA[ALPHA][MAX];

int getRow(char a) {
    switch(a) {
        case 'A':
            return 0;
        case 'B':
            return 1;
        case 'C':
            return 2;
        default:
            return -1;
    }
}

int len(char a[]) {
    int i;
    for(i=0;i<MAX;i++) {
        if(a[i] == '\0') {
            break;
        }
    }
    return i;
}

void printDFA(char pattern[], int n) {
    for(int i=0;i<ALPHA;i++) {
        for(int j=0;j<=n;j++) {
            cout << DFA[i][j] << " ";
        }
        
        cout << endl;
    }
}

void constructDFA(char pattern[], int n) {
    for(int i=0;i<ALPHA;i++) {
        if(getRow(pattern[0]) == i) {
            DFA[i][0] = 1;
        } else {
            DFA[i][0] = 0;
        }
    }

    int X = 0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<ALPHA;j++) {
            DFA[j][i] = DFA[j][X];
        }

        if(i == n) {
            break;
        }

        DFA[getRow(pattern[i])][i] = i+1;
        X = DFA[getRow(pattern[i])][X];
    }

    // printDFA(pattern, n);
}


int dfa(char pattern[], char text[]) {
    int patLen = len(pattern);
    int txtLen = len(text);
    constructDFA(pattern, patLen);

    int x = 0;
    int matched = 0;
    for(int i=0;i<txtLen;i++) {
        x = DFA[getRow(text[i])][x];
        if(x == patLen) {
            matched++;
        }
           
    }
    return matched;
}

int main() {
    char pattern[MAX], text[MAX];
    cin >> pattern >> text;

    cout << dfa(pattern, text) << endl;
    return 0;
}