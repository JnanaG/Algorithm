#include<iostream>
#include<vector>
using namespace std;

// ������
class Solution1 {
public:
    int countPrimes(int n) {
        int ans=0;
        for(int i=2;i<n;i++) {
            ans += isPrime(i);
        }
        return ans;
    }

    bool isPrime(int x) {
        for(int i=2;i*i<x;i++) {
            if(x%i==0){
                return false;
            }
        }
        return true;
    }
};

//����ɸѡ
class Solution2 {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<int> isPrimes(n, 1);
        for(int i=2;i<n;i++) {
            if(isPrimes[i]){
                count++;
                // ����ɸѡ������ǰ����Ԫ���������ط�����Ԫ���˳�
                for(int j=2*i;j<n;j+=i) {
                    isPrimes[j] = 0;
                }
            }
        }
        return count;
    }

};

int main()
{
    int x = 23;
    Solution2 s;
    int n = s.countPrimes(x);
    cout<<"С��"<<x<<"����������Ϊ��"<<n<<endl;

    system("pause");
}