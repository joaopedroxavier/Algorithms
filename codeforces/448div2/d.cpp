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

string a, b;
ll f[N], finv[N], inv[N];
ll cnt[26];
ll fa, fb;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> a >> b;
  int n = a.size();

  f[0] = 1; finv[0] = 1; inv[1] = 1;
  f[1] = 1; finv[1] = 1;
  ll p = MOD;
  for(ll i=2; i<N; i++) {
    inv[i] = (p - (p/i) * inv[p%i]%p)%p;
    f[i] = (f[i-1] * i) % p;
    finv[i] = (finv[i-1] * inv[i]) % p;
  }

  for(char c : a) cnt[c - 'a']++;

  for(int i=0; i<n; i++) {
    ll term = f[n-i-1];
    ll sterm = 1;
    bool cont = cnt[b[i] - 'a'];
    for(char c = 'a'; c <= 'z'; c++) {
      sterm = (sterm * finv[cnt[c-'a']]) % p;
    }
    for(char c = 'a'; c < b[i]; c++) if(cnt[c-'a'] > 0) {
      sterm = (sterm * cnt[c-'a']) % p;
      fb = (fb + ((term * sterm) % p)) % p;
      sterm = (sterm * inv[cnt[c-'a']]) % p;
    }
    cnt[b[i] - 'a']--;
    if(!cont) break;
  }

  memset(cnt, 0, sizeof cnt);

  for(char c : a) cnt[c - 'a']++;

  for(int i=0; i<n; i++) {
    ll term = f[n-i-1];
    ll sterm = 1;
    bool cont = cnt[a[i] - 'a'];
    for(char c = 'a'; c <= 'z'; c++) {
      sterm = (sterm * finv[cnt[c-'a']]) % p;
    }
    for(char c = 'a'; c < a[i]; c++) if(cnt[c-'a'] > 0) {
      sterm = (sterm * cnt[c-'a']) % p;
      fa = (fa + (term * sterm) % p) % p;
      sterm = (sterm * inv[cnt[c-'a']]) % p;
    }
    cnt[a[i] - 'a']--;
    if(!cont) break;
  }

  printf("%lld\n", (fb - fa - 1 + MOD) % MOD);

  return 0;
}

