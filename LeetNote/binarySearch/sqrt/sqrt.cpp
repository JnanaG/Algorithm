#include<iostream>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int index=-1, l=0, r=x;
        while (l<=r)
        {
            int mid = l + (r-l)/2;
            if(mid*mid<=x)
            {
                index = mid;
                l = mid + 1;
                cout<<"l: "<<l<<endl;
            }else{
                r = mid - 1;
                cout<<"r: "<<r<<endl;
            }
            cout<<endl;
        }
        return index;
    }
};

int main()
{
    int n = 27;
    Solution s;
    cout<<n<<"的平方根为： "<<s.mySqrt(n)<<endl;
    system("pause");
}