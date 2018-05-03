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

ll v[14];
ll cp[14];

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  for(int i=0; i<14; i++) {
    scanf("%lld", &v[i]);
  }

  ll ans = 0;
  for(int i=0; i<14; i++) if(v[i]) {
    for(int j=0; j<14; j++) cp[j] = v[j];

    ll val = v[i];
    cp[i] = 0;
    for(int j=0; j<14; j++) cp[j] += val/14;
    val = val % 14;
    for(int j=1; j<=val; j++) {
      cp[(i+j)%14]++;
    }
    
    ll sum = 0;
    for(int j=0; j<14; j++) if(cp[j] % 2 == 0) sum += cp[j];
    ans = max(ans, sum);
  }

  printf("%lld\n", ans);
	return 0;
}

