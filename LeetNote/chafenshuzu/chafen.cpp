#include<vector>
#include<iostream>
#include<map>
using namespace std;

typedef pair<int, int> PII;
#define x first
#define y second
typedef long long ll;

int getval(int x) {
    if(x==0) return 1;
    if(x==1) return 3;
    return 4;
}

int main() {
    int n;
    cin>>n;
    vector<PII> v;
    v.resize(n);
    int start=1e9, r=0;
    for(int i=0;i<n;++i) {
        cin>>v[i].x>>v[i].y;
        start = min(start, v[i].x);
        r = max(r, v[i].y);
    }
    map<int, int> cnts; //离散差分数组
    for(int i=0;i<n;++i) {
        int a=v[i].x, b=v[i].y;
        cnts[a]++;
        cnts[b+1]--;
    }
    ll res=0, sum=0;

    for(auto& [a,b]:cnts) {
        ll cost= getval(sum)*(a-start);
        sum += b;
        res += cost;
        start = a;
        if(start>r) break;
    }
    cout<<res<<endl;
    system("pause");
    return 0;

}