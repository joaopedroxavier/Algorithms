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

ll n, k;

ll josephus(ll n, ll k) {
  if(n == 1) return 1;
  else return (josephus(n-1, k) + k - 1) % n +1;
}

int main(){
  scanf("%lld %lld", &n, &k);

  printf("%lld\n", josephus(n,k));
	return 0;
}

