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

const int N = 1e6+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

int n, z[N];
vector<int> v;

void zf() {
  int l=0, r=0, n = v.size();
  for(int i=1; i<n; i++) {
    if(i <= r) z[i] = min(z[i-l], r-i+1);
    while(z[i] + i < n and v[z[i] + i] == v[z[i]]) z[i]++;
    if(r < i + z[i] - 1) l = i, r = i+z[i]-1;
  }
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    int u; scanf("%d", &u);
    v.push_back(u);
  }
  reverse(v.begin(), v.end());
  zf();

  pair<int, int> ans = {n-1, 1};
  for(int i=1; i<n; i++) {
    if(n - z[i] < ans.st + ans.nd) {
      ans = {n - z[i] - i, i};
    }
  }
  printf("%d %d\n", ans.st, ans.nd);
	return 0;
}

