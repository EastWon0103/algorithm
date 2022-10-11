#include <iostream>
using namespace std;
#define MAX_SIZE 100

void merge(int a[], int low, int mid, int high);
void mergeSort(int v[], int low, int high);

int evalCount;

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++){
        int length;
        cin >> length;
        int array[length];
        for(int j=0;j<length;j++) {
            cin >> array[j];
        }

        evalCount = 0;
        mergeSort(array, 0, length-1);
        cout << evalCount << endl;
    }

    return 0;
}

void merge(int a[], int low, int mid, int high){
    int temp[MAX_SIZE]; // TEMP ARRAY

    // 템프 어레이에 배열 복사
    for(int i=low; i<=high;i++){
        temp[i] = a[i];
    }
    int i,j,k;
    i = k = low;
    j = mid+1;
    

    // 두 개의 배열(한 개의 배열이지만 mid를 기준으로 positon을 다르게 둠)
    // 이를 통해 비교하면서 삽입
    while(i<=mid && j<=high) {
        evalCount++;
        //핵심연산자
        if(temp[i]<=temp[j]){
            a[k++] = temp[i++];
        } else {
            a[k++] = temp[j++];
        }
    }


    // sorting하지 못한 아이템들을 정렬
    while(i<=mid) {
        a[k++] = temp[i++];
    }
    while(j<=high) {
        a[k++] = temp[j++];
    }
}

void mergeSort(int v[], int low, int high) {
    int mid;
    if(low == high) {
        return; // basecase
    }

    mid = (low+high) / 2;
    mergeSort(v,low,mid);
    mergeSort(v,mid+1, high);
    merge(v,low,mid,high);
}