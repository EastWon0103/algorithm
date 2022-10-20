#include <iostream>
using namespace std;

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

int getW(char str[], int n) { 
    int sum = 0;
    for(int i=0;i<=n;i++) {
        if(i%2 == 0) {
            sum += str[i] - 'a';
        } else {
            sum += -(str[i] - 'a');
        }
    }

    if(sum > 0) {
        return 1;
    } else {
        return 0;
    }
}

int len(char str[]) {
    int i;
    for(i=0;i<10;i++){
        if(str[i] == '\0'){
            break;
        }
    }

    return i-1;
}

int permutation(char str[], int start, int end) {
    if(end-start == 0) {
        cout << str << " ";
        return getW(str, end);
    }
    int result = 0;
    for(int i=start;i<=end;i++) {
        swap(str[start], str[i]);
        result += permutation(str, start+1, end);
        swap(str[start], str[i]);
    }

    return result;
}

int main() {
    // int n;
    // cin >> n;
    char str[10];
    cin >> str;

    cout << permutation(str, 0, len(str)) << endl;

    return 0;
}