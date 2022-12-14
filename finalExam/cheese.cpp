#include <iostream>
#include <algorithm>
using namespace std;

/*
치즈1: 6 600
치즈2: 3 150
치즈3: 4 160
치즈4: 8 160
*/


struct Cheese {
    int w;
    int p;
};

bool compare(Cheese a, Cheese b) {
    int aV = a.p / a.w;
    int bV = b.p / b.w;

    return aV > bV;
}

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        int n, bagW;
        cin >> bagW >> n;
        Cheese *store = new Cheese[n];
        for(int j=0;j<n;j++) {
            int w,v;
            cin >> w >> v;
            store[j] = (Cheese){w,v};
        }

        sort(store, store+4, compare);
        
        int pos = 0;
        int price = 0;
        
        while(pos<n && bagW>0) {
            while(store[pos].w > bagW && store[pos].w > 0) {
                store[pos].p -= store[pos].p / store[pos].w;
                store[pos].w -= 1;
            }
            bagW -= store[pos].w;
            price += store[pos].p;
            pos++;
        }

        cout << price << endl;

        delete[] store;
    }
    return 0;
}