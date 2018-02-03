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
ll p[N];

int main(){
  scanf("%lld %lld", &n, &k);

  ll m = 0;
  for(int i=0; i<n; i++) scanf("%lld", &p[i]), m = max(m, p[i]);

  int cnt = 0;
  int p1 = 0, p2 = 1;
  for(int i=1; i<n; i++) {
    p2 = i;
    if(p[p1] > p[p2]) {
      cnt++;
    } else {
      p1 = p2;
      cnt = 1;
    }
    if(cnt == k or m == p[p1]) return printf("%lld\n", p[p1]), 0;
  }

  printf("%lld\n", n);

  return 0;
}

