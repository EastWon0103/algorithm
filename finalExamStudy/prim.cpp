#include <iostream>
using namespace std;
#define MAX 1000
#define INF 1000000
struct Edge {
    int a;
    int b;
    int w;
};

Edge F[MAX];

int W[MAX][MAX];

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

int prim(int n, int edgeN) {
    int *nearest = new int[n+1];
    int *distance = new int[n+1];

    for(int i=2;i<=n;i++) {
        nearest[i] = 1;
        distance[i] = W[1][i];
    }

    int edgeCount = 0;
    while(edgeCount < n-1) {
        int min = INF;
        int vnear;
        for(int i=2;i<=n;i++) {
            if(0 <= distance[i] && min > distance[i]) {
                vnear = i;
                min = distance[i];
            }
        }

        F[edgeCount++] = (Edge) {nearest[vnear], vnear, min};
        distance[vnear] = -1;

        for(int i=2;i<=n;i++) {
            if(distance[i] > W[vnear][i] && distance[i] >= 0) {
                nearest[i] = vnear;
                distance[i] = W[vnear][i];
            }
        }
    }


    delete[] nearest;
    delete[] distance;
    return edgeCount;
}

int main() {
    int n, edgeN;
    cin >> n >> edgeN;
    initW(n);
    for(int i=0;i<edgeN;i++) {
        int a, b, w;
        cin >> a >> b >> w;
        W[a][b] = w;
        W[b][a] = w;
    }

    cout << "-------" << endl;
    int result = prim(n,edgeN);
    for(int i=0;i<result;i++) {
        cout << F[i].a << " " << F[i].b << " " << F[i].w << endl;
    }
    return 0;
}