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
typedef pair<pair<ll, ll>, ll> plll;

const long double EPS = 1e-9;
const int N=3e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, t;
ll bit[N], ord[N];
map<ii, int> idx;
vector<int> cc;
vector<plll> guest;

void add(int i, ll x) {
  for(i+=2; i<N; i+=i&-i) bit[i] = max(bit[i], x);
}

ll query(int i) {
  ll ans = 0;
  for(i+=2; i; i-=i&-i) ans = max(ans, bit[i]);
  return ans;
}

ll b(int i) { return guest[i].first.first; }
ll f(int i) { return guest[i].first.second; }
ll d(int i) { return guest[i].second; }

int main(){

  while(scanf("%d", &n) != EOF) {
    memset(bit, 0, sizeof bit);
    memset(ord, 0, sizeof ord);
    guest.clear();
    cc.clear();
    idx.clear();
    t=0;

    for(int i=0; i<n; i++) {
      ll u, v, w;
      scanf("%lld %lld %lld", &u, &v, &w);

      if(idx.count(mp(u,v))) guest[idx[mp(u,v)]].second += w;
      else { idx[mp(u,v)] = t++; guest.pb(mp(mp(u,v), w)); cc.pb(u); }

      ord[i] = i;
    }

    sort(cc.begin(), cc.end());
    unique(cc.begin(), cc.end());

    for(int i=0; i<t; i++) {
      guest[i].first.first = lower_bound(cc.begin(), cc.end(), b(i)) - cc.begin() + 1;
    }

    sort(ord, ord+guest.size(), [](int i, int j){ return f(i) == f(j) ? b(i) > b(j) : f(i) < f(j); });

    ll ans = 0;

    for(int i=0; i<(int)guest.size(); i++) {
      ans = max(ans, query(b(ord[i]) - 1) + d(ord[i]));
      //printf("%lld: %lld %lld %lld, %lld %lld\n", ord[i], f(ord[i]), b(ord[i]), d(ord[i]), query(b(ord[i]) - 1), ans);
      add(b(ord[i]), query(b(ord[i]) - 1) + d(ord[i]));
    }

    printf("%lld\n", ans);
  }

  return 0;
}

