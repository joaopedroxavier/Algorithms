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
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll n;
ll a[N];
multiset<ll> s;

int main(){
  scanf("%lld", &n);
  for(int i=0; i<n; i++) scanf("%lld", &a[i]), s.insert(a[i]);
  if(!(n&1)) n++, s.insert(0);

  ll pty = 0;
  while(s.size() > 1) {
    auto p1 = s.begin();
    auto p2 = next(p1);
    auto p3 = next(p2);

    ll cost = *p1 + *p2 + *p3;

    s.erase(p1);
    s.erase(p2);
    s.erase(p3);

    pty += cost;
    s.insert(cost);
  }

  printf("%lld\n", pty);
	return 0;
}

