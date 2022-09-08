#include <iostream>
using namespace std;

#define MAX_SIZE 1000
void bubbleSort(int a[], int n);
void bubbleSortImproved1(int a[], int n);
void bubbleSortImproved2(int a[], int n);
void copyArray(int a[], int b[], int n);

int main()
{
    int numTestCases;
    int a[MAX_SIZE], b[MAX_SIZE];
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++){
            cin >> b[j];
        }
        copyArray(a, b, num);
        bubbleSort(a, num);
        
        copyArray(a, b, num);
        bubbleSortImproved1(a, num);

        copyArray(a, b, num);
        bubbleSortImproved2(a, num);

        cout << endl;
    }
 return 0;
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* BubbleSort 함수 */
void bubbleSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0; // swap 함수 실행 횟수
    // bubble sort 알고리즘 구현
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){
            countCmpOps++;
            if(a[j-1] > a[j]){
                countSwaps++;
                swap(a[j-1], a[j]);
            }
        }
    }

    cout << countCmpOps << " " << countSwaps << " ";
}

/* BubbleSort 함수 - Improved Version 1 */
void bubbleSortImproved1(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0; // swap 함수 실행 횟수
    // bubble sort의 개선된 알고리즘 (1) 구현
    for(int i=1;i<n;i++){
        bool swapped = false;
        for(int j=1;j<=n-i;j++){
            countCmpOps++;
            if(a[j-1] > a[j]){
                swapped = true;
                countSwaps++;
                swap(a[j-1], a[j]);
            }
        }
        if (swapped == false){
            break;
        }
    }

    cout << countCmpOps << " " << countSwaps << " ";
}

/* BubbleSort 함수 - Improved Version 2 */
void bubbleSortImproved2(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0; // swap 함수 실행 횟수
    // bubble sort의 개선된 알고리즘 (2) 구현
    int lastSwappedPos = n;
    while (lastSwappedPos > 0){
        int swappedPos = 0;
        for(int j=1;j<lastSwappedPos;j++){
            countCmpOps++;
            if(a[j-1] > a[j]){
                countSwaps++;
                swappedPos = j;
                swap(a[j-1], a[j]);
            }
        }
        lastSwappedPos = swappedPos;
    }

    cout << countCmpOps << " " << countSwaps << " ";

    // cout << endl;
    // for (int i=0;i<n;i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
}

void copyArray(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}