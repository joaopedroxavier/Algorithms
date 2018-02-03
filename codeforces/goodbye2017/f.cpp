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
const int N=3e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll n; 
vector<ll> r, g, b;
vector<ll> gr, gb;

int main(){
  scanf("%lld", &n);

  for(int i=0; i<n; i++) {
    ll p; char c;
    scanf("%lld %c ", &p, &c);
    if(c == 'G') g.pb(p);
    if(c == 'R') r.pb(p);
    if(c == 'B') b.pb(p);
  }

  ll ans = 0;
  if(r.empty() and b.empty()) {
    ans = g.back() - g[0];
  }

  else if(g.empty()){
    if(!r.empty()) ans += r.back() - r[0];
    if(!b.empty()) ans += b.back() - b[0];
  }

  else {
    for(int i=0; i < (int) g.size(); i++) {
      if(i == 0) {
        if(!r.empty() and r[0] < g[i]) ans += g[i] - r[0];
        if(!b.empty() and b[0] < g[i]) ans += g[i] - b[0];
      }
      else {
        ll mar = 0;
        ll mab = 0;

        if(!r.empty()) {
          auto lr = upper_bound(r.begin(), r.end(), g[i-1]);
          auto rr = upper_bound(r.begin(), r.end(), g[i]);

          for(auto it = lr; it < rr; it++) {
            mar = max(mar, (it == lr) ? (*it - g[i-1]) : (*it - *(it-1)));
          }
          if(*(rr-1) > g[i-1]) mar = max(mar, g[i] - *(rr-1));
        }

        if(!b.empty()) {
          auto lb = upper_bound(b.begin(), b.end(), g[i-1]);
          auto rb = upper_bound(b.begin(), b.end(), g[i]);

          for(auto it = lb; it < rb; it++) {
            mab = max(mab, (it == lb) ? (*it - g[i-1]) : (*it - *(it-1)));
          }
          if(*(rb-1) > g[i-1]) mab = max(mab, g[i] - *(rb-1));
        }

        if(mab and mar) {
          ans += min(2*(g[i] - g[i-1]), 3*(g[i] - g[i-1]) - mab - mar);
        }
        else if(!mar and mab) {
          ans += 2*(g[i] - g[i-1]) - mab;
        }
        else if(!mab and mar) {
          ans += 2*(g[i] - g[i-1]) - mar;
        }
        else {
          ans += g[i] - g[i-1];
        }
      }
    }

    if(!r.empty() and r.back() > g.back()) ans += (r.back() - g.back());
    if(!b.empty() and b.back() > g.back()) ans += (b.back() - g.back());

  }

  printf("%lld\n", ans);

  return 0;
}

