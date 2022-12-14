#include <iostream>
using namespace std;
#define COIN_NUM 4
#define MAX 10001
int coin[COIN_NUM] = {1,2,3,5};

int DP[COIN_NUM+1][MAX]; 

int exchange(int n) {
    for(int i=1;i<=n;i++) {
        DP[0][i] = 0;
    }

    for(int i=0;i<=COIN_NUM;i++) {
        DP[i][0] = 1;
    }

    for(int i=1;i<=COIN_NUM;i++) {
        for(int j=1;j<=n;j++) {
            int alpha = 0;
            if(j-coin[i-1] >= 0) {
                alpha = DP[i][j-coin[i-1]];
            }

            DP[i][j] = DP[i-1][j] + alpha;
        }
    }

    return DP[COIN_NUM][n];
}

int main() {
    int n;
    cin >> n;
    cout << exchange(n) << endl;
    return 0;
}