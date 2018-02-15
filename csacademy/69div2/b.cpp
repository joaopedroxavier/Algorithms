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

vector<int> v;
ll n;

bool increasing() {
  int i=-1;
  bool ans = true;;
  for(int u : v) {
    ans = ans and (u >= i);
    i = u;
  }
  return ans;
}

ll countidx() {
  ll cnt = 0, last = v[0];
  ll ans = 0;
  for(int u : v) {
    if(u == last) cnt++;
    else last = u, ans += (cnt*(cnt+1))/2, cnt = 1;
  }
  ans += (cnt*(cnt+1))/2;
  return ans;
}

int main(){
  scanf("%lld", &n);

  for(int i=0; i<n; i++) {
    int u;
    scanf("%d", &u);
    v.pb(u);
  }

  if(increasing()) return printf("%lld\n1 1\n", countidx()), 0;

  int l=-1, r=-1;
  for(int i=0; i<n; i++) {
    if(v[i] > v[i+1]) {
      int pl = i, pr = i;
      while(pl and v[pl-1] >= v[pl]) pl--;
      while(pr < n-1 and v[pr+1] <= v[pr]) pr++;
      l = pl, r = pr;
      break;
    }
  }

  reverse(v.begin() + l, v.begin() + r + 1);
  if(increasing()) return printf("1\n%d %d\n", l+1, r+1), 0;

  printf("0\n");


	return 0;
}

