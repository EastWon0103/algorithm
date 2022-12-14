#include <iostream>
using namespace std;
#define MAX_SIZE 1001

int DFA[3][MAX_SIZE];
char alpha[3] = {'A', 'B', 'C'};

int len(char str[]) {
    int i;
    for(i=0;i<MAX_SIZE;i++) {
        if(str[i]=='\0') {
            break;
        }
    }

    return i;
}

int getRow(char a) {
    switch (a)
    {
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

void printDFA(int patLen) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<=patLen;j++) {
            cout << DFA[i][j] << " ";
        }
        cout << "\n";
    }
    
}

void constructDFA(char pattern[], int len) {
    for(int i=0;i<3;i++) {
        if(pattern[0]==alpha[i]) {
            DFA[i][0] = 1;
        } else {
            DFA[i][0] = 0;
        }
    }
    int X = 0;
    int xCnt = 1;

    for(int j=1;j<len;j++) {
        for(int i=0;i<3;i++) {
            int tmp = DFA[i][X];
            if(tmp != 0) {
                xCnt++;
            }
            DFA[i][j] = tmp;
        }

        int matched = getRow(pattern[j]);
        if(DFA[matched][j] == 0) {
            xCnt++;
        }
        DFA[matched][j] = j+1;
        X = DFA[matched][X];
    }
    
    for(int i=0;i<3;i++) {
        int tmp = DFA[i][X];
        if(tmp != 0) {
            xCnt++;
        }
        DFA[i][len] = tmp;
    }
    cout << xCnt << " ";
}

void matching(char pattern[], char text[]) {
    int patLen = len(pattern);
    int txtLen = len(text);
    constructDFA(pattern, patLen);
    // printDFA(patLen);

    int X=0;
    int result = 0;
    for(int i=0;i<txtLen;i++) {
        X = DFA[getRow(text[i])][X];
        
        if(X==patLen) {
            result++;
        }
    }
    cout << result << endl;
}

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        char pattern[MAX_SIZE];
        char text[MAX_SIZE];
        cin >> pattern >> text;
        matching(pattern, text);        
    }
    return 0;
}