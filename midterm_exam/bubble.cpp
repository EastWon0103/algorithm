#include <iostream>
using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble1(int *a, int n) {
    int cmp = 0;
    int swp = 0;

    for(int i=0;i<n;i++) {
        for(int j=1;j<n-i;j++) {
            cmp++;
            if(a[j-1] > a[j]) {
                swp++;
                swap(a[j], a[j-1]);
            }
        }
    }

    for(int i=0;i<n;i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << cmp << " " << swp << endl;

}

void bubble2(int *a, int n) {
    int cmp=0;
    int swp=0;
    bool swapped = false;
    for(int i=0;i<n;i++) {
        for(int j=1;j<n;j++) {
            cmp++;
            if(a[j-1] > a[j]) {
                swp++;
                swapped = true;
                swap(a[j], a[j-1]);
            }
        }
        if(swapped==false){
            break;
        }
        swapped=false;   
    }
    
    for(int i=0;i<n;i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << cmp << " " << swp << endl;
}

void bubble3(int *a, int n) {
    int cmp=0;
    int swp=0;
    int lastSwapPos = n;
    while(lastSwapPos > 0) {
        int swapedPos = 0;
        for(int j=1;j<lastSwapPos;j++) {
            cmp++;
            if(a[j-1] > a[j]) {
                swp++;
                swap(a[j], a[j-1]);
                swapedPos = j;
            }
        }
        lastSwapPos = swapedPos;
    }
    
    for(int i=0;i<n;i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << cmp << " " << swp << endl;
}

int main() {
    int len;
    cin >> len;
    int *a = new int[len];
    for(int i=0;i<len;i++) {
        cin >> a[i];
    }

    bubble3(a, len);

    delete[] a;
    return 0;
}