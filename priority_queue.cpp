#include<bits/stdc++.h>
using namespace std;

// struct node{
// 	int val,index;
// 	node(int val,int index):val(val),index(index){}
// };
// struct compare{
// 	bool operator()(node a,node b){
// 		return a.val<b.val;
// 	}
// };


class node{
	public:
		int val,index;
		node(int val,int index):val(val),index(index){}
};
bool operator<(node a,node b){
	return a.val<b.val;
}


int main()
{
	// priority_queue<node,vector<node>,compare>q;
	priority_queue<node>q;
	q.push(node(0,4));
	q.push(node(3,1));
	q.push(node(2,2));
	cout<<q.top().val<<" "<<q.top().index<<endl;
	q.pop();
	cout<<q.top().val<<" "<<q.top().index<<endl;
	q.pop();
	cout<<q.top().val<<" "<<q.top().index<<endl;
	q.pop();
}