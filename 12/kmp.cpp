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

int *getFail(char pattern[]) {
    int n = len(pattern);
    int *fail = new int [n];
    fail[0] = 0;
    int i,j;
    for(i=1,j=0;i<n;i++) {
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

void printFail(int *fail, int n) {
    for(int i=0;i<n;i++) {
        cout << fail[i] << " ";
    }
    cout << endl;
}

void kmp(char pattern[], char text[]) {
    int *fail = getFail(pattern);
    int n = len(text);
    int m = len(pattern);

    printFail(fail, m);

    int j=0;
    int result = 0;

    for(int i=0;i<n;i++) {
        while(j>0 && text[i]!=pattern[j]) {
            j = fail[j-1];
        }

        if(text[i]==pattern[j]) {
            // j의 길이가 패턴의 길이와 같을 때 (패턴이 매칭 되었다고 고정할 때)
            if(j==m-1) {
                j = fail[j];
                result++;
            } else {
                j++;
            }
        }
    }

    cout << result << "\n";
    delete[] fail;
}

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        char pattern[MAX_SIZE];
        char text[MAX_SIZE];

        cin >> pattern >> text;
        kmp(pattern, text);
    }
    return 0;
}