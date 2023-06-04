#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int cur_s=min(height[l], height[r]) * (r-l);
        while(l<=r) {
            if(height[l]<=height[r]) {
                l++;
            }else if(height[l]>height[r]) {
                r--;
            }
            int s = min(height[l], height[r]) * (r-l);
            if(s>cur_s) {
                cur_s = s;
            }
        }
        return cur_s;
    }
};

void PrintV(vector<int>& v) {
    for(auto it=v.begin();it!=v.end();it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
}
int main() {
    vector<int> height{1,8,6,2,5,4,8,3,7};
    PrintV(height);
    Solution s;
    int ans = s.maxArea(height);
    cout<<ans<<endl;
    system("pause");
    return 0;
}