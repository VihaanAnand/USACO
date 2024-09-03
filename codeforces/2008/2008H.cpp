#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m;
        cin>>n>>m;
        vector<int>a(n);
        vector<int>c(n+1,0ll);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            c[a[i]]++;
        }
        for(int i=1;i<=n;i++)
        {
            c[i]+=c[i-1];
        }
        int res[n+1]={0};
        for(int x=1;x<=n;x++)
        {
            int l=0,r=x;
            while(l<r)
            {
                int mid=(l+r)/2;
                int cnt=c[mid];
                for(int k=1;k*x<=n;k++)
                {
                    cnt+=c[min(k*x+mid,n)]-c[k*x-1];
                }
                if(cnt-1>=n/2)
                {
                    r=mid;
                }
                else
                {
                    l=mid+1;
                }
            }
            res[x]=l;
        }
        while(m--)
        {
            int x;
            cin>>x;
            cout<<res[x]<<" ";
        }
        cout<<endl;
    }
}