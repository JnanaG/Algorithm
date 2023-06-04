#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRepOpt1(string text) {
        int n =text.size();
        int ct[26]={0};
        for(char& c:text) {
            ct[c-'a']++;
        }
        int res=0;
        for(int i=0;i<n-1;i++) {
            int j=i+1;
            int count = ct[text[i]-'a'];
            while(text[i]==text[j]&&j<n) {
                j++;
            }
            int k = j;
            if((j-i)<count) {
                j++;
            }
            while(text[i]==text[j]&&j<n) {
                j++;
            }
            int len = j-i;
            res = max(res, min(len, count));
            i = k-1;
        }
        return res;

    }
};
int main() {
    string text="baaabaaaaaaabaab";
    Solution sn;
    int res = sn.maxRepOpt1(text);
    cout<<res<<endl;
    return 0;
}