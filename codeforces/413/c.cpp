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

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

struct fountain {
  int p, b;
  bool operator<(fountain f) const { return p == f.p ? b < f.b : p < f.p; }
};

vector<fountain> c, d;
vector<int> mac, mad;
int n, coin, diam;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d %d", &n, &coin, &diam);
  for(int i=0; i<n; i++) {
    int b, p; char k; scanf(" %d %d %c", &b, &p, &k);
    if(k == 'D') {
      d.push_back({p, b});
    }
    else {
      c.push_back({p, b});
    }
  }

  sort(c.begin(), c.end());
  sort(d.begin(), d.end());

  if(!c.empty()) mac.push_back(c[0].b);
  for(int i=1; i<(int)c.size(); i++) {
    int ma = mac.back();
    mac.push_back(max(ma, c[i].b));
  }

  if(!d.empty()) mad.push_back(d[0].b);
  for(int i=1; i<(int)d.size(); i++) {
    int ma = mad.back();
    mad.push_back(max(ma, d[i].b));
  }

  int ans = 0;
  if(!c.empty() and !d.empty()) {
    fountain fc = {coin, INF};
    fountain fd = {diam, INF};
    int ct = upper_bound(c.begin(), c.end(), fc) - c.begin();
    int dt = upper_bound(d.begin(), d.end(), fd) - d.begin();
    ct--; dt--;
    if(ct >= 0 and coin >= c[ct].p and dt >= 0 and diam >= d[dt].p) {
      ans = max(ans, mac[ct] + mad[dt]);
    }
  }
  if(c.size() >= 2) {
    for(int i = 0; i < (int) c.size(); i++) if(coin >= c[i].p) {
      fountain f = {coin - c[i].p, INF};
      int ct = upper_bound(c.begin(), c.begin() + i, f) - c.begin();
      ct--;
      if(ct >= 0 and coin >= c[ct].p) {
        ans = max(ans, c[i].b + mac[ct]);
      }
    }
  }
  if(d.size() >= 2) {
    for(int i = 0; i < (int) d.size(); i++) if(diam >= d[i].p) {
      fountain f = {diam - d[i].p, INF};
      int dt = upper_bound(d.begin(), d.begin() + i, f) - d.begin();
      dt--;
      if(dt >= 0 and diam >= d[dt].p) {
        ans = max(ans, d[i].b + mad[dt]);
      }
    }
  }
  printf("%d\n", ans);

  return 0;
}

