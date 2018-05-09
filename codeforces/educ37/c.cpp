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

const int N = 2e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

string s;
int n;
int l[N], r[N], a[N];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(int i=1; i<=n; i++) {
    int u; cin >> u;
    a[i] = u;
  }
  cin >> s;

  int last = 0;
  for(int i=1; i<=n; i++) {
    l[i] = last+1;
    if(s[i-1] == '0') {
      last = i;
    }
  }

  last = n;
  for(int i=n; i>0; i--) {
    if(s[i-1] == '0') {
      last = i;
    }
    r[i] = last;
  }

  /*
  for(int i=1; i<=n; i++) {
    printf("%d ", l[i]);
  }
  printf("\n");

  for(int i=1; i<=n; i++) {
    printf("%d ", r[i]);
  }
  printf("\n");
  */

  bool ans = true;
  for(int i=1; i<=n; i++) {
    if(a[i] == i) continue;
    if(a[i] < i) {
      ans = ans and (l[i] <= a[i]);
    }
    else if(a[i] > i) {
      ans = ans and (r[i] >= a[i]);
    }
  }

  printf("%s\n", ans ? "YES" : "NO");
	return 0;
}

