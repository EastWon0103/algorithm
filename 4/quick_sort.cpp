#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int partitionHoare(int *array, int low, int high);
void quickSortHoare(int *array, int low, int high);

int partitionLomuto(int *array, int low, int high);
void quickSortLomuto(int *array, int low, int high);
void printArray(int *array, int len);

int hoareCompare;
int hoareSwap;
int lomutoCompare;
int lomutoSwap;

// int *testCase1() {
//     int *array = new int[9]{4,7,3,9,2,5,8,1,6};
//     return array;
// }

// int *testCase2() {
//     int *array = new int[40];
//     for(int i=0;i<40;i++) {
//         array[i] = 9;
//     }

//     return array;
// }

// int *testCase3(){
//     int *array = new int[30];
//     for(int i=0;i<30;i++) {
//         array[i] = i+1;
//     }

//     return array;  
// }

// int *testCase4(){
//     int *array = new int[30];
//     for(int i=0;i<30;i++) {
//         array[i] = 30-i;
//     }

//     return array;  
// }

// int *testCase5(){
//     int *array = new int[30]{
//         19, 14, 30, 25, 13, 29, 5, 20, 2, 12, 18, 24, 9, 21, 6, 26, 16, 4, 22, 1, 28, 17, 10, 7, 23, 15, 3, 27, 11, 8 
//     };
//     return array;  
// }

// int *testCase6() {
//     int *array = new int[1000];
//     for(int i=0;i<1000;i++) {
//         array[i] = 9;
//     }
//     return array;
// }

// int *testCase7() {
//     int *array = new int[1000];
//     for(int i=0;i<1000;i++) {
//         array[i] = i+1;
//     }
//     return array;
// }

// int *testCase8() {
//     int *array = new int[1000];
//     for(int i=0;i<1000;i++) {
//         array[i] = 1000-i;
//     }
//     return array;
// }

// int *(*functionPtr[])() = {
//     testCase1,
//     testCase2,
//     testCase3,
//     testCase4,
//     testCase5,
//     testCase6,
//     testCase7,
//     testCase8
// };

int main() {
    // int length[8] = {9,40,30,30,30, 1000,1000,1000};
    // for(int i=0;i<8;i++) {
    //     int *arrayA = (*functionPtr[i])();
    //     int *arrayB = (*functionPtr[i])();

    //     hoareCompare = hoareSwap = 0;
    //     lomutoCompare = lomutoSwap = 0;
        
    //     quickSortHoare(arrayA, 0, length[i]-1);
    //     quickSortLomuto(arrayB, 0, length[i]-1);
        
    //     cout << hoareSwap << " " << lomutoSwap << " ";
    //     cout << hoareCompare << " " << lomutoCompare;

    //     cout << endl;

    //     delete[] arrayA;
    //     delete[] arrayB;
    // }


    int numTestCase = 8;
    cin >> numTestCase;

    for(int i=0;i<numTestCase;i++) {
        int length;
        cin >> length;
        int *arrayA = new int[length];
        int *arrayB = new int[length];

        hoareCompare = hoareSwap = 0;
        lomutoCompare = lomutoSwap = 0;

        for(int j=0;j<length;j++) {
            int input;
            cin >> input;
            arrayA[j] = input;
            arrayB[j] = input;
        }
    
        quickSortHoare(arrayA, 0, length-1);
        quickSortLomuto(arrayB, 0, length-1);

        cout << hoareSwap << " " << lomutoSwap << " ";
        cout << hoareCompare << " " << lomutoCompare;

        cout << endl;

        delete[] arrayA;
        delete[] arrayB;
    }

    return 0;
}

int partitionHoare(int *array, int low, int high) {
    int pivot = array[low];
    int lowPos = low-1;
    int highPos = high+1;
    while(true) {
        while(array[++lowPos] < pivot) {
            ++hoareCompare;
        }
        ++hoareCompare;

        while(array[--highPos] > pivot) {
            ++hoareCompare;
        }
        ++hoareCompare;

        if(lowPos<highPos) {
            hoareSwap++;
            swap(array[lowPos], array[highPos]);
        } else {
            return highPos;
        }
    }
}

void quickSortHoare(int *array, int low, int high) {
    if(low >= high){
        return;
    }
    
    int pivot = partitionHoare(array, low, high);
    quickSortHoare(array, low, pivot);
    quickSortHoare(array, pivot+1, high);
}

int partitionLomuto(int *array, int low, int high) {
    int pivot = array[low];
    int j=low;

    for(int i=low+1;i<=high;i++) {
        lomutoCompare++;
        if(array[i] < pivot) {
            lomutoSwap++;
            j++;
            swap(array[i], array[j]);
        }
    }
    lomutoSwap++;
    swap(array[j], array[low]);
    return j;
}

void quickSortLomuto(int *array, int low, int high) {
    if(low >= high){
        return;
    }
    
    int pivot = partitionLomuto(array, low, high);
    quickSortLomuto(array, low, pivot-1);
    quickSortLomuto(array, pivot+1, high);

}

void printArray(int *array, int len) {
    for(int i=0;i<len;i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}