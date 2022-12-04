#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define ALL(s) (s).begin(), (s).end()
#define rALL(s) (s).rbegin(), (s).rend()
#define show(x) cout << #x << " : " << x << endl
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
template <class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>; // indexed_set<ll> st;st.order_of_key(x);
const long long mod = 1e9 + 7;

int dx[]={0, 0, +1, -1};
int dy[]={+1, -1, 0, 0};

vector<vector<pll>>g;
vector<ll>vis;
ll n, mx=-INT_MAX, start=0;
void dfs(ll u, ll dis){
    vis[u]=1;
    for(auto it : g[u]){
      if(!vis[it.ff]){
         vis[it.ff] = 1;
         ll tem = dis + it.ss;
         if(tem>mx){
            mx=tem;
            start=it.ff;
         }
         dfs(it.ff, tem);
      }
     }
}
void solve(int tc)
{
  
  cout << "Case " << tc << ": ";
  cin >> n;
  start=0;
  mx=INT_MIN;
  g.clear();
  g.resize(n+5);
  vis.clear();
  vis.resize(n+5);

  for(int i=0; i<n-1; i++){
    ll u, v, w;
    cin >> u >> v >> w;
    g[u].pb({v, w});
    g[v].pb({u, w});
  }
  
  dfs(0, 0);
  mx=INT_MIN;
  vis.clear();
  vis.resize(n+5);

  dfs(start, 0);
  cout << mx << endl;   
}

int main()
{
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
        solve(i);
}