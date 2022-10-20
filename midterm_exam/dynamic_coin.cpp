#include <iostream>
using namespace std;

#define NUM_OF_COIN 7
int COIN[NUM_OF_COIN] = {1,5,10,15,21,25,50};

// 6분석 5로 떨어짐
// 나머지 1 찾음
// 8분석 5로 떨어짐
// 나머지 3 = 3 ->4개씀
// 1로 떨어짐
// 나머지 7 = 3 ->4개씀


// 0 1 2 3 4 5 6 7
// 0 1 2 3 4 1 2 3
// 0 1 1 1 1 5 5 5

void dynamic_coin(int *lastCoin, int *coinUsed, int change) {
    int j;

    for(int i=0;i<=change;i++) {
        if(i==0) {
            lastCoin[0] = 0;
            coinUsed[0] = 0;
            // cout<< i << ": " << 0 << " " << 0 << endl;
        } else {
            int min = i;
            int minPos = -1;
            for(j=NUM_OF_COIN-1;j>=0;j--) {
                if(i-COIN[j] < 0) {
                    continue;
                }
                
                if(min > coinUsed[i-COIN[j]]) {
                    min = coinUsed[i-COIN[j]];
                    minPos = j;
                }
            }
            // cout<< i << ": " << min+1 << " " << COIN[j] << endl;
            coinUsed[i] = min+1;
            lastCoin[i] = COIN[minPos];
        }
    }
}

void printArray(int *a, int n) {
    for(int i=0;i<n;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
} 

void reconstruct(int *lastCoin, int *coinUsed, int change) {
    if(coinUsed[change] > 0) {
        reconstruct(lastCoin, coinUsed, change - lastCoin[change]); 
        cout << lastCoin[change] << " ";
    }
}

int main() {
    int exchange;
    cin >> exchange;
    
    int *last = new int[exchange+1];
    int *used = new int[exchange+1];

    dynamic_coin(last, used, exchange);
    cout << used[exchange] << endl;
    reconstruct(last, used, exchange);
    cout << endl;

    delete[] last;
    delete[] used;


    return 0;
}