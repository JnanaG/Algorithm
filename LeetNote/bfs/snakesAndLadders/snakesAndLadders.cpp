#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    pair<int, int> id2rc(int id, int n) {
        int r=(id-1)/n, c=(id-1)%n;
        if(r%2==1) {
            c = n-1-c;
        }
        return {n-1-r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<bool> visited(n*n+1, false);
        queue<pair<int, int>> q;
        q.emplace(1, 0); //表示初始加入第一个位置，1是id， 0代表移动次数
        visited[1]=true;
        while(!q.empty()) {
            auto p=q.front();
            q.pop();
            for(int i=0;i<6;i++) {
                int next = p.first+i;
                if(next>n*n)    break;
                auto rc=id2rc(next, n);
                if(board[rc.first][rc.second]>0) {
                    next = board[rc.first][rc.second];
                }
                if(next==n*n)   return p.second+1;
                if(!visited[next]) {
                    visited[next]=true;
                    q.emplace(next, rc.second+1);
                }
            }
        }
        return -1;
    }
};

int main() {
    system("pause");
}