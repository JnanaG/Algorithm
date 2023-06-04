#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m1 = nums[n-1]*nums[n-2]*nums[n-3];
        int m2 = nums[0]*nums[1]*nums[n-1];
        return max(m1, m2);
    }

};
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(-3);
    v.push_back(-4);

    Solution s;
    int m = s.maximumProduct(v);
    cout<<m<<endl;
    system("pause");
}