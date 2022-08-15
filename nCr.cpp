long long BigMod(long long B,long long P,long long M)
{
    long long R=1;
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2LL;
        B=(B*B)%M;
    }
    return R;
}
long long fact[2000005];
long long ncr(long long n, long long r,long long mod)
{
    if(fact[0]==0)
    {
        fact[0]=1;
        for(i=1; i<2000003; i++)
        {
            fact[i]=fact[i-1]*i;
            fact[i]%=mod;
        }
    }
    long long ret=fact[n];
    ret*=BigMod(fact[r],mod-2,mod);
    ret%=mod;
    ret*=BigMod(fact[n-r],mod-2,mod);
    ret%=mod;
    return ret;
}