#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(a,a+n);
    
    int result = 0;
    int w = 0;
    for(int i=0;i<n;i++) {
        w += a[i];
        //cout << w << endl;
        result += w;
    }

    cout << result << endl;
    
    delete[] a;
    return 0;
}