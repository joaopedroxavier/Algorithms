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

int bad[] = {4, 16, 37, 58, 89, 145, 42, 20};
ll n;

bool check_bad(ll n) {
  for(int i=0; i<8; i++) if(bad[i] == n) return true;
  return false;
}

ll f(ll n) {
  ll ans = 0;
  while(n) {
    ans += (n%10) * (n%10);
    n /= 10;
  }
  return ans;
}

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  scanf("%lld", &n);
  while(n != 1) {
    if(check_bad(n)) return printf("UNHAPPY\n"), 0;
    n = f(n);
  }
  printf("HAPPY\n");
	return 0;
}

