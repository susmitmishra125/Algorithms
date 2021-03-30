#include<iostream>
using namespace std;
class node{
	public :
	int val;
	node *next;
};
class queue{
	public:
	node *front,*back;
	queue(){
		front=NULL;
		back=NULL;
	}
	void insert(int key)
	{
		node *temp;
		temp=new node();
		temp->val=key;
		temp->next=NULL;
		if(front==back && front==NULL)
				front=back=temp;
		else
		{
			back->next=temp;
			back=back->next;
		}
		return ;
	}
	void pop()
	{
		if(front==NULL)
			{
				cout<<"error queue is empty";
			}
		else
			if(front==back)
				front=back=NULL;
			else
				front=front->next;

		return ;
	}
	void print()
	{
		node *temp=front;
		while(temp)
		{
			cout<<temp->val<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
};

int main()
{
	
}