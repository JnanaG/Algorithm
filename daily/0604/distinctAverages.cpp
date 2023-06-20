#include<bits/stdc++.h>
using namespace std;


int distinctAverages(vector<int>& nums) {
    int i=0, j=nums.size()-1;
    sort(nums.begin(), nums.end());
    int sum=INT_MAX;
    unordered_set<int> s;
    while(i<j) {
        int cur = nums[i]+nums[j];
        if(cur!=sum) {
            s.insert(cur);
        }
        sum = cur;
        i++;
        j--;
    }
    return s.size();
}

int main() {
    vector<int> nums{4,1,4,0,3,5};
    int res = distinctAverages(nums);
    cout<<res<<endl;
    return 0;
}