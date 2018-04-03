#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 2e6+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, sieve[N];
int st[4*N];

vector<int> fact(int n) {
  vector<int> ans;
  for(int i=2; i*i <= n; i++) {
    bool put = false;
    while(n % i == 0) {
      n /= i;
      put = 1;
    }
    if(put) ans.push_back(i);
  }

  if(n > 1) ans.push_back(n);
  return ans;
}

void build(int p, int l, int r) {
  if(l == r) { st[p] = l; return; }

  int m = (l+r)/2;
  build(2*p, l, m);
  build(2*p+1, m+1, r);

  st[p] = min(st[2*p], st[2*p+1]);
}

void disable(int p, int l, int r, int x) {
  if(l == r) { st[p] = INF; return; }

  int m = (l+r)/2;
  if(x > m) disable(2*p+1, m+1, r, x);
  else disable(2*p, l, m, x);

  st[p] = min(st[2*p], st[2*p+1]);
}

int query(int p, int l, int r, int i, int j) {
  if(l > j or r < i) return INF;
  if(l >= i and r <= j) return st[p];

  int m = (l+r)/2;
  return min(query(2*p, l, m, i, j),
             query(2*p+1, m+1, r, i, j));
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  build(1, 1, N-1);
  bool liberougeral = false;

  for(int i=0; i<n; i++) {
    int u; scanf("%d", &u);
    int p = liberougeral ? query(1, 1, N-1, 2, N-1) : query(1, 1, N-1, u, N-1);
    printf("%d ", p);
    if(p != u) liberougeral = true;

    vector<int> f = fact(p);
    for(int q : f) if(!sieve[q]) {
      for(int j=q; j<N; j+=q) {
        sieve[j] = 1; disable(1, 1, N-1, j);
      }
    }
  }
  printf("\n");
	return 0;
}

