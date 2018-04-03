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

int n, k, m, c[N];
map<string, int> st;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);
  
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k >> m;
  for(int i=1; i<=n; i++) {
    string s; cin >> s;
    st[s] = i;
  }

  for(int i=1; i<=n; i++) cin >> c[i];

  for(int i=0; i<k; i++) {
    int t; cin >> t;
    int mi = INF;
    vector<int> v;

    for(int j=0; j<t; j++) {
      int u; cin >> u;
      v.pb(u); mi = min(mi, c[u]);
    }

    for(int i : v) c[i] = mi;
  }

  ll ans = 0;
  for(int i=0; i<m; i++) {
    string s; cin >> s;
    ans += c[st[s]];
  }

  cout << ans << endl;

	return 0;
}

