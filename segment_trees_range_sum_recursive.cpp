// debug a.cpp -o a.exe && ./a.exe</mnt/d/Projects/CPP_Sublime/inputf.in
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum(vector<ll>&tree,ll node,ll node_l,ll node_r,ll q_l,ll q_r)
{
  if(node_l>=q_l && node_r<=q_r)
    return tree[node];
  if(q_r<node_l  || q_l>node_r )
    return 0;
  return sum(tree,node*2,node_l,(node_l+node_r)/2,q_l,q_r)+sum(tree,node*2+1,(node_l+node_r+1)/2,node_r,q_l,q_r);
}
void update(vector<ll>&tree,ll node,ll x)
{
  if(node==1)
  {
    tree[node]+=x;
    return;
  }
  tree[node]+=x;
  update(tree,node/2,x);
}
void solve()
{
  ll n,q,i,l,r,x;
  cin>>n>>q;

  vector<ll>a(n,0);
  for(i=0;i<n;i++)
    cin>>a[i];
  ll p=1;
  while(p<n)
    p=p*2;
  for(i=n;i<p;i++)
    a.push_back(0);
  n=a.size();
  vector<ll>tree(2*n,0);
  for(i=n;i<2*n;i++)
    tree[i]=a[i-n];
  for(i=n-1;i>=1;i--)
    tree[i]=tree[i*2]+tree[2*i+1];
  while(q--)
  {
    cin>>x>>l>>r;
    if(x==1)
    {
      update(tree,n+l-1,r-a[l-1]);
      a[l-1]=r;
    }
    else
    {
      l--;
      r--;
      cout<<sum(tree,1,0,n-1,l,r)<<endl;
    }
  }
}
int main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  // clock_t z=clock();
  ll tt=1;
  
  // cin>>tt;
  while(tt--)
    solve();
  // cerr<<"[Finished in "<<(double)(clock()-z)*1000/(CLOCKS_PER_SEC)<<"ms]\n";
}
