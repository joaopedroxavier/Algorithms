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

set<ll> s;
ll a[N], b[N];
int n;

int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++) scanf("%lld", &a[i]), s.insert(a[i]);
  for(int i=0; i<n; i++) scanf("%lld", &b[i]), s.insert(b[i]);

  ll ans = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      ll u = a[i] ^ b[j];
      if(s.count(u)) ans++;
    }
  }

  printf("%s\n", ans % 2 ? "Koyomi" : "Karen");

	return 0;
}

