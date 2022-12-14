#include <iostream>
using namespace std;
#define MAX_SIZE 1001
#define NUM_CHAR 3
#define OTHER -1
char abc[NUM_CHAR] = {'A', 'B', 'C'};

int findRow(char alpha) {
    switch (alpha)
    {
    case 'A':
        return 0;
    case 'B':
        return 1;
    case 'C':
        return 2;   
    default:
        return OTHER;
    }
} 

int len(char str[]) {
    int i;
    for(i=0;i<MAX_SIZE;i++) {
        if(str[i] == '\0') {
            break;
        }
    }
    return i;
}

void constructDFA(int **DFA, char pattern[], int patLen) {
    for(int i=0;i<NUM_CHAR;i++) {
        DFA[i][0] = 0;
    }

    DFA[findRow(pattern[0])][0] = 1;

    int X=0;
    int edgeCount = 1;
    for(int i=1;i<=patLen;i++) {
        for(int c=0;c<NUM_CHAR;c++) {
            DFA[c][i] = DFA[c][X];
            if(DFA[c][i] != 0) {
                edgeCount++;
            }
        }

        int j = findRow(pattern[i]);
        if(j==OTHER) {
            break;
        }
        if(DFA[j][i] == 0) {
            edgeCount++;
        }
        DFA[j][i] = i+1;
        X = DFA[j][X];
    }
    //fix
    cout << edgeCount;
}

void printDFA(int **DFA, int patLen) {
    for(int i=0;i<NUM_CHAR;i++) {
        for(int j=0;j<=patLen;j++) {
            cout << DFA[i][j] << " ";
        }
        cout << "\n";
    }
}

// ABCABAABABABACACA
void printResult(int **DFA, char pattern[], char text[], int patLen) {
    int teLen = len(text);

    int patCount = 0;
    int i=0;
    int X=0;
    while(i<teLen) {
        if(X!=patLen && pattern[X] != text[i]) {
            //X가 패턴 길이와 맞지 않고 패턴이 맞지 않으면
            X = DFA[findRow(text[i])][X];
        } else {
            //X가 패턴 길이와 맞거나 패턴이 맞으면
            X = DFA[findRow(text[i])][X];   
        }


        if(X == patLen) {
            patCount++;
        } 

        i++;
    }

    cout << " " << patCount << "\n";
}

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        char pattern[MAX_SIZE];
        char text[MAX_SIZE];

        cin >> pattern >> text;
        int patLen = len(pattern);
        int **DFA = new int *[NUM_CHAR];

        for(int j=0;j<NUM_CHAR;j++) {
            DFA[j] = new int [patLen+1];
        }
        // cout << len(text) << endl;
        constructDFA(DFA, pattern, patLen);
        cout << endl;
        printDFA(DFA,patLen);
        printResult(DFA, pattern, text, patLen);


        for(int j=0;j<NUM_CHAR;j++) {
            delete[] DFA[j];
        }
        delete[] DFA;
    }
    return 0;
}