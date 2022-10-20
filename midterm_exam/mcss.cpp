#include <iostream>
using namespace std;

int leftSum(int *a, int low, int mid) {
    int maxSum = 0;
    int tmp = 0;
    for(int i = mid;i>=low;i--) {
        tmp += a[i];
        if(maxSum < tmp) {
            maxSum = tmp;
        }
    }

    return maxSum;
}
int rightSum(int *a, int mid, int high) {
    int maxSum = 0;
    int tmp = 0;
    for(int i = mid;i<=high;i++) {
        tmp += a[i];
        if(maxSum < tmp) {
            maxSum = tmp;
        }
    }

    return maxSum;
}

int mcss(int *a, int low, int high){
    int mid=(low+high)/2;
    if(low>=high){
        return a[low];
    }
    int temp[3] = {
        mcss(a, low, mid),
        mcss(a,mid+1, high),
        leftSum(a, low, mid)+rightSum(a,mid+1, high)
    };

    int max = 0;
    for(int i=0;i<3;i++) {
        if(max < temp[i]){
            max = temp[i];
        }
    }

    return max;
}

int main () {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        int n;
        cin >> n;
        int *a = new int[n];
        for(int j=0;j<n;j++){
            cin >> a[j];
        }
        cout << mcss(a, 0,n-1)<<endl;
        
        delete[] a;
    }
    return 0;
}