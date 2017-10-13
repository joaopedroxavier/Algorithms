#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const int N = 1e5+5;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n; ll ans = 0;
    scanf("%d", &n);
    vector<ll> v(n); vector<pll> lefts;

    for(int i=0;i<n;i++) scanf("%lld", &v[i]);

    for(int i=0;i<n;i++){
      lefts.pb(mp(0, i));

      int sz = (int) lefts.size();
      for(int j=0;j<sz;j++){
        lefts[j].st = gcd(lefts[j].st, v[i]);
      }

      //printf("%d: \n", i);

      vector<pll> w;
      w.pb(lefts[0]);
      for(int j=1;j<sz;j++) if(lefts[j].st != lefts[j-1].st){
        w.pb(lefts[j]);
      }

      lefts = w;

      //for(pll p : lefts) printf("\t%lld: %lld\n", p.nd, p.st);

      for(pll p : lefts)  ans = max(ans, (i - p.nd + 1) * p.st);
    }
    printf("%lld\n", ans);
    
  }
  return 0;
}
