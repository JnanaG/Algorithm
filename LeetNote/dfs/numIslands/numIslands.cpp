#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int d[4][2] = {0, -1, 0, 1, -1, 0, 1, 0};
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y) {
        if(visited[x][y]||grid[x][y]=='0') {
            return;
        }
        visited[x][y]=true;
        for(int i=0;i<4;i++) {
            int nextx = x+d[i][0];
            int nexty = y+d[i][1];
            if(nextx<0||nextx>=grid.size()||nexty<0||nexty>=grid[0].size())  continue;
            dfs(grid, visited, nextx, nexty);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        vector<bool> tmp(grid[0].size(), false);
        vector<vector<bool>> visited(grid.size(), tmp);
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[i].size();j++) {
                if(!visited[i][j]&&grid[i][j]=='1') {
                    dfs(grid, visited, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};

int main() {
    int n;
    cin>>n;
    while(n--) {
        int m, n;
        cin>>m>>n;
        vector<vector<char>> grid(m, vector<char>(n));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                cin>>grid[i][j];
            }
        }
        Solution sn;
        int ans = sn.numIslands(grid);
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}