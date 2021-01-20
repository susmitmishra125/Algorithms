/*
 * @Author: Susmit Kumar Mishra 
 * @Date: 2021-01-10 10:35:42 
 * @Last Modified by: Susmit Kumar Mishra
 * @Last Modified time: 2021-01-10 19:10:19
 * https://cp-algorithms.com/algebra/binary-exp.html
 */

#include<iostream>
using namespace std;
typedef long long ll;
#define mod 10000007
//note if mod is prime number then we can use x^(n%m)instead of n to speed upx
//conplexity log(n)
ll power(ll x,ll n)
{
    ll res=1;
    while(n)
    {
        if(n&1)
        res=((res%mod)*(x%mod))%mod;
        x=((x%mod)*(x%mod))%mod;
        n>>=1;
    }
    return res%mod;
}
int main()
{
    ll x,n;
    cin>>x>>n;
    cout<<power(x,n);
}
