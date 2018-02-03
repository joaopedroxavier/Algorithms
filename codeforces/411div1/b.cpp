#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll p[N], ps[N];
char s[N];

int main(){
  scanf("%s", s);

  int n = strlen(s);

  ps[0] = 1;
  for(int i=1; i<N; i++) ps[i] = (ps[i-1] * 2) % MOD;
  for(int i=1; i<N; i++) ps[i] = (ps[i] + ps[i-1]) % MOD;

  ll ans = 0, carry = 0, i = 0;
  while(i < n) {
    if(s[i] == 'a') {
      while(s[i] == 'a' and i < n) carry++, i++;
    }
    else if(s[i] == 'b') {
      ll cb = 0;
      while(s[i] == 'b' and i < n) cb++, i++;
      ans = (ans + (cb * ps[carry-1]) % MOD) % MOD;
    }
  }

  printf("%lld\n", ans);

	return 0;
}

