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
#define mp          make_pair
#define ff          first
#define ss          second
#define mll         map<ll, ll>
#define vpll        vector<pair<ll,ll>>
#define vll         vector<ll>
#define vcc         vector<char>
#define pll         pair<ll, ll>
#define queue       queue<ll> 
#define pq          priority_queue
#define slk         stack<ll>
#define loop(i,n)   for(ll i=0;i<n;i++)
#define nl          "\n"
#define in          insert
#define b_s         binary_search
#define l_b         lower_bound
#define u_b         upper_bound
#define all(v)      v.begin(),v.end()
#define mem(a,x)    memset(a,x,sizeof(a))  
const ll mod =1e9+7;
const ull INF=5*1e18;
const ull N=1e6+7;
using namespace std; 

void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{
    ll n, i, j, k, ans=0;
    cin>>n;
    vll v, v1;
    k = n/2;
    set<ll>s;
    ll a[n][5], b[5][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<5;j++)
            cin>>a[i][j];
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<n;j++)
            b[i][j]=a[j][i];
    }
    for(i=0;i<5;i++)
    {
        ll count = 0, f=1;
        for(j=0;j<n;j++)
        {
            for(auto h: s)
            {
                if(j==h)
                    f=0;
            }
            if(b[i][j]!=0 && f)
                count++, v.pb(j);
            f=1;
            if(count==k)
            {
                break;
            }
        }
        if(count==k)
        {
            ans++;
            // ans++;
                for(ll g=0;g<v.size();g++)
                    s.insert(v[g]);
        }
        v.clear();
    }
    if(ans==2)
        cout<<"YES\n";
    else
        cout<<"NO\n";


}
 
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
        
    fast();
    // store();
    // solve();
    Test{
        solve();
    }
}
ll n, i, a, b, mn=INT_MAX;
    cin>>a>>b;
    n = max(a, b);
    n = n | (n>>1);
    n = n | (n>>2);
    n = n | (n>>4);
    n = n | (n>>8);
    n = n | (n>>16);
    n = n | (n>>32);
    n = (n+1)>>1;   
    while(n>0)
    {
        mn = min(mn, (a^n)+(b^n));
        n/=2;
    }
    cout<<mn<<nl;