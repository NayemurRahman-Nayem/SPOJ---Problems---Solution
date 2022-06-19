//      بسم الله الرحمن الرحيم
//      All praise is due to ALLAH alone




#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<float, float> pff;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sa(v) sort(v.begin(), v.end())
#define sd(v) sort(v.begin(), v.end(), greater<>())
#define el << '\n'
#define pb push_back
#define PI 3.14159265358979323
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define fastIO	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll bin_expo(ll base, ll pow, ll m)
{       if (pow == 0) return 1;
        ll ret = bin_expo(base, pow / 2, m) % m;
        if (pow & 1)return (ret % m * ret % m * base % m) % m;
        else return (ret % m * ret % m) % m; }
ll mod_add(ll a, ll b, ll m) { return (a % m + b % m) % m; }
ll mod_sub(ll a, ll b, ll m) { return (a % m - b % m) % m; }
ll mod_mul(ll a, ll b, ll m) { return (a % m * b % m) % m; }
ll mod_div(ll a, ll b, ll m) { return (a % m * bin_expo(b, m - 2, m)) % m; }
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
int dx[] = {0, 0, +1, -1, +1, -1, -1, +1} ;
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1} ;
const ll infLL = 1e18 ;
const ll inf = 1e17 + 7 ;
const ll mod = 1e9 + 7 ;
const int mx = 2e5 + 123 ;
const double eps = 1e-7 ;




ll n , m , timer =0 ;
ll disc[mx] , low[mx] , par[mx] , vis[mx] ;
vi adj[mx] ;
vector<pair<int,int>> bridge ;
ll t ;


void dfs(int node,int parent)
{
        par[node]=parent ;
        disc[node] = low[node] = timer++ ;
        vis[node]=1 ;

        for(auto u:adj[node])
        {
                if(u==parent) continue ;
                if(!vis[u])
                {
                        dfs(u,node) ;
                        low[node] = min(low[node],low[u]) ;
                        if(disc[node]<low[u])
                        {
                                int x = min(node,u) ;
                                int y = max(node,u)  ;
                                bridge.push_back({x,y}) ;
                        }
                }
                else
                {
                        low[node]= min(low[node],disc[u]) ;
                }
        }
}


void solution()
{
        cin >> n >> m ;
        for(int i=0;i<=n;i++)
        {
                disc[i]=-1;
                adj[i].clear() ;
                low[i]=-1 ;
                vis[i]=0 ;
                par[i]=i ;
        }
        timer = 0 ;
        bridge.clear() ;
        for(int i=0;i<m;i++)
        {
                int u , v ;
                cin >> u >> v ;
                adj[u].pb(v) ;
                adj[v].pb(u) ;
        }
        for(int i=0;i<=n;i++)
        {
                if(!vis[i]) dfs(i,timer) ;
        }
        cout << "Caso #" << ++t << endl;
        if(bridge.size()==0)
        {
                cout << "Sin bloqueos" << endl ;
                return ;
        }
        cout << bridge.size() << endl ;
        sort(bridge.begin(),bridge.end()) ;
        for(auto i:bridge) cout << i.first << " " << i.second << endl ;
}


int main()
{
        fastIO;
        // file() ;
        int _ = 1; cin >> _ ;
        while (_--) solution();
        return 0;
}
