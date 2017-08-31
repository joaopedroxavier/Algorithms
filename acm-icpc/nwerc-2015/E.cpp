#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e4+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int x, n, vis[N], ans;
map<ll, ll> par, fwrd;
pair<int, int> p[N];
vector<ll> adj[N];

bool match(ll u){
  if(vis[u] == x) return 0;
  vis[u] = x;
  for(ll v : adj[u]) if(!par[v] or match(par[v])){
    par[v] = u, fwrd[u] = v;
    return par[v];
  }
  return 0;
}

int main(){
  scanf("%d", &n);
  for(int i=1;i<=n;i++){
    ll u, v;
    scanf("%lld %lld", &u, &v);
    p[i] = mp(u, v);
    adj[i].pb(u+v), adj[i].pb(u-v), adj[i].pb(u*v);
  }
  for(int i=1;i<=n;i++) x++, ans += match(i);
  if(ans < n) return printf("impossible\n"), 0;
  for(auto it : fwrd){
    ll u = p[it.first].first, v = p[it.first].second;
    ll a = it.second;
    char c;
    if(a == u + v) c = '+';
    if(a == u - v) c = '-';
    if(a == u * v) c = '*';
    printf("%lld %c %lld = %lld\n", u, c, v, a);
  }
	return 0;
}

