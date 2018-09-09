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
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ull P = 2003;

int t, n, cnt;
map<ull, ll> m;
ull p[N];
map<ii, int> val;
int id[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &t);
  p[0] = 1;
  for(int i=1; i<N; i++) p[i] = P * p[i-1];

  while(t--) {
    m.clear();
    val.clear();
    cnt = 0;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
      int u, v; scanf("%d %d", &u, &v);
      if(u > v) swap(u, v);

      if(!val.count({u,v})) val[mp(u,v)] = cnt++;
      id[i] = val[mp(u,v)];
    }

    for(int i=0; i<n; i++) {
      ull hsh = 0;
      for(int j=i; j<n; j++) {
        hsh += p[id[j]];
        m[hsh]++;
      }
    }

    ll ans = 0;
    for(auto p : m) {
      ans += (p.nd * (p.nd - 1)) / 2;
    }

    printf("%lld\n", ans);
  }
	return 0;
}

