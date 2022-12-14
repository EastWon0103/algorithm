#include <iostream>
using namespace std;

// https://www.acmicpc.net/problem/12865
// 평범한 배낭 - 백준
struct Item {
    int w;
    int v;
};
int DP[101][100001];

int max(int a, int b) {
    if(a>b) {
        return a;
    } 
    return b;
}

void solution(Item *items, int n, int bagW) {
    for(int i=0;i<=bagW;i++) {
        DP[0][i] = 0;
    }
    for(int i=0;i<=n;i++) {
        DP[i][0] = 0;
    }


    for(int i=1;i<=n;i++) {
        for(int j=1;j<=bagW;j++) {
            if(j-items[i-1].w >= 0) {
                DP[i][j] = max(DP[i-1][j], DP[i-1][j-items[i-1].w] + items[i-1].v);
            } else {
                DP[i][j] = DP[i-1][j];
            }
        }
    }

    cout << DP[n][bagW] << endl;
}


int main() {
    int n, bagW;
    cin >> n >> bagW;
    
    Item *items = new Item[n];
    for(int i=0;i<n;i++) {
        int w, v;
        cin >> w >> v;
        items[i] = (Item) {w,v};
    }

    solution(items, n, bagW);

    delete[] items;
    return 0;
}