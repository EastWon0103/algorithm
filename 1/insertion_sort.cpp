#include <iostream>
using namespace std;

#define MAX_SIZE 1000
void insertionSort(int a[], int n);

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

        insertionSort(a, num);
    }
    return 0;
}
void printArray(int a[], int n){
    for (int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void insertionSort(int a[], int n){
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0; // swap 함수 실행 횟수
    
    for(int i=1;i<n;i++){
        int temp = a[i];
        int insertPosition = i;
        for(int j=i;j>0;j--){
            countCmpOps++;
            if(a[j-1]>temp){
                countSwaps++;
                a[j] = a[j-1];
                insertPosition = j-1;
            } else {
                break;
            }
        }
        a[insertPosition] = temp;
    }
    cout << countCmpOps << " " << countSwaps << " ";
}