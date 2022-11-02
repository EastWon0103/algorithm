#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
#define MAX_SIZE 100000


struct member {
    int age;
    string name;
};

member tmp[MAX_SIZE];

void print(member a[], int n){
    for(int i=0;i<n;i++) {
        cout << a[i].age << " " << a[i].name << "\n";
    }
}

void merge(member a[], int low, int mid, int high) {
    for(int i=low;i<=high;i++) {
        tmp[i] = a[i];
    }

    int i,j,k;
    i = j = low;
    k=mid+1;

    while(i<=mid&&k<=high) {
        if(tmp[i].age <= tmp[k].age) {
            a[j++] = tmp[i++];
        } else {
            a[j++] = tmp[k++];
        }
    }

    while(i<=mid){a[j++] = tmp[i++];}
    while(k<=high){a[j++] = tmp[k++];}
}

void mergeSort(member a[], int low, int high) {
    if(low>=high) {
        return;
    }

    int mid = (low+high)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    merge(a,low,mid, high);
}

int main() {
    int n;
    cin >> n;
    member a[MAX_SIZE];
    for(int i=0;i<n;i++) {
        int age;
        string name;
        cin >> age >> name;
        a[i] = (member) {age, name};
    }

    mergeSort(a,0,n-1);
    print(a,n);
    return 0;
}