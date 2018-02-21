#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define st first
#define nd second

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

iii cutr(iii a, iii b) { return {{max(a.first.first, b.first.second), a.second}, a.second}; }
iii cutl(iii a, iii b) { return {{a.first.first, min(b.first.first, a.first.second)}, a.second}; }

void add(int i, int j, int x) {
  auto it = ranges.lower_bound(mp(mp(i-1,0),0));
  if(it != ranges.begin()) it--;

  vector<iii> er, in;
  in.push_back(mp(mp(i, j), x));

  while(it != ranges.end()) {
    int lft = (*it).st.st;
    int rgt = (*it).st.nd;
    int val = (*it).nd;

    iii p = *it; it++;

    if(lft > j) break;
    if(rgt < i) continue;

    er.push_back(p);
    if(lft >= i and rgt > j) in.push_back(mp(mp(j+1, rgt), val));
    if(lft < i and rgt <= j) in.push_back(mp(mp(lft, i-1), val));
    if(lft < i and rgt > j) {
      in.push_back(mp(mp(lft, i-1), val));
      in.push_back(mp(mp(j+1, rgt), val));
    }
  }

  for(auto i : er) {
    ranges.erase(i);
    f[i.nd] -= (i.st.nd - i.st.st + 1);
  }

  for(auto i : in) {
    ranges.insert(i);
    f[i.nd] += (i.st.nd - i.st.st + 1);
  }
}

int main(){

  scanf("%lld %lld %lld", &l, &c, &n);
  f[1] = l;
  ranges.insert(mp(mp(0,l-1), 1));

  for(int i=0; i<n; i++) {
    ll p, x, a, b;
    scanf("%lld %lld %lld %lld", &p, &x, &a, &b);
    ll s = f[p];
    ll m1 = (a + s*s) % l;
    ll m2 = (a + (s+b)*(s+b)) % l;

    if(m1 > m2) swap(m1, m2);
    add(m1, m2, x);
  }

  ll ans = 0;
  for(int i=1; i<=c; i++) ans = max(ans, f[i]);
  printf("%lld\n", ans);


  return 0;
}

