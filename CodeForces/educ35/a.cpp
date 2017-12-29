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
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

map<int, vector<int>> m;
int n;

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    int u;
    scanf("%d", &u);
    m[u].pb(i);
  }

  ll ans = INF, p = 0, last;
  for(auto i : m.begin()->second) {
    if(p) {
      ans = min(ans, i - last);
    }
    last = i;
    p++;
  }

  printf("%lld\n", ans);

  return 0;
}

