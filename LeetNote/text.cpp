#include<bits/stdc++.h>
using namespace std;


void PrintV(vector<int>& v) {
	for(int& x:v) {
		cout<<x<<" ";
	}
	cout<<endl;
}
// vector<int> applyOperations(vector<int>& nums) {
//     int n=nums.size();
//     vector<int> res;
//     for(int i=0;i<n-1;i++) {
//         int j=i+1;
//         if(nums[i]==nums[j]) {
//             nums[i] *= 2;
//             nums[j] = 0;
            
//         }
//         if(nums[i]!=0) {
//             res.push_back(nums[i]);
//         }
//     }
//     int len = res.size();
//     res.insert(res.end(), n-len, 0);
//     return res;
// }

vector<int> applyOperations(vector<int>& nums) {
    int n = nums.size();
    for(int i=0,j=0;i<n;i++){
        if(i+1<n && nums[i]==nums[i+1]){
            nums[i]*=2;
            nums[i+1]=0;
        }
    

        if(nums[i]!=0){
            swap(nums[i],nums[j]);
            j++;
        }
    }
    return nums;
}

int main() {
    vector<int> v{1,2,2,1,1,0};
    vector<int> res = applyOperations(v);
    PrintV(res);
	return 0;
	
}