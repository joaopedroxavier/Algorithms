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

ll n, sum;
ll a[N], b[N];

int main(){
  scanf("%lld", &n);
  for(int i=0; i<n; i++) scanf("%lld", &a[i]);

  for(int i=0; i<n; i++) {
    ll u;
    scanf("%lld", &u);
    sum += a[i];
    b[i] = u;
  }

  sort(b, b+n);
  ll cap = b[n-1] + b[n-2];
  printf("%s\n", cap >= sum ? "YES" : "NO");
  return 0;
}

