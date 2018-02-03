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

ll gcd(ll a, ll b){ return b ? gcd(b, a%b): a; }

int main(){
  ll n, k;
  scanf("%lld %lld", &n, &k);
  ll kk = 1;
  while(k) kk*=10, k--;
  printf("%lld\n", n * kk / gcd(n, kk));

	return 0;
}

