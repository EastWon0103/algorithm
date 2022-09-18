#include <iostream>
#include <cmath>
using namespace std;

#define MAX_SIZE 1000
void shellSort(int a[], int n);

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int numTestCases;
    cin >> numTestCases;

    for(int i=0;i<numTestCases;++i){
        int num;
        int a[MAX_SIZE];
        cin >> num;

        for(int j=0;j<num;j++){
            cin >> a[j];
        }

        shellSort(a, num);
        cout << endl;
    }
    return 0;
}
void printArray(int a[], int n){
    for (int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void shellSort(int a[], int n){
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0; // swap 함수 실행 횟수
    int shrinkRatio = 2;
    int gap = floor(n / shrinkRatio);
    int j;
    while(gap>0){
        for(int i=gap;i<n;i++){
            int temp = a[i];
            for(j=i; j>=gap; j-=gap){
                countCmpOps++;
                if(a[j-gap] > temp){
                    countSwaps++;
                    a[j] = a[j-gap];
                } else {
                    break;
                }
            }
            a[j] = temp;
        }
        gap = floor(gap/shrinkRatio);
    }
    cout << countCmpOps << " " << countSwaps << " ";
}