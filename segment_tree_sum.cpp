#include<bits/stdc++.h>
using namespace std;
// void construct (vector<int>&tree,int index){
// 	int i;
// 	if(index%2)

// }
int sum(vector<int>&tree,int l,int r)
{
	int n=tree.size()/2,s=0;

	l+=n;
	r+=n;
	while(l<=r)
	{
		if(l%2==1)
			s+=tree[l++];
		if(r%2==0)
			s+=tree[r--];
		l/=2;
		r/=2;
	}
	return s;
}
void add(vector<int>&tree,int k,int x)
{
	int n=tree.size()/2;
	k+=n;
	tree[k]+=x;
	for(k/=2;k>=1;k/=2)
	{
		tree[k]=tree[2*k]+tree[2*k+1];
	}
	return ;
}
int main(){
	int n,i;
	cin>>n;
	vector<int>a(n);
	for(i=0;i<n;i++)
		cin>>a[i];
	vector<int>dp(n);
	dp[0]=a[0];
	for(i=1;i<n;i++)
		dp[i]=a[i]+dp[i-1];
	vector<int>tree(2*n,-1);
	for(i=n;i<2*n;i++)
		tree[i]=a[i-n];
	for(i=n-1;i>=0;i--)
		tree[i]=tree[2*i]+tree[2*i+1];
	for(i=1;i<2*n;i++)
		cout<<tree[i]<<" ";
	cout<<endl;
	cout<<sum(tree,0,7)<<endl;
	cout<<sum(tree,1,1)<<endl;
	cout<<sum(tree,2,4)<<endl;
	cout<<sum(tree,1,7)<<endl;
	cout<<sum(tree,6,7)<<endl;
	add(tree,0,1);
	cout<<sum(tree,0,7)<<endl;

}