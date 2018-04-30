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

int disp[N];
int n, s;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%d %d", &n, &s);
  for(int i=0; i<n; i++) {
    int h, m; scanf("%d %d", &h, &m);
    int t = h*60 + m;
    for(int j=t; j<=t+s; j++) disp[j] = 1;
    for(int j=t; j>=max(0,t-s); j--) disp[j] = 1;
  }

  for(int i=0; i<N; i++) if(!disp[i]) {
    printf("%d %d\n", i/60, i%60);
    return 0;
  }
	return 0;
}

