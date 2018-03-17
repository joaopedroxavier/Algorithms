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

map<int, ld> code;
int n;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  code[0] = 2;
  code[1] = 1;
  code[2] = 0.5;
  code[4] = 0.25;
  code[8] = 0.125;
  code[16] = code[8] / 2;

  scanf("%d", &n);

  ld ans = 0;
  for(int i=0; i<n; i++) {
    int u; scanf("%d", &u);

    ans += code[u];
  }

  printf("%.12Lf\n", ans);
	return 0;
}

