#include <iostream>
#define MAX_SIZE 100
using namespace std;

int countSum;
void merge(int *a, int low, int mid, int high);
void mergeIter(int *array, int n);
int min(int a, int b) {
    if(a>b) {
        return b;
    } else {
        return a;
    }
}

void printArray(int *a, int n) {
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }

    cout << endl;
}

int main() {
    int numTestCase;
    cin >> numTestCase;

    for(int i=0;i<numTestCase;i++) {
        int length;
        cin >> length;
        int *array = new int[length];
        countSum = 0;
        for(int j=0;j<length;j++) {
            cin >> array[j];
        }

        mergeIter(array, length);
        cout << countSum << endl;
        // printArray(array, length);

        delete[] array;
    }
    return 0;
}


void merge(int *a, int low, int mid, int high) {
    int temp[MAX_SIZE];
    int i,j,k;
    for(i=low;i<=high;i++) {
        temp[i] = a[i];
    }

    i = j = low;
    k = mid+1;
    while(i<=mid && k<=high) {
        countSum++;
        if(temp[i] <= temp[k]) {
            a[j++] = temp[i++];
        } else {
            a[j++] = temp[k++];
        } 
    }
    while(i<=mid){
        a[j++] = temp[i++];
    }

    while(k<=high) {
        a[j++] = temp[k++];
    }
}

void mergeIter(int *array, int n) {
    int size = 1;
    while (size < n) {
        for (int i=0;i<n;i+=2*size) {
            int low = i;
            int mid = low+size-1;
            int high = min(i+2*size -1, n-1);
            if(mid>=n-1) {
                break;
            }
            merge(array,low,mid,high);
        }
        size *= 2;
    }
}
