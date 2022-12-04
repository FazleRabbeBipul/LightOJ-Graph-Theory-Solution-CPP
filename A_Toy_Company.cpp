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
set<string>st;
map<string, ll>vis;
ll ans =-1;
string inp, out;

void bfs(string str, ll movv){
     vis[str]=1;
     queue<pair<string, ll>>q;
     q.push({str, movv});

    while(!q.empty()){ 
        string s = q.front().ff;
        ll mov = q.front().ss;
        q.pop();
        
        if(s == out){
          ans = mov;
          break;
        }

      for(int i=0; i<3; i++){
          string tem1 = s, tem2 = s;
           char ch1 = tem1[i], ch2=tem2[i];
           if(ch1=='z')ch1 = 'a';
           else ch1++;
       
           if(tem2[i]=='a') ch2='z';
           else ch2--;
           tem1[i]=ch1, tem2[i]=ch2;
          
           if(tem1==out || tem2==out){
              ans = mov+1;
              return;
           }
           else{
              if(!st.count(tem1) && vis[tem1]==0) {q.push({tem1, mov+1}); vis[tem1]=1;}
              if(!st.count(tem2) && vis[tem2]==0) {q.push({tem2, mov+1}); vis[tem2]=1;}
           }
      }
    }
     
}

void genString(string a, string b, string c){
     for(int i=0; i<a.size(); i++){
      for(int j=0; j<b.size(); j++){
        for(int k=0; k<c.size(); k++){
           string tem = "";
           tem+=a[i];
           tem+=b[j];
           tem+=c[k];
           st.insert(tem);
        }
      }
     }
}

void solve(int tc)
{
  vis.clear();
  st.clear();

  cout << "Case " << tc << ": ";
  cin >> inp >> out;
  ll n;
  cin >> n;
  while(n--){
     string a, b, c;
     cin >> a >> b >> c;
     genString(a, b, c);
  } 
     
  ans = -1;
  if(st.count(out) || st.count(inp)) cout << -1 << endl;
  else if(inp==out) cout << 0 << endl;
  else{
      bfs(inp, 0);
      cout << ans << endl;
  }
  
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
    check the constraints
    try *BFS from starting string string (inp)
    convert string into possible 6 ways
             *6 way means. string lenght is 3. so for each index 0,1,2
                                   we can change it to right or left
                                   that means, b->c or  a <- b
    if(it's not a restricted string , then push it into queue with mov+1)

    if(you get goal string(out) then return)
    and that mov is the answer.                                    
*/