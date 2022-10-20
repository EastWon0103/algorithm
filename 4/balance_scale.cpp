#include <iostream>
using namespace std;

void balance(int differ, int &tryNum);

int main() {
    int numTestCase;
    cin >> numTestCase;

    for(int i=0;i<numTestCase;i++) {
        int len;
        cin >> len;
        
        int leftSum = 0;
        int rightSum = 0;
        for(int j=0;j<len;j++) {
            int num;
            cin >> num;
            if(leftSum <= rightSum) {
                leftSum += num;
            } else {
                rightSum += num;
            }
        }

        if(leftSum == rightSum) {
            cout << 0 << endl;
        } else {
            int differ = leftSum-rightSum;
            if(differ <0) {
                differ = -differ;
            }
            // cout << "differ: " << differ << endl;
            int tryNum = 0;
            balance(differ, tryNum);
            cout << tryNum << endl;
        }

    }

    return 0;
}

void balance(int differ, int &tryNum) {
    int w[7] = {1, 2, 5, 10, 20, 50, 100};
    for(int i=6;i>=0;i--) {
        if(differ/w[i] > 0) {
            tryNum += differ/w[i];
            differ = differ%w[i];
        }
    }
}

// 3 1 4 1 5 9 2 
// 2 4 6 4
// 2 5 3 1 2

// 20문제
// 메타버스 상식 문제 수준?
// 