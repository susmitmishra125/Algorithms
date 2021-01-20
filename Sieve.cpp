#include<iostream>
#include<vector>
#include<time.h>
using namespace std;


#define N 1000000
vector<bool>prime(N+5,true);
void sieve(void )
{
    int i,j;
    prime[1]=false;
    for(i=4;i<=N;i+=2)
        prime[i]=false;
    for(i=3;i*i<N;i++)
        if(prime[i])
            for(j=i*i;j<=N;j+=i)
                prime[j]=false;
    return ;
}

int main()
{
    int n,i;
    // clock_t z=clock();
    sieve();
    // printf("\nTime taken %0.4lf\n",(double)(clock()-z)/(CLOCKS_PER_SEC));
}