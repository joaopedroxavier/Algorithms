#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=5e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ii st[4*N];
int n, m, v[N];
map<int, vector<int>> s;

void build(int p, int l, int r) {
  if(l == r) { st[p] = {v[l], 1}; return; }

  int m = (l+r)/2;
  build(2*p, l, m);
  build(2*p+1, m+1, r);

  ii p1 = st[2*p], p2 = st[2*p+1];

  st[p] = {0, 0};
  if(p1.first) {
    int num = upper_bound(s[p1.st].begin(), s[p1.st].end(), r) - lower_bound(s[p1.st].begin(), s[p1.st].end(), l);
    if(num > (r-l+1)/2) st[p] = {p1.first, num};
  }
  if(p2.first) {
    int num = upper_bound(s[p2.st].begin(), s[p2.st].end(), r) - lower_bound(s[p2.st].begin(), s[p2.st].end(), l);
    if(num > (r-l+1)/2) st[p] = {p2.first, num};
  }
}

ii query(int p, int l, int r, int i, int j) {
  if(l > j or r < i) return {0, 0};
  if(l >= i and r <= j) return st[p];

  int m = (l+r)/2;
  ii p1 = query(2*p, l, m, i, j), p2 = query(2*p+1, m+1, r, i, j);

  if(p1.first) {
    int num = upper_bound(s[p1.st].begin(), s[p1.st].end(), j) - lower_bound(s[p1.st].begin(), s[p1.st].end(), i);
    if(num > (j-i+1)/2) return {p1.first, num};
  }
  if(p2.first) {
    int num = upper_bound(s[p2.st].begin(), s[p2.st].end(), j) - lower_bound(s[p2.st].begin(), s[p2.st].end(), i);
    if(num > (j-i+1)/2) return {p2.first, num};
  }

  return {0, 0};
}

int main(){
  scanf("%d %d", &n, &m);

  for(int i=1; i<=n; i++) {
    scanf("%d", v+i);
    s[v[i]].pb(i);
  }
  build(1, 1, n);
  for(int i=0; i<m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    ii qry = query(1, 1, n, l, r);
    printf("%d\n", qry.first);
  }

	return 0;
}

