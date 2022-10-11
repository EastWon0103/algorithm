#include <iostream>
using namespace std;


int kadane(int array[], int len, int &startPoint, int &endPoint);

int main() {
    int numTestCase;
    cin >> numTestCase;

    for(int i=0;i<numTestCase;i++) {
        int length;
        cin >> length;

        int array[length];
        for(int j=0;j<length;j++) {
            int data;
            cin >> data;
            array[j] = data;
        }
        int start, end;
        int result = kadane(array, length, start, end);
        cout << result << " " << start << " " << end <<  endl;
    }
    return 0;
}

int kadane(int array[], int len, int &startPoint, int &endPoint) {
    int maxSum = 0;
    int thisSum = 0;

    int start=-1;
    int end=-1;
    bool isCountStart = false;
    int minStart = -1;

    for(int i=0;i<len;i++) {
        if (array[i] == 0){
            continue;
        }
        if (!isCountStart) {
            start = i;
            isCountStart = !isCountStart;
        }
        thisSum += array[i];
        if(thisSum < 0) {
            thisSum = 0;
            start = -1;
            isCountStart = !isCountStart;
        } else if (thisSum>maxSum){
            maxSum = thisSum;
            end = i;
            minStart = start;
        }
    }

    startPoint = minStart;
    endPoint = end;
    
    return maxSum;
}