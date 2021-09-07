#include<iostream>
using namespace std;
//https://cp-algorithms.com/algebra/euclid-algorithm.html
template <typename T>
T gcd(T x, T y)
{
    if(x<y)
    return gcd(y,x);
    T temp;
    while(y)
    {   
        temp=x%y;
        x=y;
        y=temp;
    }
    return x;
}
template <typename T>
T lcm(T x, T y)
{
    return (x*y)/gcd(x,y);
}
int main()
{
    int n,m;
    cin>>n>>m;
    cout<<"GCD is "<<gcd(n,m)<<endl;
    cout<<"lcm is "<<lcm(n,m)<<endl;
    // note the stl fuction for gcd is __gcd(a,b)

}