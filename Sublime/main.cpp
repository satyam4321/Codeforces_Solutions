/* hare krishna hare krishna
krishna krishna hare hare
hare rama hare rama
rama rama hare hare*/

#include<bits/stdc++.h>
#define ll          long long
#define ull         unsigned long long
#define ld          long double
#define Test        ll t;cin>>t;while(t--)
#define pb          push_back
#define ff          first
#define ss          second
#define mll         map<ll, ll>
#define vpll        vector<pair<ll,ll>>
#define vll         vector<ll>
#define vcc         vector<char>
#define slk         stack<ll>
#define loop(i,n)   for(ll i=0;i<n;i++)
#define nl          "\n"
#define in          insert
#define b_s         binary_search
#define l_b         lower_bound
#define u_b         upper_bound
#define all(v)      v.begin(),v.end()
#define mem(a,x)    memset(a,x,sizeof(a))  
#define mod1        998244353
const ll mod =1e9+7;
const ull INF=5*1e18;
const ull N=1e6+7;
using namespace std;
ll fact[200006];
bool isprime(ll a)
{
    ll i;
    if(a==1)
        return false;
    if(a==2)
        return true;
    if(a%2==0)
        return false;
    for(i=3;i*i<=a;i+=2)
        if(a%i==0)
            return false;
    return true;
}

ll fastpow(ll a, ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b&1)
            ans=(ans*a)%mod1;
        a = (a*a)%mod1;
        b/=2;
    }
    return ans;
}
ll modinv(ll m)
{
    return fastpow(m, mod1-2);
}

void factstore()
{
    fact[0]=1;
    for(ll i=1;i<=200005;i++)
        fact[i]=(i*fact[i-1])%mod1;
}

void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void solve()
{

    ll n, i, mx1=-1, mx2=-1, ans=0, s1=0, s2=0, s=0;
    cin>>n;
    vll v(n);
    mll m;
    loop(i, n)
    {
        cin>>v[i];
        mx1=max(v[i], mx1);
        m[v[i]]++;
    }
    for(i=0;i<n;i++)
    {
        if(v[i]>mx2 && v[i]!=mx1)
            mx2=v[i];
    }
    
    if(m[mx1]!=1)
        cout<<fact[n]<<nl;
    else if(mx1-mx2>1)
        cout<<0<<nl;
    else
    {
        ans=fact[n];
        s2 = fact[n-1-m[mx2]];
        // cout<<s1<<" "<<s2<<" ";
        for(i=1;i<n;i++)
        {
            if(i-1<m[mx2])
                continue;
            s = (fact[i-1]%mod1)*(modinv(fact[i-1-m[mx2]])%mod1)*(modinv(fact[m[mx2]])%mod1)*(s2%mod1)*(fact[m[mx2]]%mod1);
            ans=(ans-s)%mod1;
        }
        cout<<ans<<nl;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
        
    fast();
    // solve();
    factstore();
    Test{
        solve();
    }

}