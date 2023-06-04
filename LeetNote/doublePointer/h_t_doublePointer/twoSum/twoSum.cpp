#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int
     target) {
        int l=0, r=nums.size()-1;
        while (l<=r)
        {
            if(nums[l]+nums[r]<target) {
                l++;
            }else if(nums[l]+nums[r]>target) {
                r--;
            }else {
                return {l, r};
            }
        }
        return {};
    }
};

void PrintVector(vector<int>& v) {
    for(auto it=v.begin();it!=v.end();it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    Solution s;
    vector<int> ans=s.twoSum(v, 6);
    PrintVector(ans);
    system("pause");
}