#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long p[n+1]={0},b[n+1]={0};
        int us[n+1]={0};
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
        }
        string s;
        cin >> s;
        for(int i=1;i<=n;i++)
        {
            if(us[i])continue;
            int sz=0;
            while(!us[i])
            {
                us[i]=1;
                sz += s[i - 1] == '0';
                i=p[i];
            }
            while(us[i]!=2)
            {
                b[i]=sz;
                us[i]=2;
                i=p[i];
            }
        }
        for(int i=1;i<=n;i++)
        {
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
}