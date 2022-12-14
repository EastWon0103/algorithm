#include <iostream>
using namespace std;
#define MAX_SIZE 1001

int len(char str[]) {
    int i;
    for(i=0;i<MAX_SIZE;i++) {
        if(str[i] == '\0') {
            break;
        }
    }
    return i;
}

void printFail(int *fail, int len) {
    for(int i=0;i<len;i++) {
        cout << fail[i] << " ";
    }
    cout << endl;
}

int *failFunc(char pattern[], int len) {
    int *fail = new int[len];
    fail[0] = 0;

    int j=0;
    for(int i=1;i<len;i++) {
        while(j>0 && pattern[i]!=pattern[j]) {
            j = fail[j-1];
        }

        if(pattern[i] == pattern[j]) {
            j++;
        }
        fail[i] = j;
    }

    return fail;
}

void kmp(char pattern[], char text[]) {
    int patLen = len(pattern);
    int txtLen = len(text);
    int *fail = failFunc(pattern, patLen);
    
    int j=0;
    int result = 0;
    printFail(fail,patLen);
    for(int i=0;i<txtLen;i++) {
        while(j>0 && pattern[j]!=text[i]) {
            j = fail[j-1];
        }

        if(pattern[j] == text[i]) {
            if(j==patLen-1) {
                j = fail[j];
                result++;
            } else {
                j++;
            }
        }

    }
    cout << result << endl;

    delete[] fail;
}

int main() {
    int numTestCase;
    cin >> numTestCase;

    for(int i=0;i<numTestCase;i++) {
        char pattern[MAX_SIZE];
        char text[MAX_SIZE];
        cin>>pattern >> text;
        kmp(pattern, text);
    }
    return 0;
}