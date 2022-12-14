#include <iostream>
using namespace std;
#define MAX 1000

int len(char a[]) {
    int i;
    for(i=0;i<MAX;i++) {
        if(a[i] == '\0') {
            break;
        }
    }
    return i;
}

int *getFail(char pattern[], int n) {
    int *fail = new int[n];
    fail[0] = 0;

    int j=0;
    for(int i=1;i<n;i++) {
        while(j>0 && pattern[j]!=pattern[i]) {
            j = fail[j-1];
        }

        if(pattern[j] == pattern[i]) {
            j++;
        }
        fail[i] = j;
    }
    return fail;
}

int kmp(char pattern[], char text[]) {
    int patLen = len(pattern);
    int txtLen = len(text);
    int *fail = getFail(pattern, patLen);

    for(int i=0;i<patLen;i++) {
        cout << fail[i] << " ";
    }
    cout << endl;

    int matched = 0;

    int j=0;
    for(int i=0;i<txtLen;i++) {
        while(j>0 && pattern[j]!=text[i]) {
            j = fail[j-1];
        }

        if(pattern[j] == text[i]) {
            if(j==patLen-1) {
                matched++;
                j = fail[j];
            } else {
                j++;
            }
        }
    }

    delete[] fail;
    return matched;
}

int main() {
    char pattern[MAX], text[MAX];
    cin >> pattern >> text;
    int result = kmp(pattern, text);
    cout << result << endl;
    return 0;
}