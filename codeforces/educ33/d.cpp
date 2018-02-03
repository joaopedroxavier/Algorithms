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

ll n, d;
ll a[N], s[N], mx[N];

int main(){
  scanf("%lld %lld", &n, &d);
  for(int i=1; i<=n; i++) scanf("%lld", &a[i]), s[i] = s[i-1] + a[i];

  mx[n] = s[n];
  for(int i=n-1; i>0; i--) mx[i] = max(mx[i+1], s[i]);
  if(mx[1] > d) return printf("-1\n"), 0;

  //for(int i=1; i<=n; i++) printf("%lld ", mx[i]);
  //printf("\n");

  ll c = 0, ans = 0;
  for(int i=1; i<=n; i++) {
    mx[i] += c;
    s[i] += c;
    if(a[i] == 0 and s[i] < 0) {
      ll add = d - mx[i]; 
      c += add; ans++; s[i] += add;
    }
    if(a[i] == 0 and s[i] < 0) return printf("-1\n"), 0;
  }

  printf("%lld\n", ans);

	return 0;
}

