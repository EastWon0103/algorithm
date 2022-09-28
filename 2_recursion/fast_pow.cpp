#include <iostream>
using namespace std;

int pow(int x, int n);

int main(){
    int numTestCase;

    cin >> numTestCase;

    for(int i=0;i<numTestCase;i++){
        int num, indice;
        cin >> num >> indice;

        int result = pow(num, indice);

        cout << result << endl;
    }

    return 0;
}

int pow(int x, int n) {
    if(n==0){
        return 1;
    } else if(n%2!=0){ // odd
        int y = pow(x, (n-1)/2);
        int result = x * y * y;
        return result % 1000;
    } else { // even
        int y = pow(x, n/2);
        int result = y*y;
        return result % 1000;
    }   
}