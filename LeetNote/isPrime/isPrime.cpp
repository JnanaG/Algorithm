#include<iostream>
#include<vector>
using namespace std;

// 暴力解
class Solution1 {
public:
    int countPrimes(int n) {
        int ans=0;
        for(int i=2;i<n;i++) {
            ans += isPrime(i);
        }
        return ans;
    }

    bool isPrime(int x) {
        for(int i=2;i*i<x;i++) {
            if(x%i==0){
                return false;
            }
        }
        return true;
    }
};

//埃氏筛选
class Solution2 {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<int> isPrimes(n, 1);
        for(int i=2;i<n;i++) {
            if(isPrimes[i]){
                count++;
                // 埃氏筛选，将当前遍历元素往后的相关非质数元素滤除
                for(int j=2*i;j<n;j+=i) {
                    isPrimes[j] = 0;
                }
            }
        }
        return count;
    }

};

int main()
{
    int x = 23;
    Solution2 s;
    int n = s.countPrimes(x);
    cout<<"小于"<<x<<"的质数个数为："<<n<<endl;

    system("pause");
}