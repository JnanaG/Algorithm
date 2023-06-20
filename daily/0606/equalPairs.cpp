#include<bits/stdc++.h>
using namespace std;


int equalPairs(vector<vector<int>>& grid) {
    int n=grid.size();
    int res=0;
    map<vector<int>, int> cnt;
    for(int i=0;i<n;i++) {
        cnt[grid[i]]++;
    }
    
    for(int i=0;i<n;i++) {
        vector<int> col;
        for(int j=0;j<n;j++) {
            col.push_back(grid[j][i]);
        }
        if(cnt.find(col)!=cnt.end()) {
            res += cnt[col];
        }
    }

    return res;
}

void PrintVV(vector<vector<int>>& grid) {
    for(int i=0;i<grid.size();i++) {
        for(int j=0;j<grid[0].size();j++) {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<vector<int>> grid;
    vector<int> row;
    unordered_set<int> s;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int x;
            cin>>x;
            row.push_back(x); 
        }
        grid.push_back(row);
        row.clear();
    }
    // PrintVV(grid);
    int res=equalPairs(grid);
    cout<<res<<endl;
    return 0;
}