#include<iostream>
#include<vector>
using namespace std;

template<class T>

void PrintVV(vector<vector<T>>& vv) {
    for(int i=0;i<vv.size();i++) {
        for(int j=0;j<vv[0].size();j++) {
            cout<<vv[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
// class Solution {
// public:

//     int d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};


//     void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y) {
//         if(board[x][y]=='X'||visited[x][y]) {
//             return;
//         }
//         visited[x][y]=true;
//         for(int i=0;i<4;i++) {
//             int nx=x+d[i][0];
//             int ny=y+d[i][1];
//             if(!inArea(board, nx, ny)) continue;
//             dfs(board, visited, nx, ny);
//         }
//     }
//     bool inArea(vector<vector<char>>& board, int x, int y) {
//         if(x<0||x>(board.size()-1)){
//             return false;
//         }else if(y<0||y>(board[0].size()-1)) {
//             return false;
//         }
//         return true;
//     }
//     void solve(vector<vector<char>>& board) {
//         int m=board.size(), n=board[0].size();
//         vector<vector<bool>> visited(m, vector<bool>(n, false));
//         for(int i=0;i<m;i++) {
//             for(int j=0;j<n;j++) {
//                 dfs(board, visited, i, j);
//             }
//         }
//         PrintVV(visited);
//     }
// };

class Solution {
public:
    int n, m;

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        if (n == 0) {
            return;
        }
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for (int i = 1; i < m - 1; i++) {
            dfs(board, 0, i);
            dfs(board, n - 1, i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {
    int m, n;
    cin>>m>>n;
    vector<vector<char>> board(m, vector<char>(n));
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin>>board[i][j];
        }
    }
    Solution sn;
    sn.solve(board);
    PrintVV(board);
    system("pause");
    return 0;
}