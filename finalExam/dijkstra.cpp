#include <iostream>
using namespace std;
#define MAX_SIZE 1001
#define INF 100000
int W[MAX_SIZE][MAX_SIZE];

struct Edge {
    int s;
    int e;
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

void dijkstra(int n, int edgeN, Edge *edges) {
    int *touch = new int[n+1];
    int *length = new int[n+1];
    for(int i=1;i<=n;i++) {
        touch[i] = 1;
        length[i] = W[1][i];
    }

    int index = 0;
    while(index < n-1) {
        int min = INF;
        int vertex;
        // printArr(n, touch);
        // printArr(n, length);
        for(int i=2;i<=n;i++) {
            if(0 <= length[i] && length[i] <min) {
                min = length[i];
                vertex = i;
            }
        }

        edges[index] = (Edge){touch[vertex], vertex , min};
        index++;

        for(int i=2;i<=n;i++) {
            // cout << length[vertex]+W[vertex][i] << ":" << length[i] << " ";
            if((length[vertex]+W[vertex][i]) < length[i]) {
                length[i] = length[vertex] + W[vertex][i];
                touch[i] = vertex;
                // cout << "t" << endl;
            }
        //     } else {
        //         cout << "f" << endl;
        //     }
        }

        length[vertex] = -1;
    }

    delete[] touch;
    delete[] length;
}



int main () {
    int n, edgeN;
    cin >> n >> edgeN;

    initW(n);
    for(int i=0;i<edgeN;i++) {
        int start, end, w;
        cin >> start >> end >> w;
        W[start][end] = w;
    }

    // for(int i=0;i<=n;i++) {
    //     for(int j=0;j<=n;j++) {
    //         cout << W[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    Edge *edges = new Edge[edgeN];
    dijkstra(n,edgeN,edges);
    for(int i=0;i<n-1;i++) {
        cout << "{" << edges[i].s << "," << edges[i].e << "," << edges[i].w << "}" << endl;
    }

    delete[] edges;
    
    return 0;
}