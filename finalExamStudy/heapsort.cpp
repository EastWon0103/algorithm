#include <iostream>
using namespace std;
#define MAX 100000

int arr[MAX];

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void fixheap(int root, int n) {
    while(root*2<=n) {
        int left = root*2;
        int right = root*2+1;

        int bigger = left;
        if(right <= n && arr[left] < arr[right]) {
            bigger = right;
        }

        if(arr[bigger] > arr[root]) {
            swap(arr[bigger], arr[root]);
            root = bigger;
        } else {
            break;
        }
    }
}

void heapSort(int n) {
    for(int i=n/2;i>=1;i--) {
        fixheap(i,n);
    }
    
    
    // for(int i=1;i<=n;i++) {
    //     cout << "why?" << endl;
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    for(int i=n;i>1;i--) {
        swap(arr[1], arr[i]);
        fixheap(1,i-1);
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }

    heapSort(n);

    for(int i=1;i<=n;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}