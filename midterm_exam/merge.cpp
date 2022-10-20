#include <iostream>
using namespace std;

#define MAX_SIZE 100
int CMP;

void merge(int a[], int low, int mid, int high) {
    int tmp[MAX_SIZE];
    for(int i=low;i<=high;i++)
        tmp[i] = a[i];
    
    int i,l,r;
    i = l = low;
    r = mid+1;

    while(l<=mid && r<=high) {
        CMP++;
        if(tmp[l] > tmp[r]) {
            a[i++] = tmp[r++];
        } else {
            a[i++] = tmp[l++];
        }
    }

    while(l<=mid){a[i++]=tmp[l++];}
    while(r<=high){a[i++]=tmp[r++];}
    
}

void printArray(int a[], int n) {
    for(int i=0;i<n;i++) {
        cout << a[i] << " ";
    }

    cout << endl;
}

void mergeSort(int a[], int low, int high) {
    if(low>=high) {
        return;
    }

    int mid = (low+high)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    merge(a,low,mid,high);
}

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        int n;
        cin >> n;
        int a[MAX_SIZE];
        CMP = 0;
        for(int j=0;j<n;j++) {
            cin >> a[j];
        }

        mergeSort(a,0,n-1);
        cout << CMP << endl;
        printArray(a, n);
    }
    return 0;
}