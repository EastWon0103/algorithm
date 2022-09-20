#include <iostream>
using namespace std;

int fibo(int num);

int main(){
    int testCaseNum;
    cin >> testCaseNum;
    for(int i=0;i<testCaseNum;i++){
        int iterNum;
        cin >> iterNum;

        cout << fibo(iterNum) << endl;
    }
    return 0;
}

int fibo(int num){
    if(num == 0) {
        return 0;
    } else if(num == 1){
        return 1;
    }

    return fibo(num-1) + fibo(num-2); 
}