#include <iostream>
using namespace std;
#define NUM_COIN 3
int coin[NUM_COIN] = {1,5,10};

void init(int *a, int *b, int n){
    for(int i=0;i<=n;i++) {
        a[i] = -1;
        b[i] = -1;
    }
}

int exchange(int *used, int *last, int change, int *coin, int n) {
    if(change==0) {
        used[0] = 0;
        last[0] = 0;
        return 0;
    }

    if(used[change] != -1){
        return used[change];
    }

    int min = change;
    int minPos;
    for(int i=0;i<n;i++) {
        if(change-coin[i]<0) {
            continue;
        }
        int tmp = exchange(used,last,change-coin[i], coin, n);
        if(min>tmp) {
            min = tmp;
            minPos = i;
        }
    }

    used[change] = min+1;
    last[change] = coin[minPos];

    return min+1;
}

void recon(int *last, int n) {
    if(n>0) {
        recon(last, n-last[n]);
        cout << last[n] << " ";
    }
}

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int t=0;t<numTestCase;t++) {
        int change;
        cin >> change;
        int *used = new int[change+1];
        int *last = new int[change+1];

        int n;
        cin >> n;
        int *coin = new int[n];
        for(int i=0;i<n;i++){
            cin >> coin[i];
        }


        init(used, last, change);
        cout << exchange(used,last, change, coin, n) << endl;
        // recon(last, change);
        delete[] used;
        delete[] last;
        delete[] coin;
    }
    return 0;
}