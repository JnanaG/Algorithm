#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.size()==0){
            return 0;
        }
        int i=0;
        for(int j=0;j<nums.size();++j){
            if(nums[j]!=nums[i]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
void PrintVector(vector<int>& v){
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> v = {1, 1, 2, 4, 5, 5, 5, 8};
    Solution s;
    int cnt = s.removeDuplicates(v);
    cout<<cnt<<endl;

    system("pause");
}