#include <iostream>
#include <string>
using namespace std;

int factorial(int n);

int main(){
    int testCaseNum;
    cin >> testCaseNum;
    for(int i=0;i<testCaseNum;i++){
        int num;
        cin >> num;

        int factorial_num = factorial(num);
        cout << factorial_num << endl;
    }
    return 0;
}

int factorial(int n){
    if(n == 0){
        return 1;
    }
    int result = n * factorial(n-1);
    while (1){
        if (result % 10 == 0){
            result = result/10;
        } else {
            break;
        }
    }
    
    return result % 1000;
}