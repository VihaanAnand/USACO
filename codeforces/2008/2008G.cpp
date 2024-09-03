#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        long long a[n+1],g=0,mx=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            g=__gcd(g,a[i]);
            mx=max(mx,a[i]);
        }
        if(g==0)
        {
            cout<<k<<endl;
            continue;
        }
        sort(a,a+n);
        int q=-g;
        if(n!=1)
        {
            for(int i=0;i<n;i++)
            {
                q+=g;
                a[i]=q;
            }
        }
        a[n]=1e16;
        long long lst=-1;
        for(int i=0;i<=n;i++)
        {
            if(k<=a[i]-lst-1)
            {
                break;
            }
            k-=max(a[i]-lst-1,0ll);
            lst=a[i];
        }
        cout<<lst+k<<endl;
    }
}