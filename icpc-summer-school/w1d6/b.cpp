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
const int K=26;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

string s;
int n, r, ra[N], sa[N], tra[N], tsa[N], c[N];
ll ans;

void count(int k) {
  int sum = 0, x = max(300, n); 
  memset(c, 0, sizeof c);
  for(int i=0; i<n; i++) c[i+k<n ? ra[i+k] : 0]++;
  for(int i=0; i<x; i++) sum += c[i], c[i] = sum - c[i];
  for(int i=0; i<n; i++) tsa[c[sa[i]+k < n ? ra[sa[i]+k] : 0]++] = sa[i];
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
    if(ra[sa[n-1]] == n-1) break;
  }
}

int phi[N], lcp[N], plcp[N], ps[N];

void calclcp() {
  int l = 0;
  phi[sa[0]] = -1; plcp[sa[0]] = 0;
  for(int i=1; i<n; i++) phi[sa[i]] = sa[i-1];
  for(int i=0; i<n; i++) {
    if(phi[i] == -1) continue;
    while(s[i+l] == s[phi[i]+l]) l++;
    plcp[i] = l;
    l = max(l-1, 0);
  }
  for(int i=0; i<n; i++) lcp[i] = plcp[sa[i]];
  ps[0] = 0;
  for(int i=1; i<=n; i++) ps[i] = ps[i-1] + i;
}

void recover(int k) {
  for(int i=k; i<n; i++) printf("%c", s[i]);
  printf("\n");
}

int main(){
  cin >> s;
  s += "$";
  n = (int) s.size();

  suffixarray();
  calclcp();
  ll ans = 0;
  for(int i=0; i<n; i++) {
    ll term = ps[n-sa[i]-1] - ps[lcp[i]];
    ans += term;
  }

  printf("%lld\n", ans);
	return 0;
}

