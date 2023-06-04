#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution
{

public:
    int pivotindex(vector<int>& nums)
    {
        // 左右双指针
        //l从左边累加， r从右边递减， 直至l=r
        int l=0, r=0;
        // for(int i=0;i<nums.size();++i)
        // {
        //     r += nums[i];
        // }
        r = accumulate(nums.begin(), nums.end(), 0);
        for(int i=0;i<nums.size();++i)
        {
            l += nums[i];
            if(l==r)
            {
                return i;
            }
            r = r - nums[i];
        }
        return -1;
    }
};


int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(7);
    v.push_back(3);
    v.push_back(6);
    v.push_back(5);
    v.push_back(6);

    Solution s;
    int index = s.pivotindex(v);
    cout<<index<<endl;
    system("pause");
}