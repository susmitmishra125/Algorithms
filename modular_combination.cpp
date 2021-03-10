#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll fact[1000005];
void factorial(void )
{
    ll i;
    fact[0]=1;
    for(i=1;i<=1000000;i++)
    fact[i]=(i*fact[i-1])%mod;
}
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
template<typename T>
T ncr(T n, T r)
{
    return ((fact[n]%mod)*(modinv(fact[n-r]*fact[r])%mod))%mod;
}

int main()
{
    int n,r;
    cin>>n>>r;
    cout<<ncr(n,r)<<endl;
}