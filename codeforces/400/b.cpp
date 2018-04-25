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

int sieve[N], n;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  for(int i=2; i<N; i++) if(!sieve[i]) {
    for(int j=2*i; j<N; j+=i) sieve[j]++;
  }

  scanf("%d", &n);
  int ans = 1;
  for(int i=1; i<=n; i++) if(sieve[i+1]) ans = 2;

  printf("%d\n", ans);
  for(int i=1; i<=n; i++) printf("%d ", sieve[i+1] ? 2 : 1);
  printf("\n");
	return 0;
}

