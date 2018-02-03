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
const ll P=10;

ll n, h[N];
char s[N];

void buildhash() {
  ll p = 1;
  for(int i=n-1; i>=0; i--) {
    ll term = (p * (s[i] - '0')) % MOD;
    h[i] = (h[i+1] + term) % MOD;
    p = (p * P) % MOD;
  }
}

ll fexp(ll b, ll e) {
  ll ans = 1;
  while(e) {
    if(e&1) ans = (ans * b) % MOD;
    b = (b * b) % MOD;
    e /= 2;
  }
  return ans;
}

bool check(int i, int j) {
  if((s[i+1] == '0' and j-i != 1) or (s[j+1] == '0' and n-1-j != 1) or (s[0] == '0' and i != 0)) return false;

  ll term1 = (h[0] - h[i+1] + MOD) % MOD;
  ll term2 = (h[i+1] - h[j+1] + MOD) % MOD;
  ll term3 = (h[j+1]) % MOD;

  term1 = (term1 * fexp(P, MOD-1-(n-(i+1)))) % MOD;
  term2 = (term2 * fexp(P, MOD-1-(n-(j+1)))) % MOD;

  return term3 == ((term1 + term2)) % MOD;
}

void getans(int i, int j) {
  for(int k=0; k<=i; k++) printf("%c", s[k]);
  printf("+");
  for(int k=i+1; k<=j; k++) printf("%c", s[k]);
  printf("=");
  for(int k=j+1; k<n; k++) printf("%c", s[k]);
  printf("\n");
}

int main(){
  scanf("%s", s);

  n = strlen(s);
  buildhash();

  for(int j=n-2; j>=0; j--) {
    int len3 = n - j - 1;
    int len1, len2;
    
    len1 = len3, len2 = n-len1-len3;
    if(len1 > 0 and len2 > 0 and len3 >= max(len1, len2)) {
      if(check(len1-1, j)) {
        getans(len1-1, j);
        return 0;
      }
    }
    len1 = len3-1, len2 = n-len1-len3;
    if(len1 > 0 and len2 > 0 and len3 >= max(len1, len2)) {
      if(check(len1-1, j)) {
        getans(len1-1, j);
        return 0;
      }
    }
    len2 = len3, len1 = n-len2-len3;
    if(len1 > 0 and len2 > 0 and len3 >= max(len1, len2)) {
      if(check(len1-1, j)) {
        getans(len1-1, j);
        return 0;
      }
    }
    len2 = len3-1, len1 = n-len2-len3;
    if(len1 > 0 and len2 > 0 and len3 >= max(len1, len2)) {
      if(check(len1-1, j)) {
        getans(len1-1, j);
        return 0;
      }
    }
  }

	return 0;
}

