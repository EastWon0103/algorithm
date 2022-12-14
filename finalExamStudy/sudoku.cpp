#include <iostream>
using namespace std;
#define MAX 4

int board[MAX][MAX];

struct Point {
    int x;
    int y;
};

Point emptySet[MAX*MAX];

bool isPromise(Point e) {
    for(int i=0;i<MAX;i++) {
        if(i!=e.y && board[i][e.x] == board[e.y][e.x]) {
            return false;
        }
    }

    for(int i=0;i<MAX;i++) {
        if(i!=e.x && board[e.y][i] == board[e.y][e.x]) {
            return false;
        }
    }

    int startY = e.y/2*2;
    int startX = e.x/2*2;

    for(int i=startY;i<startY+2;i++) {
        for(int j=startX;j<startX+2;j++) {
            if(e.x != j && e.y != i && board[i][j] == board[e.y][e.x]) {
                return false;
            }
        }
    }

    return true;
}

bool sudoku(int index, int size) {
    if(index == size) {
        return true;
    }

    Point e = emptySet[index];
    for(int i=1;i<=MAX;i++) {
        board[e.y][e.x] = i;
        if(isPromise(e) && sudoku(index+1, size)) {
            return true;
        }
    }
    return false;
}

int main() {
    int sum = 0;
    for(int i=0;i<MAX;i++) {
        for(int j=0;j<MAX;j++) {
            int input;
            cin >> input;
            if(input == 0) {
                emptySet[sum++] = (Point) {j,i};
            }
            board[i][j] = input;
        }
    }

    bool result = sudoku(0,sum);
    if(result == false) {
        return 0;
    }

    cout << "----" << endl;
    for(int i=0;i<MAX;i++) {
        for(int j=0;j<MAX;j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}