#include<bits/stdc++.h>
using namespace std;
void KMP(string s,int lps[]){
	int n=s.size(),i=0,j=-1;
	lps[0]=-1;
	while(i<n)
	{
		while(j!=-1 && s[i]!=s[j]) j=lps[j];
		i++;j++;lps[i]=j;
	}
}
int main()
{
	string s="abacabad";
	int n=s.size();
	int lps[n+1];
	LPS(s,lps);
	for(int i=1;i<=n;i++)
		cout<<lps[i]<<" ";
	cout<<endl;
}