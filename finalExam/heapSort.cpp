#include <iostream>
using namespace std;
#define MAX_SIZE 1001

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void fixheap(int arr[], int root, int n) {
    // 루트아이템
    int rootItem = arr[root];

    //루트*2 = 레프트 차일드가 있는지 없는지 검사
    while(root*2<=n) {
        int lc = root*2;
        int rc = root*2+1;
        int large = lc;
        if(rc<=n && arr[lc] < arr[rc]) {
            large = rc;
        }

        if(arr[large] > arr[root]) {
            swap(arr[large], arr[root]);
            root = large;
        } else {
            break;
        }
    }
}



void heapsort(int arr[], int n) {
    //construct h-1단계의 노드부터 할것
    for(int i=n/2;i>=1;i--) {
        fixheap(arr,i,n);
    }

    for(int i=n;i>1;i--) {
        swap(arr[1], arr[i]);
        fixheap(arr,1,i-1);
    }
}

int main() {
    int numTestCase;
    cin>>numTestCase;
    for(int i=0;i<numTestCase;i++) {
        int n;
        cin >> n;

        int arr[MAX_SIZE];
        for(int j=1;j<=n;j++) {
            cin >> arr[j];
        }
        heapsort(arr, n);
        // for(int i=1;i<=n;i++) {
        //     cout << arr[i] << " ";
        // }
        cout << endl;
    }
    return 0;
}