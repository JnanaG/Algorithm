#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void dfs(vector<vector<int>>& graph, int x) {
        // graph为从0开始的数组成的邻接矩阵
        if(x==graph.size()-1) {
            result.emplace_back(path);
            return;
        }
        for(int i=0;i<graph[x].size();i++) {
            path.push_back(graph[x][i]);
            dfs(graph, graph[x][i]);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.emplace_back(0);
        dfs(graph, 0);
        return result;
    }
};

void PrintVV(vector<vector<int>>& vv) {
    for(auto& it:vv) {
        for(auto& i:it) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    int n;
    cin>>n;  
    Solution sn;
    while ((n--))
    {
        int m;
        cin>>m;
        vector<vector<int>> graph(m);
        for(int i=0;i<m;i++) {
            int k;
            cin>>k;
            graph[i].resize(k);
            for(int j=0;j<k;j++) {
                cin>>graph[i][j];
            }
        }
        PrintVV(graph);
        vector<vector<int>> res=sn.allPathsSourceTarget(graph);
        PrintVV(res);
    }
    system("pause");
    return 0;
}