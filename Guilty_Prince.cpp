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
vector<ll> g[2005], adj[2005];
vector<vector<ll>> vis;
vector<vector<char>>grid;
ll ans =1;
ll n, m;

bool isvalid(ll x, ll y){
    if(x>=0 && x<m && y>=0 && y<n && grid[x][y]=='.' && vis[x][y]==0) return true;
    else return false;
}

void dfs(ll x, ll y){
    vis[x][y]=1;
    for(int i=0; i<4; i++){
       if(isvalid(x+dx[i], y+dy[i])){
           ans++;
           dfs(x+dx[i], y+dy[i]);
       }
    }
}

void solve(int tc)
{
  cout << "Case "<<tc<<": ";
   
   cin >>n >> m;
   grid.resize(m+1);
   vis.resize(m+1);

   for(int i=0; i<=m; i++){
      grid[i].resize(n+1);
      vis[i].resize(n+1);
   }
   ll x, y;
   for(int i=0; i<m; i++){
     for(int j=0; j<n; j++){
          vis[i][j]=0;
          cin >> grid[i][j];
          if(grid[i][j]=='@') x=i, y=j;
     }
   }
   ans = 1;
   dfs(x, y);
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
       its a simple bfs or dfs travarsal prob.
       pick your starting cell.
       don't move out of the cell and any already visited cell. 
       if(cell = land) ans++;
*/