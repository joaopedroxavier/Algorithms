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

ll n;

int main(){
  scanf("%lld", &n);

  ll ans = 1;
  for(int i=0; i<(n-1)*(n-1); i++) {
    ans = (ans * n) % MOD;
  }

  printf("%lld\n", ans);
	return 0;
}

