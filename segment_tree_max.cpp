#include<bits/stdc++.h>
using namespace std;
int Max(vector<int>&tree,int l,int r)
{
	int n=tree.size()/2;

	l+=n;r+=n;
	int m=INT_MIN;
	while(l<=r)
	{
		if(l%2==1)
			m=max(m,tree[l++]);
		if(r%2==0)
			m=max(m,tree[r--]);
		l/=2;r/=2;
	}
	return m;
}
void update(vector<int>&tree,int k,int x)
{
	int n=tree.size()/2;
	k+=n;
	tree[k]=x;
	for(k/=2;k>=1;k=k/2)
		tree[k]=max(tree[2*k],tree[2*k+1]);
	return ;
}
int main()
{
	int n,i;
	cin>>n;
	vector<int>a(n);
	for(i=0;i<n;i++)
		cin>>a[i];
	vector<int>tree(2*n);
	for(i=n;i<2*n;i++)
	tree[i]=a[i-n];
	for(i=n-1;i>=0;i--)
		tree[i]=max(tree[2*i],tree[2*i+1]);
	cout<<Max(tree,0,0)<<endl;
	cout<<Max(tree,0,7)<<endl;
	cout<<Max(tree,3,7)<<endl;
	update(tree,1,6);
	cout<<Max(tree,0,7)<<endl;
	


}