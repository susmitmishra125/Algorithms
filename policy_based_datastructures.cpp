// https://codeforces.com/blog/entry/11080 

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;


// this template is for ordered_set
typedef tree<
int, // Key type
null_type,// Mapped-policy Mapped for map
less<int>,// Key comparison functor
rb_tree_tag,// Specifies which underlying data structure to use
tree_order_statistics_node_update>// A policy for updating node invariants
ordered_set;
// this gives two extra functions apart from set
// find_by_order() and order_of_key()
// The first returns an iterator to the k-th largest element 
// (counting from zero), the second — the number of items in a set that are 
// strictly smaller than our item. 
// for using multiset use less_equal<int> in place of less<int> but then lower_bound 
// upper_bound work oppositely 
int main()
{
	ordered_set X;
	X.insert(1);
	X.insert(2);
	X.insert(4);
	X.insert(8);
	X.insert(16);

  cout<<*X.find_by_order(1)<<endl; // 2
  cout<<*X.find_by_order(2)<<endl; // 4
  cout<<*X.find_by_order(4)<<endl; // 16
  cout<<(end(X)==X.find_by_order(6))<<endl; // true

  cout<<X.order_of_key(-5)<<endl;  // 0
  cout<<X.order_of_key(1)<<endl;   // 0
  cout<<X.order_of_key(3)<<endl;   // 2
  cout<<X.order_of_key(4)<<endl;   // 2
  cout<<X.order_of_key(400)<<endl; // 5
}
