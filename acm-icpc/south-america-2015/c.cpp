#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n;
ll x[N], y[N];
ll A[N];

ll area(int i, int j, int k){
  ll res = x[i]*y[j] + x[j]*y[k] + x[k]*y[i] - y[i]*x[j] - y[j]*x[k] - y[k]*x[i];
  return abs(res);
}

ll area(int i, int j){
  if(i > j) swap(i, j);
  return A[j] - A[i] - area(1, i, j);
}

ll query(int i, int j){
  ll ma = max(area(i, j), A[n] - area(i, j));
  ll mi = min(area(i, j), A[n] - area(i, j));
  return ma - mi;
}

int lowest_diff(int i){
  int l = 1, r = n-1;
  while(l < r){
    if(r - l <= 2){
      int ans = l;
      for(int p=l; p<=r; p++) if(query(i, (i+p-1) % n + 1) < query(i, (i+ans-1) % n + 1)) ans = p;
      return (i+ans-1) % n + 1;
    }
    int m1 = (2*l + 1*r) / 3;
    int m2 = (1*l + 2*r) / 3;
    if(query(i, (i+m1-1) % n + 1) >= query(i, (i+m2-1) % n + 1)) l = m1;
    else r = m2;
  }
  return (i+l-1) % n + 1;
}

int main(){
  scanf("%d", &n);

  for(int i=1; i<=n; i++) scanf("%lld %lld", &x[i], &y[i]);

  for(int i=3; i<=n; i++) A[i] = A[i-1] + area(i, i-1, 1); 
  //for(int i=1; i<=n; i++) printf("%lld ", A[i]);
  //printf("\n");

  vector<ii> cand;
  for(int i=1; i<=n; i++){
    int j = lowest_diff(i);
    //printf("%d %d\n", i, j);
    cand.pb(mp(i, j));
  }

  sort(cand.begin(), cand.end(), [](ii a, ii b){ return query(a.first, a.second) > query(b.first, b.second); });

  int b1 = cand[0].first, b2 = cand[0].second;
  ll ma = max(area(b1, b2), A[n] - area(b1, b2));
  ll mi = min(area(b1, b2), A[n] - area(b1, b2));

  printf("%lld %lld\n", ma, mi);
	return 0;
}

