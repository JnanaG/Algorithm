#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int fib(int n) {
        if(n<=1) {
            return n;
        }
        // // 确定dp数组以及下标的含义
        // // dp[i]的定义为：第i个数的斐波那契数值是dp[i]
        // vector<int> dp(n+1);

        // // 确定递推公式
        // //  dp[i] = dp[i - 1] + dp[i - 2]

        // // dp数组初始化
        // dp[0]=0;
        // dp[1]=1;

        // // 确定遍历顺序
        // for(int i=2;i<=n;i++) {
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];

        // // 例推导dp数组

        int dp[2];
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++) {
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
};


int main() {
    int n;
    cin>>n;
    Solution sn;
    int fib_ans = sn.fib(n);
    cout<<fib_ans<<endl;
    system("pause");
    return 0;
}