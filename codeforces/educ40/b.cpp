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

string s;
int n, z[N];

void zf() {
  int l=0, r=0;
  for(int i=1; i<n; i++) {
    if(i <= r)
      z[i] = min(z[i-l], r-i+1);
    while(z[i] + i < n and s[z[i]+i] == s[z[i]])
      z[i]++;
    if(r < i+z[i]-1)
      l = i, r = i+z[i]-1;
  }
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> s;
  zf();


  int ans = INF;
  for(int i=1; i<n; i++) {
    if(z[i] >= i)
      ans = min(ans, n - i + 1);
  }
  ans = min(ans, n);

  cout << ans << endl;
	return 0;
}

