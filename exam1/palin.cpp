#include <iostream>
using namespace std;

int palindrome(int *a, int low, int high) {
    if(low>=high) {
        return 1;
    }

    if(a[low]!=a[high]) {
        return 0;
    } else {
        return palindrome(a, low+1, high-1);
    }
}

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int t=0;t<numTestCase;t++) {
        int n;
        cin >> n;
        int *a = new int[n];
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }

        cout << palindrome(a, 0, n-1) << endl;

        delete[] a;
    }
    return 0;
}