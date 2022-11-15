#include <iostream>
using namespace std;

int gcd(int x, int y) {
    if(x%y == 0) {
        return y;
    }

    return gcd(y, x%y);
}

int main() {
    int a,b;
    cin >> a >> b;
    if(a>b) {
        int g = gcd(a,b);
        cout << g << " " << a*b/g << "\n";
    } else {
        int g = gcd(a,b);
        cout << g << " " << a*b/g << "\n";
    }
    return 0;
}