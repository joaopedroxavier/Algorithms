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

const long double EPS = 1e-9;
const int N=3e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, q;
ll h[N];

void check(int i, int j) {
  if(j-i < 2) { printf("-1\n"); return; }

  vector<pair<ll, int>> v;
  for(int k=i; k<=min(i+80, j); k++) {
    v.pb({h[k], k});
  }

  sort(v.begin(), v.end());
  for(int k = 1; k < (int) v.size() - 1; k++) {
    auto l1 = v[k-1];
    auto l2 = v[k];
    auto l3 = v[k+1];

    if(l3.st < l1.st + l2.st) { printf("%d %d %d\n", l1.nd, l2.nd, l3.nd); return; }
  }

  printf("-1\n");
}

int main(){
  scanf("%d %d", &n, &q);
  for(int i=1; i<=n; i++) scanf("%lld", &h[i]);

  for(int i=0; i<q; i++) {
    int u, v;
    scanf("%d %d", &u, &v);

    check(u, v);
  }

	return 0;
}

