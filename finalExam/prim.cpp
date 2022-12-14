#include <iostream>
using namespace std;
#define MAX_SIZE 100
#define INF 10000000
int W[MAX_SIZE][MAX_SIZE];

struct Edge {
    int a;
    int b;
    int w;
};

void initW(int n) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i==j) {
                W[i][j] = 0;
            } else {
                W[i][j] = INF;
            }
        }
    }
}

void printArr(int n, int *arr) {
    for(int i=1;i<=n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void prim(int n, int edgeN, Edge *edges) {
    int *nearest = new int[n+1];
    int *distance = new int[n+1];
    int index = 0;


    // 초기화
    for(int i=2;i<=n;i++) {
        nearest[i] = 1;
        distance[i] = W[1][i];
    }

    while(index < n-1) {
        int min = INF;
        int vnear;
        // printArr(n,nearest);
        // printArr(n,distance);
        for(int i=2;i<=n;i++) {
            if(0<=distance[i] && distance[i]<min) {
                min = distance[i];
                vnear = i;
            }
        }

        Edge edge = (Edge) {nearest[vnear], vnear, min};
        edges[index] = edge;
        index++;

        distance[vnear] = -1;
        for(int i=2;i<=n;i++) {
            if(W[i][vnear] < distance[i]) {
                distance[i] = W[i][vnear];
                nearest[i] = vnear;
            }
        }
    }
    

    delete[] nearest;
    delete[] distance;
}

int main() {
    int n, edgeN;
    cin >> n >> edgeN;
    
    initW(n);
    Edge *edges = new Edge[n-1];
    for(int i=0;i<edgeN;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        W[a][b] = w;
        W[b][a] = w;
    }

    prim(n,edgeN, edges);
    for(int i=0;i<n-1;i++) {
        cout << "{" << edges[i].a << "," << edges[i].b << "," << edges[i].w << "}" << endl;
    }

    delete[] edges;
    return 0;
}