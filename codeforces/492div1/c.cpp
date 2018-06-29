//
// Elohim Essaim, Elohim Essaim, I implore you...
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

struct point {
  ll x, y;

  point() : x(0), y(0) {}
  point(ll x, ll y) : x(x), y(y) {}

  point operator+(point p) const { return point(x+p.x, y+p.y); }
  point operator-(point p) const { return point(x-p.x, y-p.y); }
  
  ll operator~() const { return x*x + y*y; }
};

int n, ans[N], par[N];
point res[N];
vector<int> myset[N];

int find (int a) { return par[a] == a ? a : par[a] = find(par[a]); }

int unite(int a, int b, int op) {
  a = find(a); b = find(b);
  if(myset[a].size() <= myset[b].size()) {
    for(int j : myset[a]) {
      if(op == 1) myset[b].push_back(j);
      else myset[b].push_back(-j);
    }
    par[a] = b;
    if(op == 1) res[b] = res[b] + res[a];
    else res[b] = res[b] - res[a];
    return b;
  }
  else {
    for(int j : myset[b]) {
      if(op == 1) myset[a].push_back(j);
      else myset[a].push_back(-j);
    }
    par[b] = a;
    if(op == 1) res[a] = res[a] + res[b];
    else res[a] = res[a] - res[b];
    return a;
  }
}

void proceed(int &a, int &b, int &c) {
  if(~(res[a]+res[b]) <= 1e12) {
    a = unite(a,b,1); b = c;
    return;
  }

  if(~(res[a]-res[b]) <= 1e12) {
    a = unite(a,b,-1); b = c;
    return;
  }

  if(~(res[a]+res[c]) <= 1e12) {
    a = unite(a,c,1);
    return;
  }

  if(~(res[a]-res[c]) <= 1e12) {
    a = unite(a,c,-1);
    return;
  }

  if(~(res[c]+res[b]) <= 1e12) {
    int aux = a;
    a = unite(c,b,1); b = aux;
    return;
  }

  if(~(res[c]-res[b]) <= 1e12) {
    int aux = a;
    a = unite(c,b,-1); b = aux;
    return;
  }
}

vector<int> v;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    ll x, y; scanf("%lld %lld", &x, &y);
    v.push_back(i);
    res[i] = point(x,y);
    par[i] = i;
    myset[i].push_back(i);
  }

  while(v.size() > 2) {
    int a = v.back(); v.pop_back();
    int b = v.back(); v.pop_back();
    int c = v.back(); v.pop_back();

    proceed(a, b, c);
    v.push_back(b);
    v.push_back(a);
  }

  if(v.size() == 2) {
    int a = v.back(); v.pop_back();
    int b = v.back(); v.pop_back();

    a = find(a); b = find(b);

    if(~(res[a]+res[b]) <= 225e10) {
      unite(a, b, 1);
    }
    else {
      unite(a, b, -1);
    }
  }

  if(v.size() == 1) return printf("1\n"), 0; 

  vector<int> answer = myset[find(1)];
  sort(answer.begin(), answer.end(), [](int a, int b) { return abs(a) < abs(b); });
  for(int i : answer) printf("%d ", i/abs(i));
  printf("\n");

  return 0;
}

