#include <iostream>
using namespace std;

int mcss(int array[], int low, int high);
int leftSum(int array[], int low, int high);
int rightSum(int array[], int low, int high);

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        int length;
        cin >> length;
        int array[length];
        for(int j=0;j<length;j++){
            cin >> array[j];
        }

        cout << mcss(array, 0, length-1) << endl;
    }

    return 0;
}

int leftSum(int array[], int low, int mid){
    int maxSum = 0;
    int thisSum = 0;
    while(low <= mid){
        thisSum += array[mid--];
        if(thisSum>maxSum){
            maxSum = thisSum;
        }
    }
    
    return maxSum;
}
int rightSum(int array[], int mid, int high){
    int maxSum = 0;
    int thisSum = 0;

    while(mid <= high){
        thisSum += array[mid++];
        if(thisSum>maxSum){
            maxSum = thisSum;
        }
    }

    return maxSum;
}

int mcss(int array[], int low, int high){
    if(low == high) {
        return array[low];
    }

    int midPos = (low+high) / 2;
    
    int left = mcss(array,low,midPos);
    int right = mcss(array,midPos+1,high);
    int mid = leftSum(array, low, midPos) + rightSum(array, midPos+1, high);

    int maxArray[2] = {right, mid};
    int max = left;
    for(int i=0;i<2;i++){
        if(max < maxArray[i]){
            max = maxArray[i];
        }
    }

    return max;
}