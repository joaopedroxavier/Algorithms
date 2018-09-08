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

struct pref {
  int t, idx;
  set<ll> numb;

  bool operator<(pref p) const { 
    if(t != p.t) return t  < p.t;
    else return numb.size() == p.numb.size() ? idx < p.idx : numb.size() < p.numb.size();
  }
};

int n;
pref p[N], cur;

void intersect(int i) {
  set<ll> newcur;
  if(p[i].numb.size() < cur.numb.size()) {
    for(ll j : p[i].numb) if(cur.numb.count(j)) {
      newcur.insert(j);
    }
    cur.numb = newcur;
  }
  else {
    for(ll j : cur.numb) if(p[i].numb.count(j)) {
      newcur.insert(j);
    }
    cur.numb = newcur;
  }
}

void unite(int i) {
  for(ll j : p[i].numb) cur.numb.insert(j);
}

void remove(int i) {
  if(p[i].numb.size() < cur.numb.size()) {
    for(ll j : p[i].numb) if(cur.numb.count(j)) {
      cur.numb.erase(j);
    }
  }
  else {
    for(ll j : cur.numb) if(p[i].numb.count(j)) {
      cur.numb.erase(j);
    }
  }
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    int t; scanf("%d %d", &p[i].t, &t);

    for(int j=0; j<t; j++) {
      ll u; scanf("%lld", &u);
      p[i].numb.insert(u);
    }

    p[i].idx = i;
  }

  sort(p, p+n);

  if(p[0].t == 2) {
    cur = p[0];
    for(int i=1; i<n; i++) unite(i);

    ll curs = (ll) 1e18 - cur.numb.size();
    printf("%lld\n", curs);
  }
  else {
    cur = p[0];
    for(int i=1; i<n; i++) {
      if(p[i].t == 1) intersect(i);
      else remove(i);
    }
    printf("%d\n", (int) cur.numb.size());
  }
	return 0;
}

