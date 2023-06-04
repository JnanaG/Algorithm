#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // vector<int> dp(cost.size()+1);
        // for(int i=2;i<=cost.size();i++) {
        //     dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        // }
        // return dp[cost.size()];
        int dp[2];
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=cost.size();i++) {
            int res = min(dp[1]+cost[i-1], dp[0]+cost[i-2]);
            dp[0] = dp[1];
            dp[1] = res;
        }
        return dp[1];
    }
};

int main() {
    int n;
    cin>>n;
    while(n--) {
        int m;
        cin>>m;
        vector<int> cost(m);
        for(int& x:cost) {
            cin>>x;
        }
        Solution sn;
        int ans = sn.minCostClimbingStairs(cost);
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}