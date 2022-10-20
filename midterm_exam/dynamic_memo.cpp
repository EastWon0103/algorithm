#include <iostream>
using namespace std;

#define NUM_OF_COIN 7
int COIN[NUM_OF_COIN] = {1,5,7,12,23,50,100};

void initArray(int *lastCoin, int *usedCoin, int change) {
    for(int i=0;i<change;i++) {
        lastCoin[i] = -1;
        usedCoin[i] = -1;
    }
}


int memo_coin(int *lastCoin, int *usedCoin, int change) {
    // 값이 있다면
    // cout<<change << endl;
    if(change<=0) {
        lastCoin[0] = 0;
        usedCoin[0] = 0;
        return 0;
    }
    if(usedCoin[change] != -1) {
        
        // cout<<"here2: " << usedCoin[change] << " " << change << endl;
        return usedCoin[change];
    }
    // 값이 없다면
    int min = change;
    int coinPos = -1;
    int i;
    for(i=NUM_OF_COIN-1;i>=0;i--) {
        // cout << "i&coin: " << i << " " << COIN[i] << endl;
        if(change-COIN[i]<0) {
            continue;
        }
        // cout << "change coin: " << change-COIN[i] << endl;
        int temp = memo_coin(lastCoin, usedCoin, change-COIN[i]);
        if(min > temp) {
            min = temp;
            coinPos = i;
        }
    }
    // cout << i << ": " << min << endl;

    usedCoin[change] = min+1;
    lastCoin[change] = COIN[coinPos];

    return usedCoin[change];
    // // 이미 값이 있따면?
    // if(lastCoin[change] != -1){

    // }
    // 값이 없으면 실행
    
    // for(int i=)

    // C(k) = c(k-i)-coin
}

void reconstruct(int *lastCoin, int *coinUsed, int change) {
    if(change > 0){
        reconstruct(lastCoin, coinUsed, change-lastCoin[change]);
        cout << lastCoin[change] << " ";
    }
}


int main () {
    int exchange;
    cin >> exchange;
    int *last = new int[exchange+1];
    int *used = new int[exchange+1];
    initArray(last, used, exchange+1);
    // for(int i=0;i<exchange+1;i++) {
    //     cout << last[i] << " ";
    // }
    // cout << endl;
    cout << memo_coin(last, used, exchange) << endl;
    reconstruct(last, used, exchange);

    delete[] last;
    delete[] used;

    return 0;
}