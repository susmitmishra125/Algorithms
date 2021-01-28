#include<bits/stdc++.h>
using namespace std;
//supports log(n) query update and range sum queries
// this is 1 based indexing
template <typename T>
T sum(vector<T>&tree,T k)
{
	T s=0;
	while(k>=1)
	{
		s+=tree[k];
		k-=k&-k;
	}
	return s;
}
// increase the value at k by x
template<typename T>
T add(vector<T>&tree,T k,T x)
{
	T n=tree.size()-1;
	while(k<=n)
	{
		tree[k]+=x;
		k+=k&-k;
	}
	return ;
}
template<typename T>
void construction(vector<T>&a,vector<T>&tree)
{
	T i,n=a.size()-1;
	vector<T>dp(n+1,0);
	for(i=1;i<=n;i++)
	dp[i]=dp[i-1]+a[i];
	for(i=1;i<=n;i++)
		tree[i]=dp[i]-dp[i-k&-k];
	return ;
}
int main()
{
  
}