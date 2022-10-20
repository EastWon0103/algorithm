#include <iostream>
using namespace std;

#define MAX_SIZE 100

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partitionL(int a[], int low, int high) {
    int pivot = a[low];
    int pivotPos = low;
    for(int i=low+1;i<=high;i++){
        if(pivot < a[i]) {
            swap(a[i], a[++pivotPos]);
        }
    }
}

void quickSortL(int a[], int low, int high) {
    if(low>=high) {
        return;
    }

    int pivot = partitionL(a, low, high);
    quickSortL(a, low, pivot-1);
    quickSortL(a, pivot+1, high);
}

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        int n;
        cin >> n;
        int arr[MAX_SIZE];
        for(int j=0;j<n;j++){
            cin >> arr[j];
        }

        quickSortL(arr,0,n-1);
    }
    return 0;
}