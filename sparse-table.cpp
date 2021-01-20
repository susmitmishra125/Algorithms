#include<bits/stdc++.h>
using namespace std;
// https://cp-algorithms.com/data_structures/sparse-table.html
//this sparse table is for minimum range queries
template<typename T>
vector<vector<T>> precompute(vector<T>&a)
{
  T n=a.size(),K=25,i,j;
  vector<vector<T>>dp(n,vector<T>(K+1));
  for(i=0;i<n;i++)
  dp[i][0]=a[i];
  for(j=1;j<=K;j++)
    for(i=0;i+(1ll<<(j-1))<n;i++)
      dp[i][j]=min(dp[i][j-1],dp[i+(1ll<<(j-1))][j-1]);
  return dp;
}
template<typename T>
T range(T l,T r,vector<vector<T>>&dp)
{
  T K=dp[0].size()-1,i,j=0,m;
  while(l<=r)
  {
    for(i=K;i>=0;i--)
    if(l+(1ll<<i)-1<=r)
    {
      if(j==0)
      m=dp[l][i];
      else
      m=min(m,dp[l][i]);
      l=l+(1ll<<i);
      break;
    }
    j++;
  }
  return m;
}
int main()
{
  int l,r,n,i,q;
  cin>>n;
  vector<int>a(n);
  for(i=0;i<n;i++)
  cin>>a[i];
  vector<vector<int>>dp=precompute(a);
  cin>>q;
  while(q--)
  {
    cin>>l>>r;
    cout<<range(l,r,dp)<<endl;
  }

}