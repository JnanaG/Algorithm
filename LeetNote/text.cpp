#include<bits/stdc++.h>
using namespace std;


void PrintV(vector<int>& v) {
	for(int& x:v) {
		cout<<x<<" ";
	}
	cout<<endl;
}
class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> arr(26, 0);
        vector<int> used;
        for(char& c:word) {
            int cur = c-'a';
            arr[cur] += 1;
        }
        for(int& x:arr) {
            if(x!=0) {
                used.push_back(x);
            }
        }
        sort(used.begin(), used.end());
        if(used[0]==used[used.size()-1]&&used[0]>1) {
            return false;
        }

		PrintV(used);

        if(used[0]>1) {
  			int cha = used[0]-1;
			for(int& x:used) {
				x -= cha;
			}
        }
		PrintV(used);
        int max = used[used.size()-1];
        int min = used[0];
        int min_times = count(used.begin(), used.end(), min);
        int max_times = count(used.begin(), used.end(), max);
        set<int> s(used.begin(), used.end());
		cout<<"max: "<<max<<endl;
		cout<<"min: "<<min<<endl;
        if(s.size()>2)  return false;
        if((max-min)>1)   return false;
        if(min_times>1 && max_times>1)
            return false;
        return true;

    }
};


int main() {
	string s= "zz";
	Solution sn;
	bool y=sn.equalFrequency(s);
	cout<<y<<endl;
	system("pause");
	return 0;
	
}