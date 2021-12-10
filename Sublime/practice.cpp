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
const ll mod = 1e9+7;
const ull INF=5*1e18;
using namespace std;


// ----------------------------

ll dx[4] = {-1, 0, 1, 0};
ll dy[4] = {0, 1, 0, -1};

// ----------------------------
const ull N=1e3+1;
 
bool vis[N][N];
ll dis[N][N];
char a[N][N];
// ll k=0;
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool isValid(ll x, ll y, ll n, ll m)
{
    if(x<1 || y<1 || x>n || y>m || vis[x][y] || a[x][y]=='#')
        return false;
    return true;
}
void bfs(ll srcX, ll srcY, ll n, ll m)
{
    queue<pair<ll, ll>>q;
    q.push({srcX, srcY});
    vis[srcX][srcY] = true;
    dis[srcX][srcY] = 0ll;
    while(!q.empty())
    {
        ll currX = q.front().ff;
        ll currY = q.front().ss;
        q.pop();
        for(ll i=0;i<4;i++)
        {
            if(isValid(currX+dx[i], currY+dy[i], n, m))
            {
                ll newX = currX + dx[i];
                ll newY = currY + dy[i];
                if(i==0)
                    a[newX][newY]='U';
                else if(i==1)
                    a[newX][newY]='R';
                else if(i==2)
                    a[newX][newY]='D';
                else
                    a[newX][newY]='L';
                // dis[newX][newY] = dis[currX][currY] + 1;
                vis[newX][newX] = true;
                q.push({newX, newY});
            }
        }
    }
    // return true;
}
void solve()
{
    ll n, m, i, x, y, f=0, j;
    cin>>n>>m;
    pair<ll, ll>A, B;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            char c;
            cin>>c;
            a[i][j] = c;
            if(a[i][j]=='A')
                A.ff=i, A.ss=j;
            else if(a[i][j]=='B')
                B.ff=i, B.ss=j;
        }
    // bfs(A.ff, A.ss, n, m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cout<<a[i][j];
        cout<<nl;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
        
    fast();
    solve();
    // Test{
    //     solve();
    // } 
} 