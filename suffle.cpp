#include<iostream>
#include<vector>
#include<random>
using namespace std;
template<typename T>
void suffle(vector<T>&a)
{
	int n=a.size();
	for(int i=0;i<n-1;i++)
	{
		int j=i+rand()%(n-i);
		swap(a[i],a[j]);
	}
}
int main()
{
	// srand(time(NULL));
	vector<int>a={1,2,3};
	suffle(a);
	for(int i=0;i<(int)a.size();i++)
		cout<<a[i]<<" ";
	cout<<endl;
}