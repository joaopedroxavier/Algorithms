#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define f first
#define s second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ll, ll> pll;

const long double EPS = 1e-9;
const int N=2e5+5;
const int MOD=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f;

vector<pair<pll, pll> > q;
ll best[N];
ll n, x, ans = INF;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n >> x;
  for(int i=0;i<n;++i){
    int u, v, w;
    cin >> u >> v >> w;
    q.pb(mp(mp(u,-1),mp(v,w)));
    q.pb(mp(mp(v,1),mp(u,w)));
  }
  sort(q.begin(), q.end());
  for(int i=0;i<N;++i) best[i] = INF;

  for(pair<pll,pll> p : q){
    if(p.f.s == -1 and p.s.f - p.f.f + 1 <= x){
      ans = min(ans, p.s.s + best[x - (p.s.f - p.f.f + 1)]);
    }
    if(p.f.s == 1){
      best[p.f.f - p.s.f + 1] = min(best[p.f.f - p.s.f + 1], p.s.s);
    }
  }

  cout << ((ans >= INF) ? -1 : ans) << endl;

	return 0;
}

