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
vector<ll> vis;
//ll ans=0, ans2=0;
ll st;
vector<vector<pll>>incoming, outgoing;


ll bfs(ll u, ll tot, ll par){
   vis[u]=1;
   queue<pll>q;
   q.push({u,par});

   while(!q.empty()){
      ll u=q.front().ff,  par=q.front().ss;
      q.pop();
      vis[u]=1;

      for(auto it : outgoing[u]){
         ll x =it.ff, val =it.ss;
         if(!vis[x] && x!=par){
            vis[x]=1;
            q.push({x,u}); 
         }
      }
      for(auto it : incoming[u]){
         ll x = it.ff;
         if(!vis[x] && x!=par){
            tot += it.ss;
            vis[x]=1;
            q.push({x, u});
         }
      }   
   }
   return tot;
}

void solve(int tc)
{
   cout << "Case " << tc << ": ";
   vis.clear();
   incoming.clear();
   outgoing.clear();

   ll m, n;
   cin >> m;
   vis.resize(m+5);
   incoming.resize(m+5);
   outgoing.resize(m+5);
   n=m;

   ll st, ed, cost;
   while(m--){             
     ll u, v, w;
     cin >> u >>v >> w;
     outgoing[u].pb({v, w});       // storing incoming & outgoing edge.if you need to use incoming edge it will cost W 
     incoming[v].pb({u, w});       
     st=u, ed=v, cost=w;          /// choose a edege , starting node-> ednding node,(st, ed)
   }
   
   ll ans = bfs(ed, 0, st);   /// trying to make a cyclic st to ed in this dirrection.
   vis.clear();               /// cost will be zero for first edge.
   vis.resize(n+5);
 
  
   ll ans2 = cost;
   ans2 = bfs(st, ans2, ed);
   
   cout << min(ans, ans2)<<endl;
}

int main()
{
    int ts = 1;
    cin >> ts;
    for(int tc=1; tc<=ts; tc++){
        solve(tc);
    }
}



/*
      hints:
       number of edge = n, node=2;
       and from any node you can visit any other nodes.
          that means it will be a cyclic graph
       
      hints2:
         its sure it will be crcular path as total node number is N.
         so it will be clock wise or anticlockwise.

      Ans will be the minimum of cost between(converting this graph in clockwise and anticlockwise)
      ans = min(cost_clockwise, cost_anticlockwise);


      Solution:
         just track incoming & outgoing edges
         outgoing means given direction, that cost 0. (u->v) it cost 0.
         incoming means (u<-v) , but if we need to use it the it will cost W.as its a reverse path.

         solution approch is very easy, just pick a edge u->v, 
          then,  1) try to make all the edges in this sequence 
                 2) try to make all the edges in reverse sequence
              ans will be min of cost(1, 2).                                           
*/