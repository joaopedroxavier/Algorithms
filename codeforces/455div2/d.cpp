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

char s[N];
int n, l[N], r[N];
set<int> rm;

char atpos(int i) { return s[i-1]; }

bool check(int i) {
  if(i == 0 or i == n+1) return false;
  if(l[i] and r[i] <= n) {
    return atpos(l[i]) != atpos(i) or atpos(r[i]) != atpos(i);
  }
  else if(l[i]) {
    return atpos(l[i]) != atpos(i);
  }
  else if(r[i] <= n) {
    return atpos(r[i]) != atpos(i);
  }
  return false;
}

int main(){
  scanf("%s", s);
  n = strlen(s);
  for(int i=1; i <= n; i++) {
    l[i] = i-1; r[i] = i+1;
    if(check(i)) {
      rm.insert(i);
    }
  }

  ll ans = 0;
  while(!rm.empty()) {
    ans++;
    set<int> step = rm;
    rm.clear();
    for(auto i : step) {
      if(l[i]) r[l[i]] = r[i];
      if(r[i] <= n) l[r[i]] = l[i];

      if(check(l[i])) rm.insert(l[i]);
      else {
        if(rm.count(l[i])) rm.erase(l[i]);
      }

      if(check(r[i])) rm.insert(r[i]);
      else {
        if(rm.count(r[i])) rm.erase(r[i]);
      }
    }
    for(auto i : step) if(rm.count(i)) rm.erase(i);
  }

  printf("%lld\n", ans);

	return 0;
}

