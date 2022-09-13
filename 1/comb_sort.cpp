#include <iostream>
#include <cmath>
using namespace std;

#define MAX_SIZE 1000
void combSort(int a[], int n);

int main()
{
    int numTestCases;
    // int a[MAX_SIZE], b[MAX_SIZE];
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; ++i) {
        int num;
        int a[MAX_SIZE];
        cin >> num;

        for (int j = 0; j < num; j++){
            cin >> a[j];
        }
        combSort(a, num);
    }

    return 0;
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* CombSort 함수 */
void combSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0; // swap 함수 실행 횟수
    int gap = n;
    double shrink = 1.3;
    bool sorted = false;
    // Comb Sort 알고리즘 구현
    while(!sorted){
        gap = floor(gap / shrink);
        cout << "gap: " << gap << endl;
        if (gap <= 1){
            gap = 1;
            sorted = true;
        }
        for(int i=0;i+gap<n;i++){
            countCmpOps++;
            if(a[i] > a[gap+i]){
                sorted = false;
                countSwaps++;
                swap(a[i], a[gap+i]);
            }
        }
    }

    cout << countCmpOps << " " << countSwaps << " ";
}
