#include <iostream>
using namespace std;

int pow(int n, int i) {
    if(i==0) {
        return 1;
    }
    int tmp;
    int result;
    if(i%2 == 0) {
        tmp = pow(n,i/2);
        result = (tmp*tmp);
    } else {
        tmp = pow(n,(i-1)/2);
        result = n * (tmp*tmp);
    }

    while(result%10 == 0) {
        result = result%10;
    }

    return result %1000;
}

int main() {
    int num,ind;
    cin >> num;
    cin >> ind;

    cout << pow(num, ind) << endl;
    return 0;
}