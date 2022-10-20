#include <iostream>
using namespace std;

#define NUM_ROCK 7
int rock[NUM_ROCK] = {1,2,5,10,20,50,100};

void initArray(int *a, int n) {
    for(int i=0;i<n;i++) {
        a[i] = -1;
    }
}

int balance(int *rockUsed,int differ) {
    if(differ <= 0) {
        rockUsed[0] = 0;
        return 0;
    }
    if(rockUsed[differ] != -1) {
        return rockUsed[differ];
    }

    int i;
    int min = differ;
    int minPos;
    // cout << differ << endl;
    for(i=NUM_ROCK-1;i>=0;i--) {
        if(differ-rock[i] < 0) {
            continue;
        }
        int temp = balance(rockUsed, differ-rock[i]);
        if(min > temp) {
            min = temp;
            minPos = i;
        }
    }
    rockUsed[differ] = min+1;
    return min+1;
}

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        int n;
        cin >> n;
        
        int input;

        int leftSum=0;
        int rightSum=0;
        for(int j=0;j<n;j++) {
            cin >> input;
            if(leftSum<=rightSum) {
                leftSum += input;
            } else {
                rightSum += input;
            }
        }

        if(leftSum-rightSum == 0) {
            cout << 0 << endl;
        } else {
            int differ = leftSum-rightSum;
            if(differ < 0) {
                differ = -differ;
            }

            int *arr = new int[differ+1];
            initArray(arr, differ+1);
            // cout << differ << " " << arr[differ] << endl;
            cout << balance(arr, differ) << endl;
            delete[] arr;
        }

    }
    return 0;
}