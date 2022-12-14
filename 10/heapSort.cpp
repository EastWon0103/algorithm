#include <iostream>
using namespace std;

int cmpCount;

int maxItem(int l, int r, int *arr) {
    if(r==-1) {
        return l;
    } else if (arr[l]>arr[r]) { 
        cmpCount++;
        return l;
    } else {
        cmpCount++;
        return r;
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print(int *a, int n) {
    for(int i=1;i<=n;i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void fixHeap(int *arr, int root, int n) {
    while(root*2<=n) {
        int leftNode = root*2;
        int rightNode = (root*2+1<=n)?root*2+1:-1;
        int leafMax = maxItem(leftNode, rightNode, arr);

        cmpCount++;
        if (arr[root] < arr[leafMax]) {
            swap(arr[root],arr[leafMax]);
            root = leafMax;
        } else {
            break;
        }
    }
}

void heapSort(int *arr, int n) {
    // leaf node의 루트 노드들부터 차례대로
    for(int i=n/2;i>=1;i--) {
        fixHeap(arr, i, n);
    }

    for(int i=n; i>=2; i--) {
        int max = arr[1];
        swap(arr[1], arr[i]);
        fixHeap(arr,1,i-1);
        arr[i] = max;
    }
}


int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        int n;
        cin >> n;
        int *a = new int[n+1];
        cmpCount = 0;
        for(int j=1;j<=n;j++) {
            cin >> a[j];
        }
        heapSort(a,n);
        cout << cmpCount << "\n";

        delete[] a;
    }
    return 0;
}