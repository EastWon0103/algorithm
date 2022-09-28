#include <iostream>
using namespace std;

// int **mulMatrix2(int **matrix1, int **matrix2);
// int **fast_fibo(int **matrix, int p);
// void initMatrix(int **matrix);
// int **makeMatrix2();
// void deleteMatrix2(int **matrix);

void copyMatrix(int a[2][2], int b[2][2]);
void mulMatrix(int original[2][2], int change[2][2]);
void fast_fibo(int original_matrix[2][2], int change_matrix[2][2], int n);

int main(){
    int numTestCase;
    
    cin >> numTestCase;

    for (int i=0;i<numTestCase;i++){
        int num;
        cin >> num;

        int constMatrix[2][2] = {
            {1,1},
            {1,0}
        };
        int resultMatrix[2][2];

        fast_fibo(constMatrix, resultMatrix, num);
        cout << resultMatrix[1][0] << endl;
    }

    return 0;
}

void copyMatrix(int a[2][2], int b[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j=0; j<2; j++){
            a[i][j] = b[i][j];
        }
    }
}

void mulMatrix(int original[2][2], int change[2][2]){
    int a,b,c,d;
    a = change[0][0];
    b = change[0][1];
    c = change[1][0];
    d = change[1][1];

    change[0][0] = (original[0][0]*a + original[0][1]*c) % 1000;
    change[0][1] = (original[0][0]*b + original[0][1]*d) % 1000; 
    change[1][0] = (original[1][0]*a + original[1][1]*c) % 1000;
    change[1][1] = (original[1][0]*b + original[1][1]*d) % 1000;
}

void fast_fibo(int original_matrix[2][2], int change_matrix[2][2], int n){
    if(n==0){
        change_matrix[0][0] = 1;
        change_matrix[0][1] = 0;
        change_matrix[1][0] = 0;
        change_matrix[1][1] = 1;
    } else if(n%2!=0){
        int num;
        if (n==1){
            num = 0;
        } else {
            num = (n-1)/2;
        }
        fast_fibo(original_matrix, change_matrix, num);
        // cout << "test1: " << num << endl;
        int temp[2][2];
        copyMatrix(temp, change_matrix);
        mulMatrix(temp, change_matrix); 
        // cout << "test2: "<< num  << endl;
        mulMatrix(original_matrix, change_matrix);
    } else {
        fast_fibo(original_matrix, change_matrix, n/2);
        int temp[2][2];
        copyMatrix(temp, change_matrix); 
        mulMatrix(temp, change_matrix); 
    }
}