#include <iostream>
using namespace std;
#define MAX_SIZE 4
int board[MAX_SIZE][MAX_SIZE];

struct Point {
    int row;
    int col;
};

void print() {
    for(int i=0;i<MAX_SIZE;i++) {
        for(int j=0;j<MAX_SIZE;j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isPromise(Point p) {
    bool result = true;
    int item = board[p.row][p.col];

    for(int j=0;j<MAX_SIZE;j++) {
        if(j != p.col && item == board[p.row][j]) {
            return false;
        }
    }

    for(int i=0;i<MAX_SIZE;i++) {
        if(i != p.row && item == board[i][p.col]) {
            return false;
        }
    }

    int row = p.row/2*2;
    int col = p.col/2*2;
    for(int i=row;i<row+2;i++) {
        for(int j=col;j<col+2;j++) {
            if((!(p.row==i && p.col==j)) && item == board[i][j]) {
                return false;
            }
        }
    }

    return result;
}


bool sudoku(Point *empty, int n, int len) {
    if(n==len) {
        return true;
    }

    Point point = empty[n];
    bool result = false;
    for(int i=1;i<=MAX_SIZE;i++) {
        board[point.row][point.col] = i;
        if(isPromise(point) && sudoku(empty,n+1,len)) {
            return true;
        }    
    }

    board[point.row][point.col] = 0;
    return false;
}

int main () {
    int numTestCase;
    cin >> numTestCase;

    for(int i=0;i<numTestCase;i++) {
        Point *empty = new Point[MAX_SIZE * MAX_SIZE];
        int index = 0;

        for(int j=0;j<MAX_SIZE;j++) {
            for(int k=0;k<MAX_SIZE;k++) {
                int input;
                cin >> input;
                if(input == 0) {
                    empty[index++] = (Point) {j,k};
                }
                board[j][k] = input;
            }
        }

        if(sudoku(empty, 0, index)) {
            print();
        } else {
            cout <<"no" << endl;
            print();
        }

        delete[] empty;
    }

    return 0;
}