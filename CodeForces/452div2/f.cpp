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

const long double EPS = 1e-9;
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

set<int> p[300];
int n, m, bit[N];

void update(int x, int p) {
  for(p+=2; p < N; p += p&-p) bit[p] += x;
}

int query(int p) {
  int ans = 0;
  for(p+=2; p; p -= p&-p) ans += bit[p];
  return ans;
}

int pos(int p) {
  int l = 1, r = n;
  while(l < r) {
    int m = (l+r)/2;
    if(m - query(m) < p) l = m+1;
    else r = m;
  }
  return l;
}
int main(){
  scanf("%d %d", &n, &m);

  for(int i=1; i<=n; i++) {
    char c;
    scanf(" %c", &c);
    p[(int)c].insert(i);
  }

  for(int i=0; i<m; i++) {
    int l, r;
    char c;
    scanf(" %d %d %c", &l, &r, &c);
    int ch = (int)c;

    l = pos(l), r = pos(r);
    auto pt = p[ch].lower_bound(l);
    while(pt != p[ch].end() and *pt <= r) {
      update(1, *pt);

      p[ch].erase(pt);
      pt = p[ch].lower_bound(l);
    }
  }

  bool print = true;
  while(print) {
    print = false;
    int mi = INF, c;
    for(int i=0; i<300; i++) {
      if(!p[i].empty()) {
        print = true;
        if(*p[i].begin() < mi) mi = *p[i].begin(), c = i;
      }
    }
    if(print) {
      printf("%c", (char)c);
      p[c].erase(p[c].begin());
    }
  }
  printf("\n");

	return 0;
}

