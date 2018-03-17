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

int n, h[N], t;

bool cmp(int i, int j) {
  return (t % h[i]) < (t % h[j]);
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d", &n);
  for(int i=0; i<n; i++) scanf("%d", &h[i]);
  scanf("%d", &t);

  int best = 0;
  for(int i=0; i<n; i++) {
    if(cmp(i, best)) best = i;
  }

  printf("%d\n", h[best]);
	return 0;
}

