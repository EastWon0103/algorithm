#include <iostream>
#include <string>
using namespace std;

// string reverse_string(string reverse_copy, int size, int pos);

int strlen(char arr[]);
void reverse(char arr[], int size, int gap);

int main(){
    int numTestCase;

    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++){
        char arr[101];
        
        cin >> arr;

        reverse(arr, 0, strlen(arr)-1);
        cout << arr << endl;
    }

    return 0;
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

void swap(char* a, char* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(char arr[], int start, int end){
    if(start < end) {
        swap(arr[start], arr[end]);
        reverse(arr, start+1, end-1);
    }
}
