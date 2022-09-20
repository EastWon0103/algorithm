#include <iostream>
using namespace std;

int gcd(int a, int b);

int main() {
    int numTestCase;
    cin >> numTestCase;

    for (int i=0; i<numTestCase; i++){
        int a;
        int b;

        cin >> a;
        cin >> b;

        cout << gcd(a,b) << endl;
    }

    return 0;
}

int gcd(int a, int b) {
    if(b==0){
        return a;
    } else {
        return gcd(b, a%b);
    }
}