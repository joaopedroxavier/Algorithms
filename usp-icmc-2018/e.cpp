//
// 내가 나인 게 싫은 날
// 영영 사라지고 싶은 날
// 문을 하나 만들자 너의 맘 속에다
// 그 문을 열고 들어가면
// 이 곳이 기다릴 거야
// 믿어도 괜찮아 널 위로해줄 magic shop
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 450;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, p;
string t;

struct myset {
  int idx;
  bool vis;
  ll mx;
  multiset<ll> numb;

  bool operator<(myset s) const {
    if(mx != s.mx) return mx > s.mx;
    if(vis != s.vis) return vis < s.vis;
    return numb.size() < s.numb.size();
  }

  void fix_mx() { mx = *prev(numb.end()); }

  void step(ll x) {
    fix_mx();
    
    auto p = numb.find(mx);
    numb.erase(p);

    ll y = mx/2;
    if(mx <= 2*x + 1) x = y;
    numb.insert(x), numb.insert(mx-x-1);
    vis = true;
    fix_mx();
  }

  void step_half(ll x) {
    fix_mx();
    
    auto p = numb.find(mx);
    numb.erase(p);

    ll y = mx/2;
    x = y;
    numb.insert(x), numb.insert(mx-x-1);
    vis = true;
    fix_mx();
  }

  void fix() {
    if (numb.size() <= 1) return;
    ll ma = *prev(numb.end());
    ll mi = *(numb.begin());

    while(abs(ma-mi) > 1) {
      auto l = numb.find(mi);
      auto r = numb.find(ma);

      numb.erase(l);
      numb.erase(r);

      numb.insert(mi+1);
      numb.insert(ma-1);

      ma = *prev(numb.end());
      mi = *(numb.begin());
    }
  }
};

ll cost(ll m, multiset<myset> s, ll av, bool half) {
  for(int i=0; i<m; i++) {
    auto best = *s.begin();

    auto p = s.find(best);
    s.erase(p);

    if(half) best.step_half(av);
    else best.step(av);
    s.insert(best);
  }

  ll cost = 0;
  for(auto p : s) {
    p.fix();
    for(ll j : p.numb) cost += (j*(j+1))/2;
  }
  return cost;
}

bool check(ll m, multiset<myset> s) {
  ll sum = 0;
  for(auto i : s) sum += i.mx;

  if(sum <= m) { return true; }

  sum -= m;
  ll q = s.size() + m;

  ll av = sum / q;
  if(sum % q > q / 2) av++;

  if(sum < q) return sum <= p;

  return min(cost(m, s, av, 0), cost(m, s, av, 1)) <= p;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> p;
  cin >> t;

  multiset<myset> s;

  int cnt = 0;
  for(int i=0; i<n; i++) {
    if(t[i] == '0') {
      if(cnt) {
        multiset<ll> m; m.insert(cnt);
        myset ms = {i, 0, cnt, m};

        s.insert(ms);
      }
      cnt = 0;
    }
    else {
      cnt++;
    }
  }
  if(cnt) {
    multiset<ll> m; m.insert(cnt);
    myset ms = {n, 0, cnt, m};

    s.insert(ms);
  }

  for(int i=0; i<=n; i++) check(i, s);

  int l=0, r=n;
  while(l < r) {
    int m = (l+r)/2;
    if(check(m, s)) r = m;
    else l=m+1;
  }

  printf("%d\n", l);

  return 0;
}

