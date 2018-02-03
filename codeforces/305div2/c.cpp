#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define y1 aoishdf

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll m;
ll h1, a1;
ll x1, y1;
ll h2, a2;
ll x2, y2;
ll clen1, clen2;
ll f2, dif, ans;
int vis1[N], vis2[N], vis[N];

bool check1(ll u) {
  if(u == a1) return true;
  if(vis1[u]) return false;
  vis1[u] = 1;

  ll nw = x1*u + y1;
  nw = nw % m;
  return check1(nw);
}

bool check2(ll u) {
  if(u == a2) return true;
  if(vis2[u]) return false;
  vis2[u] = 1;

  ll nw = x2*u + y2;
  nw = nw % m;
  return check2(nw);
}

void szlen1(ll u) {
  clen1++;
  if(u == a1) return;

  ll nw = x1*u + y1;
  nw = nw % m;
  szlen1(nw);
}

void szlen2(ll u) {
  clen2++;
  if(u == a2) return;

  ll nw = x2*u + y2;
  nw = nw % m;
  szlen2(nw);
}

bool finalcheck(ll u) {
  if(u == 0) return true;
  if(vis[u]) return false;
  vis[u] = 1;

  u = (u + dif) % clen2;
  ans = ans + clen1;
  return finalcheck(u);
}

int main(){
  scanf("%lld", &m);
  scanf("%lld %lld", &h1, &a1);
  scanf("%lld %lld", &x1, &y1);
  scanf("%lld %lld", &h2, &a2);
  scanf("%lld %lld", &x2, &y2);

  if(!check1(h1) or !check2(h2)) return printf("-1\n"), 0;

  ll p1 = (x1*a1 + y1) % m;
  ll p2 = (x2*a2 + y2) % m;

  memset(vis1, 0, sizeof vis1);
  memset(vis2, 0, sizeof vis2);

  if(!check1(p1)) {
    p1 = h1, p2 = h2;
    while(p1 != a1) {
      p1 = (x1*p1 + y1) % m;
      p2 = (x2*p2 + y2) % m;
      ans++;
    }

    if(p2 == a2) return printf("%lld\n", ans), 0;   
    return printf("-1\n"), 0;
  }

  if(!check2(p2)) {
    p1 = h1, p2 = h2;
    while(p2 != a2) {
      p1 = (x1*p1 + y1) % m;
      p2 = (x2*p2 + y2) % m;
      ans++;
    }

    if(p1 == a1) return printf("%lld\n", ans), 0;   
    return printf("-1\n"), 0;
  }

  szlen1(p1), szlen2(p2);

  p1 = h1, p2 = h2;
  bool passed2 = false;;
  while(p1 != a1 or !passed2) {
    p1 = (x1*p1 + y1) % m;
    p2 = (x2*p2 + y2) % m;
    if(passed2) f2 = (f2 + 1) % clen2;
    if(p2 == a2) passed2 = true, f2 = 0;
    ans++;
  }

  if(p2 == a2) return printf("%lld\n", ans), 0;

  dif = clen1 % clen2;
  printf("%lld\n", finalcheck(f2) ? ans : -1);

  return 0;
}

