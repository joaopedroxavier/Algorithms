#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n;
set<ll> a;
ll lim, k;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %lld", &n, &k);
  for(int i=0; i<n; i++) {
    ll u; scanf("%lld", &u);
    a.insert(u);
  }

  lim = k * 2;
  int ans = 0;
  while(!a.empty()) {
    vector<ll> er;
    for(auto it : a) {
      if(it <= lim) {
        er.push_back(it);
      }
    }
    if(er.empty()) {
      ans++;
      lim *= 2;
    }
    else {
      lim = max(lim, er.back() * 2);
      for(int i : er) a.erase(i);
    }
  }

  printf("%d\n", ans);

	return 0;
}

