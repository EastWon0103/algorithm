#include <iostream>
using namespace std;

#define MARK 1 // 마킹
#define UNMARK 0 // 논마킹
#define NOTMAP 2 // 맵이 아님

typedef struct Point {int x, y;} point;
point direction[8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2},
{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

int **makeBoard(int x,int y);
void initBoard(int **board, int x,int y, int s, int t);
void destroyBoard(int **board, int y);
int knightsTour(int **board, int x, int y, Point pos, int count);

void printBoard(int **board, int m, int n, bool zero) {
    if(zero == true){
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    
}

int main() {
    int numTestCase;
    cin >> numTestCase;
    
    for(int i=0;i<numTestCase;i++){
        // x은 행, y 열
        // s는 행 위치, t 열 위치
        int m, n, s, t;
        cin >> m >> n;
        cin >> s >> t;

        int **board = makeBoard(n,m);
        initBoard(board, n, m, s, t);
        Point first = {t,s};
        int result = knightsTour(board, n, m, first, 1);
        cout << result << endl;
        if(result) {
            printBoard(board, m, n, false);
        }
    
        destroyBoard(board, m);
    }

    return 0;
}

int **makeBoard(int x,int y){
    int **board = new int *[y+1];
    for (int i=0;i<y+1;i++){
        board[i] = new int[x+1];
    }

    return board;
}

void destroyBoard(int **board, int y) {
    for(int i=0;i<y+1;i++){
        delete[] board[i];
    }
    delete[] board;
}

void initBoard(int **board, int x,int y, int s, int t){
    for(int i=0;i<y+1;i++){
        for(int j=0;j<x+1;j++){
            if(i == 0 || j == 0) {
                board[i][j] = NOTMAP;
            } else {
                if (i==s && j==t){
                    board[i][j] = MARK;
                } else {
                    board[i][j] = UNMARK;
                }
            }
        }
    }
}

int knightsTour(int **board, int x, int y, Point pos, int count){
    Point next;
    if(x*y == count) {
        return 1;
    }

    for(int i=0;i<8;i++){
        next.x = pos.x + direction[i].x;
        next.y = pos.y + direction[i].y;
        if((next.x > 0 && next.x <= x) && (next.y > 0 && next.y <= y) && board[next.y][next.x] == UNMARK) {
            board[next.y][next.x] = count+1;
            if(knightsTour(board, x, y, next, count+1)){
                return 1;
            }

            board[next.y][next.x] = 0;
        }
        
    }

    return 0;
}