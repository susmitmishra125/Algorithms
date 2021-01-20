#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
void print(vector<vector<ll>>&a)
{
    ll i,j;
    for(i=0;i<a.size();i++)
    {
        for(j=0;j<a[0].size();j++)
        cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
vector<vector<ll>> multiply(vector<vector<ll>>a,vector<vector<ll>>b)
{
    ll i,j,k,a_n,a_m,b_n,b_m,s;
    a_n=a.size();
    a_m=a[0].size();
    b_n=b.size();
    b_m=b[0].size();
    if(a_m!=b_n)
    cout<<"Error in dimensions"<<endl;
    vector<vector<ll>>c(a_n,vector<ll>(b_m));
    for (i=0;i<a_n;i++)
    {
        for(j=0;j<b_m;j++)
        {
            s=0;
            for (k=0;k<a_m;k++)
                s=(s%mod+((a[i][k]%mod)*(b[k][j]%mod))%mod)%mod;
            c[i][j]=s;
        }
    }
    return c;
}
vector<vector<ll>> matrix_power(vector<vector<ll>>X,ll n)
{
    vector<vector<ll>>res(X.size(),vector<ll>(X.size(),0));
    ll i;
    for(i=0;i<X.size();i++)
    res[i][i]=1;
    while(n)
    {
        if(n%2==1)
        res=multiply(X,res);
        X=multiply(X,X);
        n/=2;
    }
    return res;
}
void solve()
{
    ll n;
    cin>>n;
    if(n==0)
    {
        cout<<0<<endl;
        return ;
    }
    if(n==1)
    {
        cout<<1<<endl;
        return ;
    }
    vector<vector<ll>>X={{1,1},{1,0}};
    vector<vector<ll>>T={{1},{0}};
    vector<vector<ll>>p=matrix_power(X,n-1);
    
    vector<vector<ll>>res=multiply(p,T);
    cout<<res[0][0]%mod<<endl;
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //clock_t z=clock();
    ll tt=1;
    
    // cin>>tt;
    while(tt--)
        solve();
    // printf("\nTime taken %0.4lf\n",(double)(clock()-z)/(CLOCKS_PER_SEC));
}