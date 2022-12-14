#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10000

int US[MAX];
struct Edge {
    int a;
    int b;
    int w;
};

Edge arr[MAX];
Edge F[MAX];

void constructSet(int n) {
    for(int i=1;i<=n;i++) {
        US[i] = i;
    }
}

int find(int p) {
    int root = p;
    while(US[root]!= root) {
        root = US[root];
    }

    int parent;
    while(US[p] != root) {
        parent = US[p];
        US[p] = root;
        p = parent;
    }
    return root;
}

void unionSet(int p, int q) {
    int x = find(p);
    int y = find(q);

    if(x!=y) {
        US[x] = US[y];
    }
}

bool isSame(int p, int q) {
    return find(p) == find(q);
}

bool compare(Edge a, Edge  b) {
    return a.w < b.w;
}

int kruskal(int n, int edgeN) {
    constructSet(n);
    sort(arr, arr+edgeN, compare);

    int edgeCount = 0;
    int i = 0;
    while(edgeCount < n-1) {
        Edge e = arr[i];
        if(!isSame(e.a, e.b)) {
            unionSet(e.a,e.b);
            F[edgeCount++] = e;
        }
        i++;
    }

    return edgeCount;
}

int main() {
    int n, edgeN;
    cin >> n >> edgeN;

    for(int i=0;i<edgeN;i++) {
        int a, b, w;
        cin >> a >> b>> w;
        arr[i] = (Edge) {a,b,w};
    }

    cout << "-------" << endl;
    int result = kruskal(n,edgeN);
    for(int i=0;i<result;i++) {
        cout << F[i].a << " " << F[i].b << " " << F[i].w << endl;
    }
    return 0;
}