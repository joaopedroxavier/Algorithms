#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define st first
#define nd second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n;
int ev[N], val[N];

int main(){
  scanf("%d", &n);

  for(int i=1; i<=n; i++) {
    scanf("%d", &ev[i]);
    if(ev[i] == 1 or ev[i] == 3) scanf("%d", &val[i]);
  }

  stack<int> spdlim;
  ll ans = 0, ov = 0, spd;
  for(int i=1; i<=n; i++) {
    if(ev[i] == 1) {
      while(!spdlim.empty() and val[i] > spdlim.top()){ ans++; spdlim.pop(); }
      spd = val[i];
    }
    if(ev[i] == 2) {
      ans += ov;
      ov = 0;
    }
    if(ev[i] == 3) {
      if(spd > val[i]){ ans++; }
      else spdlim.push(val[i]);
    }
    if(ev[i] == 4) {
      ov = 0;
    }
    if(ev[i] == 5) {
      while(!spdlim.empty()) spdlim.pop();
    }
    if(ev[i] == 6) {
      ov++;
    }
  }

  printf("%lld\n", ans);

  return 0;
}

