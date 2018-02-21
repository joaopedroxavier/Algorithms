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
typedef pair<ii, int> iii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

set<iii> ranges;
ll l, c, n;
ll f[N];

bool inside(iii a, iii b) {
  return a.first.first >= b.first.first and a.first.second <= b.first.second;
}

bool can_merge(iii a, iii b) { 
  if(a.second != b.second) return false; 

  return (a.first.second >= b.first.first) or (b.first.second >= a.first.first);
}

iii merged(iii a, iii b) {
  if(!can_merge(a,b)) return {{0, 0}, 0};

  return {{min(a.first.first, b.first.first), max(a.first.second, b.first.second)}, a.second};
}

iii cutr(iii a, iii b) { return {{max(a.first.first, b.first.second), a.second}, a.second}; }
iii cutl(iii a, iii b) { return {{a.first.first, min(b.first.first, a.first.second)}, a.second}; }

void add(int i, int j, int x) {
  auto it = ranges.lower_bound(mp(mp(i,j),x));
  auto jt = it;

  auto p = mp(mp(i,j), x);
  vector<iii> er, in;
  in.push_back(mp(mp(i,j), x));

  while(jt != ranges.end() and inside(*jt, p)) er.push_back(*jt), jt++;
  if(jt != ranges.end()) er.push_back(*jt), in.push_back(cutr(*jt, p));

  jt = it;
  if(jt != ranges.begin()) {
    jt--;
    er.push_back(*jt), in.push_back(cutl(*jt, p));
  }

  for(auto i : er) {
    ranges.erase(i);
    f[i.second] -= (i.first.second - i.first.first + 1);
  }
  for(auto i : in) {
    ranges.insert(i);
    f[i.second] += (i.first.second - i.first.first + 1);
  }
}

int main(){

  while(scanf("%lld %lld %lld", &l, &c, &n) != EOF) {
    ranges.clear();
    memset(f, 0, sizeof f);
    ranges.insert(mp(mp(0, l-1), 1));
    f[1] = l;

    for(int i=0; i<n; i++) {
      ll p, x, a, b;
      scanf("%lld %lld %lld %lld", &p, &x, &a, &b);
      ll s = f[p];
      ll m1 = (a + s*s) % l, m2 = (a + (s+b)*(s+b)) % l;

      if(m1 > m2) swap(m1, m2);
      printf("adding %lld %lld\n", m1, m2);
      add(m1, m2, x);

      for(auto it : ranges) {
        printf("%d %d\n", it.first.first, it.first.second);
      }
      printf("\n");
    }

    ll ans = 0;
    for(int i=0; i<c; i++) ans = max(ans, f[i]);
    printf("%lld\n", ans);

  }

	return 0;
}

