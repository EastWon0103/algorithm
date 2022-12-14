#include <iostream>
using namespace std;
#define SIZE 4

struct Point {
    int x;
    int y;
};

int **makeBoard() {
    int **B = new int *[SIZE];
    for(int i=0;i<SIZE;i++) {
        B[i] = new int[SIZE];
    }

    return B;
}

void printBoard(int **B) {
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++) {
            cout << B[i][j] << " ";
        }
        cout << "\n";
    }
}

void deleteBoard(int **B) {
    for(int i=0;i<SIZE;i++) {
        delete[] B[i];
    }
    delete[] B;
}

bool isPossible(int **b, Point p, int num){
    for(int row=0;row<SIZE;row++) {
        if(num == b[row][p.x]) {
            return false;
        }
    }

    for(int col=0;col<SIZE;col++) {
        if(num==b[p.y][col]) {
            return false;
        }
    }

    int row = p.y/2*2;
    int col = p.x/2*2;
    for(int i=row;i<row+2;i++) {
        for(int j=col;j<col+2;j++) {
            if(b[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool sudoku(int **b, Point empty[], int n) {
    if(n==-1) {
        return true;
    }

    Point p = empty[n];

    bool result = false;
    for(int num=1;num<=SIZE;num++) {
        if(isPossible(b,p,num)){
            b[p.y][p.x] = num;
            result = sudoku(b,empty,n-1);
            if(result) {
                break;
            }
        } 
    }

    return result;
}


int main() {
    int numTestCase;
    cin >> numTestCase;
    int **board = makeBoard();
    for(int i=0;i<numTestCase;i++) {
        Point empty[SIZE*SIZE];
        int count=0;
        for(int j=0;j<SIZE;j++) {
            for(int k=0;k<SIZE;k++) {
                cin >> board[j][k];
                if(board[j][k]==0) {
                    empty[count++] = (Point) {k,j};
                }
            }
        }

        if(sudoku(board,empty,count-1)) {
            printBoard(board);
        } else {
            cout << "no" << endl;
        }
    }

    deleteBoard(board);
    return 0;
}