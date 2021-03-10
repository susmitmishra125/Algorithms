#include<iostream>
using namespace std;
#define mod 1000000007
typedef long long ll ;
template <typename T>
T power(T x, T n)
{
    T res=1;
    x=x%mod;
    while(n)
    {
        if(n%2==1)
        res=(res*x)%mod;
        x=(x*x)%mod;
        n/=2;
    }
    return res;
}
template<typename T>
T modinv(T x)
{
    return power(x,(ll)(mod-2))%mod;
}
int main()
{
    ll n;
    modinv(n);
}