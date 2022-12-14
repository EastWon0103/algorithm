#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 100

struct Edge {
    int a;
    int b;
    int w;
};

Edge ARR[MAX_SIZE];
int UFS[MAX_SIZE];

void constructUFS(int n) {
    for(int i=0;i<n;i++) {
        UFS[i] = i;
    }
}

int find(int x) {
    int parent;
    int root = x;

    while(UFS[root]!=root) {
        root = UFS[root];
    }

    while(UFS[x] != root) {
        parent = UFS[x];
        UFS[x] = root;
        x = parent;
    }

    return root;
}

void unionSet(int p, int q) {
    int i = find(p);
    int j = find(q);
    if(i!=j) {
        UFS[i] = j;
    }
}

bool is_same_set(int p, int q) {
    return find(p) == find(q);
}

bool compareMin(Edge m, Edge n) {
    return m.w < n.w;
}

int totalWeight(int n, int edgeN, Edge F[]) {
    constructUFS(n);
    stable_sort(ARR, ARR+edgeN, compareMin);
    
    int index = 0;
    int vCount = 0;
    int weight = 0;
    while(vCount < n && index<edgeN) {
        Edge edge = ARR[index];
        if(!is_same_set(edge.a, edge.b)) {
            unionSet(edge.a, edge.b);
            F[vCount] = edge;
            weight += edge.w;
            vCount++;
        }

        index++;
    }
    
    return weight;
}

int main() {
    int n, edgeN;
    cin >> n >> edgeN;
    for(int i=0;i<edgeN;i++) {
        int a, b, w;
        cin >> a >> b >> w;
        ARR[i] = (Edge) {a-1,b-1,w};
    }
    Edge F[MAX_SIZE];
    int result = totalWeight(n, edgeN, F);

    cout << result << endl;
    for(int i=0;i<n-1;i++) {
        cout << "{" << F[i].a+1 << "," << F[i].b+1  <<"," << F[i].w << "}" << endl;
    }
}