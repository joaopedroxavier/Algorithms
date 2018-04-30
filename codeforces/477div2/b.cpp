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

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

ll n, a, b, s[N], ord[N];
ll sum;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld %lld %lld", &n, &a, &b);

  for(int i=0; i<n; i++) {
    scanf("%lld", &s[i]);
    ord[i] = i;
    sum += s[i];
  }

  sort(ord, ord+n, [](int i, int j) { return s[i] > s[j]; });

  int p = 0, ans = 0;
  while((s[0] * a) / sum < b) {
    if(ord[p] == 0) p++;
    sum -= s[ord[p]];
    ans++;
    p++;
  }

  printf("%d\n", ans);
	return 0;
}

