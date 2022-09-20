#include <iostream>
using namespace std;

void swap(int* a, int* b);
int strlen(char arr[]);
int getW(char str[], int size);
void permutation(char str[], int begin, int end);
static int result;

int main(){
    int numTestCase;
    cin >> numTestCase;

    for(int i=0;i<numTestCase;i++){
        
        char arr[10];
        cin >> arr;

        int end = strlen(arr);
        permutation(arr, 0, end);
        cout << result << endl;
        result = 0;
    }

    return 0;
}

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int strlen(char arr[]){
    int len = 0;
    for(int i=0;i<101;i++){
        if(arr[i] == '\0'){
            break;
        }
        len++;
    }

    return len;
}

int getW(char str[], int size){
    int a = 97;
    int sum = 0;
    for(int i=0;i<size;i++){
        if((i+1)%2!=0){
            sum += (str[i]-a);
        } else {
            sum -= (str[i]-a);
        }
    }

    if(sum>0){
        return 1;
    } else {
        return 0;
    }
}

void permutation(char str[], int begin, int end){
    int range = end - begin;
    if (range == 1){
        // cout << str << endl;
        int w = getW(str, end);
        result += w;
    } else {
        for(int i=0;i<range;i++){
            swap(str[begin], str[begin+i]);
            //cout << str << endl;
            permutation(str, begin+1, end);
            swap(str[begin], str[begin+i]);
        }
    }
}