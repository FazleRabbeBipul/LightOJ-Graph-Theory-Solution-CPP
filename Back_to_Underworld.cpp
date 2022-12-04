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
//vector<ll> g[2005], adj[2005];

vector<ll> vis, colour;
vector<vector<ll>>g;
ll ans =1;
ll x, y, n;


void bfs(ll u){
   vis[u]=1;
   
   queue<ll>q;
   q.push(u);

   while(!q.empty()){
      ll u = q.front();
      if(colour[u]==1)x++;
      else y++;
      vis[u]=1;
      q.pop();
      for(auto it : g[u]){
        if(!vis[it]){
            if(colour[u]==2){
              colour[it]=1;
              q.push(it);
            }
            else{
               colour[it]=2;
               q.push(it);
            }
            vis[it]=1; 
        }
      }
   }
}

void solve(int tc)
{
  ans =0;
  cout << "Case "<<tc<<": ";
  cin >> n;
  colour.clear();
  g.clear();
  vis.clear();
  vis.resize(200005);
  g.resize(200005);
  colour.resize(200005);

  ll st;
  while(n--){
     ll u, v;
     cin >> u >> v;
     st=u;
     g[u].pb(v);
     g[v].pb(u);
  }
  
  
  colour[st]=1;
  for(int i=1; i<200005; i++){
    if(g[i].size() && !vis[i]){
            x=y=0;
            colour[i]=1;
            bfs(i);

            ans += max(x, y);
    }
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
      its a graph bipartite colouring problem. (with *bfs)
      just try to colour them with two colour(1 and 2)
           and ans is the maximum count between (1, 2) 
      note: graph can be separated. So calculate maximum value of 
            individual connected component.
*/