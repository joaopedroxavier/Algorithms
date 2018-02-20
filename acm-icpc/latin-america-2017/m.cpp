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
typedef pair<ll, ll> pll;

const long double EPS = 1e-9;
const int N=5e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int s[N];
int sinv[N], save[N];
int n, r, t, ra[N], sa[N], tra[N], tsa[N], c[N];
ll ans;

void count(int k) {
  int sum = 0, x = max(400, n); memset(c, 0, sizeof c);

  for(int i=0; i<n; i++) c[i+k<n ? ra[i+k] : 0]++;
  for(int i=0; i<x; i++) sum += c[i], c[i] = sum - c[i];
  for(int i=0; i<n; i++) tsa[c[sa[i]+k<n ? ra[sa[i]+k] : 0]++] = sa[i];
  for(int i=0; i<n; i++) sa[i] = tsa[i];
}

void suffixarray() {
  for(int i=0; i<n; i++) ra[i] = s[i], sa[i] = i;
  for(int k=1; k<n; k <<= 1) {
    count(k); count(0);
    tra[sa[0]] = r = 0;
    for(int i=1; i<n; i++) {
      tra[sa[i]] = (ra[sa[i]] == ra[sa[i-1]] and ra[sa[i]+k] == ra[sa[i-1]+k]) ? r : ++r;
    }
    for(int i=0; i<n; i++) ra[i] = tra[i];
    if (ra[sa[n-1]] == n-1) break;
  }
}

int main(){

  while(scanf("%d", &t) != EOF) {

    n = 0;
    for(int i=0; i<t; i++) {
      int k;
      scanf("%d", &k);
      save[i] = n;

      for(int j=0; j<k; j++) {
        int u;
        scanf("%d", &u);
        s[n++] = u;
      }

      s[n++] = 301;
    }

    suffixarray();
    for(int i=0; i<n; i++) sinv[sa[i]] = i;

    priority_queue<ii> pq;
    for(int i=0; i<t; i++) pq.push(mp(-sinv[save[i]], save[i]));

    ll ans = 0;
    while(!pq.empty()) {
      ii topzera = pq.top(); pq.pop();
      ans = (ans * 365 + s[topzera.second]) % MOD;

      if(s[topzera.second + 1] != 301) pq.push(mp(-sinv[topzera.second + 1], topzera.second + 1));
    }

    printf("%lld\n", (ans * 365) % MOD);
  }

	return 0;
}

