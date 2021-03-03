#include<iostream>
using namespace std;
#ifndef ONLINE_JUDGE
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void debug_out() { cout << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cout << ' ' << H; debug_out(T...); }
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif
class heap{//max heap A[parent(i)]>=A[i]
public:
	int *a,n,h;
	void arrayinsert(int x)	
	{
		n++;
		a=(int *)realloc(a,(n+1)*sizeof(int));
		a[n]=x;
	}
	void print()
	{
		for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
		cout<<endl;
	}
	heap(){h=0;n=0;a=(int *)malloc(sizeof(int));}
	int heapsize(void){return h;}
	void heapsize(int x){h=x;}
	
	int length(void){return n;}
	
	int parent(int i)
	{
		return i/2;
	}
	int left(int i)
	{
		return 2*i;//1 indexing otherwise 2*i+1
	}
	int right(int i)
	{
		return 2*i+1;//1 indexing otherwise 2*(i+1)
	}
	
	void maxheapify(int index)
	{
		int l=left(index);
		int r=right(index);
		int largest=index;
		if(l<=heapsize() && a[l]>a[largest])
			largest=l;
		
		if(r<=heapsize() && a[r]>a[largest])
			largest=r;
		if(largest!=index)
		{
			swap(a[index],a[largest]);
			maxheapify(largest);
		}
	}

	void buildmaxheap(void){//note the running time of the buildmaxheap is o(n)
		heapsize(length());
		for (int i=length()/2;i>=1;i--)
			maxheapify(i);
	}



	int heapmax(void)//returns the element with maximum key
	{
		return a[1];
	}
	int heapextractmax(void){
		if(heapsize()<1)
			printf("Heap underflow");
		int max=a[1];
		a[1]=a[heapsize()];
		heapsize(heapsize()-1);
		maxheapify(1);
		return max;
	}

	void heapincreasekey(int index,int key)
	{
		if(a[index]>key)
			printf("error new key is less than old key");
		a[index]=key;
		while(index>1 && a[index]>a[parent(index)])
			{
				swap(a[index],a[parent(index)]);
				index=parent(index);
			}
	}
	void maxheapinsert(int key)
	{
		heapsize(heapsize()+1);
		arrayinsert(INT32_MIN);
		// a[heapsize()]=INT32_MIN;
		heapincreasekey(heapsize(),key);
	}
};
int main()
{
	int x,i,n;
	heap h;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		h.arrayinsert(x);
	}
	h.buildmaxheap();
	h.print();
	h.heapincreasekey(9,15);
	h.print();
}