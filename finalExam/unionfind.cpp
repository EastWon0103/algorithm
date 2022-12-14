#include <iostream>
using namespace std;
#define MAX_SIZE 100
int UFS[MAX_SIZE];
int SZ[MAX_SIZE];

void constructSet(int n) {
    for(int i=0;i<n;i++) {
        UFS[i] = i;
        SZ[i] = 1;
    }
}

int find(int i) {
    while(UFS[i] != i) {
        i = UFS[i];
    }
    return i;
}

bool inSameSet(int p, int q){
    return find(p) == find(q);
}

void unionSet(int p, int q) {
    int i = find(p);
    int j = find(q);
    if(i!=j) {
        UFS[i] = j;
    }
}

void unionSetImprove1(int p, int q) {
    int i = find(p);
    int j = find(q);
    if(i!=j) {
        if(SZ[i] < SZ[j]) {
            UFS[i] = j;
            SZ[j] += SZ[i];
        } else {
            UFS[j] = UFS[i];
            SZ[i] += SZ[j];
        }
    } 
}

int compressionFind(int x) {
    int parent;
    int root = x;
    // root 찾기
    while(UFS[root] != root) {
        root = UFS[root];
    }

    while(UFS[x] != root) {
        parent = UFS[x];
        UFS[x] = root;
        x = parent;
    }

    return root;
}

void compressionUnion(int p, int q) {
    int i = compressionFind(p);
    int j = compressionFind(q);
    if(i!=j) {
        UFS[i] = j;
    }
}


int main() {
    int n;
    cin >> n;
    constructSet(n);
    compressionUnion(0,1);
    compressionUnion(2,3);
    compressionUnion(0,2);

    compressionUnion(4,5);
    compressionUnion(6,7);
    compressionUnion(5,7);

    compressionUnion(0,7);


    for(int i=0;i<n;i++) {
        cout << UFS[i] << endl;
    }

    return 0;
}