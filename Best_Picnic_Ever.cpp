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
ll k, n, m;
vector<ll>nodes;
vector<ll> cnt(1005, 0), vis;
vector<vector<ll>>g;

void dfs(ll u){
  vis[u]=1;
  cnt[u]++;
  for(auto it : g[u]){
    if(!vis[it])dfs(it);
  }
}

void solve(int tc)
{
  cout << "Case " << tc << ": ";
  cin >> k >> n >> m;
  cnt.clear();
  cnt.resize(n+5);
  vis.clear();
  vis.resize(n+5);
  nodes.clear();
  nodes.resize(n+5);
  g.clear();
  g.resize(n+5);

  for(int i=0; i<k; i++) cin >> nodes[i];
  for(int i=0; i<m; i++){
     ll u, v;
     cin >> u >> v;
     g[u].pb(v);
  }
  
  for(int i=0; i<nodes.size(); i++){
      ll u=nodes[i];
      vis.clear();
      vis.resize(n+5);
      dfs(u);
  }

  ll ans =0;
  for(int i=1; i<=n; i++){
    if(cnt[i]>=k) ans++;
  }
  cout << ans << endl;
}

int main()
{
    int tc = 1;
    cin >> tc;
    for (int i = 1; i <= tc; i++)
        solve(i);
}


/*
    hints:
      idea is quite bruteforces.
      make a global count array (cnt[]), when node x will be visited, count of node x will be increased by 1.  cnt[x]++ 
      k<=100.
      maximum 100 city where can be people, they want to join picnic.
      So check for every people in which city's he can reach.  
        do this for rest (k-1) pepole also.

      now travarse every city and check how many time it has been visited.
      (this can be done by cnt[] array mentioned)
      if(cnt[x]>=k) then it can be a picnic spot, and increse your ans by 1.

         finally after travarsing the whole array you will get your desired answer. 
*/