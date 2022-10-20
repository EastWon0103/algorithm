#include <iostream>
using namespace std;

#define UNMARK 0
#define NOTMAP -1
struct point {
    int x;
    int y;
};
point directions[8] = {
    {-2,-1}, {-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1},{1,-2}, {-1,-2}
};
int board[10][10];

void initBoard(int x, int y, point p) {
    for(int i=0;i<=y+1;i++) {
        for(int j=0;j<=x+1;j++) {
            if(i==0 || j==0 || j==x+1 || i==y+1){
                board[i][j] = NOTMAP;
            } 
            // else if(i==p.y && j==p.x) {
            //     board[i][j] = 1;
            // }
            else {
                board[i][j] = UNMARK;
            }
        }
    }
}

void printBoard(int x, int y) {
    for(int i=1;i<=y;i++) {
        for(int j=1;j<=x;j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int kinghtsTour(point pos, int n, int maxX, int maxY) {
    // if(board[pos.y][pos.x]!=UNMARK) {
    //     return -1;
    // }
    if(maxX*maxY == n){
        board[pos.y][pos.x] = n;
        return 1;
    }

    board[pos.y][pos.x] = n;
    int result = -1;
    // int temp;
    for(int i=0;i<8;i++){
        point next = {pos.x+directions[i].x, pos.y+directions[i].y};
        if(next.x>=1 && next.x<=maxX && next.y>=1 && 
        next.y <=maxY && board[next.y][next.x] == UNMARK) {
            int tmp = kinghtsTour(next, n+1, maxX, maxY);
            if(tmp == 1) {
                result = tmp;
            }
        }
    }
    if(result==-1){
        board[pos.y][pos.x] = UNMARK;
    }
    return result;
}

int main() {
    int numTestCase;
    cin >> numTestCase;
    for(int i=0;i<numTestCase;i++) {
        // m=y, n=x, s= y, t=x
        int m,n,s,t;
        cin >> m >> n >> s >> t;
        point first = {t,s};
        initBoard(n,m, first);
        int result = kinghtsTour(first, 1,n,m);
        cout << result << endl;
        if(result == 1){
            printBoard(n,m);
        }
        
    }
    return 0;
}