#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map<int, int> m;
        // for(int i=0;i<nums.size();++i)
        // {
        //     m[nums[i]] = i;
        // }
        // for(int i=0;i<nums.size();++i)
        // {
        //     int item = target - nums[i];
        //     auto pos = m.find(item);
        //     if(pos!=m.end()&&pos->second!=i)
        //     {
        //         return {i, pos->second};
        //     }
        // }
        // return {};

        map<int, int> m;
        for(int i=0;i<nums.size();++i)
        {
            int item = target - nums[i];
            auto pos = m.find(item);
            if(pos!=m.end())
            {
                return {pos->second, i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};

class Solution2
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        for(int i=0;i<nums.size();++i)
        {
            int item = target - nums[i];
            for(int j=i+1;j<nums.size();++j)
            {
                if(nums[j] == item)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

int main()
{
    Solution2 s;
    vector<int> v;
    v.push_back(2);
    v.push_back(7);
    v.push_back(11);
    v.push_back(15);

    vector<int> ans = s.twoSum(v, 9);
    cout<<ans[0]<<' '<<ans[1]<<endl;

    system("pause");

}