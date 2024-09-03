#include <bits/stdc++.h>

using namespace std;
constexpr int mod=1e9+7;

long long binpow(long long a,long long b)
{
    if(b==0)
    {
        return 1;
    }
    if(b%2)
    {
        return (a*binpow(a,b-1))%mod;
    }
    return binpow((a*a)%mod,b/2);
}

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long a[n],sum=0,sumsq=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];sum%=mod;
            sumsq+=a[i]*a[i];
            sumsq%=mod;
        }
        sum*=sum;sum%=mod;
        sum=(sum-sumsq+mod)%mod;
        sum=(sum*binpow(2,mod-2))%mod;
        long long cnt=n*(n-1)/2;cnt%=mod;
        cout<<(sum%mod)*binpow(cnt,mod-2)%mod<<endl;
    }
}