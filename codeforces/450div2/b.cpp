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

ll vis[N];
ll a, b, c;
ll cnt;

void occ(ll a, ll b, ll c) {
  if(vis[a]) { cnt = -1; return; }
  vis[a] = 1;
  cnt++;
  a *= 10;
  ll r = a/b;
  if(r == c) return;
  else occ(a%b, b, c);
}

int main(){
  scanf("%lld %lld %lld", &a, &b, &c);

  occ(a, b, c);
  printf("%lld\n", cnt);

	return 0;
}

