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
const int N=8e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int st[4*N], v[N];
int start[N], fin[N];

void build(int p, int l, int r) {
  if(l == r) { st[p] = v[l]; return; }

  int m = (l+r)/2;
  build(2*p, l, m);
  build(2*p+1, m+1, r);

  st[p] = min(st[2*p], st[2*p+1]);
}

int query(int p, int l, int r, int i, int j) {
  if(l > j or r < i) return INF;
  if(l >= i and r <= j) return st[p];

  int m = (l+r)/2;
  return min(query(2*p, l, m, i, j), query(2*p+1, m+1, r, i, j));
}

set<iii> s;
int n;

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    s.insert({{u,i}, 1});
    s.insert({{v,i}, -1});
  }

  int p=0;
  int last = INF;
  while(!s.empty()) {
    iii u = *s.begin();
    if(u.first.first > last + 1) p++;
    if(u.first.first != last) {
      if(u.second == 1) {
        start[u.first.second] = ++p; 
      }
      else fin[u.first.second] = ++p;
    }
    else {
      if(u.second == 1) start[u.first.second] = p; 
      else fin[u.first.second] = p;
    }
    last = u.first.first;
    s.erase(s.begin());
  }

  for(int i=0; i<n; i++) v[start[i]]++, v[fin[i]+1]--;
  for(int i=1; i<=p; i++) v[i] += v[i-1];

  build(1, 1, p+1);
  for(int i=0; i<n; i++) {
    if(query(1, 1, p+1, start[i], fin[i]) > 1) return printf("%d\n", i+1), 0;
  }

  printf("-1\n");

  return 0;
}

