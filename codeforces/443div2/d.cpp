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
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll n, k, m;
ll ans, rem[2];
vector<ll> v, s;

int main(){
  scanf("%lld %lld %lld\n", &n, &k, &m);
  for(int i=0; i<n; i++) {
    ll u;
    scanf("%lld", &u);

    if(!v.empty() and v.back() == u) s.back()++;
    else {
      v.pb(u);
      s.pb(1);
    }
    while(!s.empty() and s.back() >= k) {
      s.back() -= k;
      ans += m*k;
      if(s.back() == 0) s.pop_back(), v.pop_back();
    }
  }

  vector<ll> sbckp = s;
  vector<ll> vbckp = v;
  int p1=0, p2=v.size()-1;
  while(p1 < p2 and v[p1] == v[p2] and s[p1] + s[p2] >= k) {
    while(s[p1] + s[p2] >= k) {
      ans += k*(m-1);
      ll d = min(s[p1], k);
      s[p1] -= d;
      s[p2] -= k-d;
    }
    if(s[p1] == 0) p1++;
    if(s[p2] == 0) p2--;
  }

  if(p1 == p2) {
    ans += k*((m*s[p1])/k);
    if((m*s[p1]) % k == 0) {
      v.clear(); s.clear();
      for(int i=0; i<(int)vbckp.size(); i++) if(i != p1) v.pb(vbckp[i]), s.pb(sbckp[i]);

      stack<ll> vst, sst;
      for(int i=0; i<(int)v.size(); i++) {
        if(!vst.empty() and vst.top() == v[i]) sst.top()+=s[i];
        else {
          vst.push(v[i]);
          sst.push(s[i]);
        }
        while(!sst.empty() and sst.top() >= k) {
          sst.top() -= k;
          ans += k;
          if(sst.top() == 0) sst.pop(), vst.pop();
        }
      }
    }
  }

  printf("%lld\n", n*m - ans);

  return 0;
}

