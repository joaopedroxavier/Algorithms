#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define f first
#define s second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

set<int> res;

int main(){
  int n, m;
  scanf("%d %d", &n, &m);

  if(m == 0) return printf("%d\n", n == 1 ? 1 : -1), 0;

  vector<ii> v(m);

  for(int i=0; i<m; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    v[i] = mp(a, b);
  }
  sort(v.begin(), v.end());

  if(v[m-1].s == 1) return printf("%d\n", v[m-1].f >= n ? 1 : -1), 0;

  int l = (v[m-1].f) / v[m-1].s;
  int r = (v[m-1].f - 1) / (v[m-1].s - 1);
  //printf("%d %d\n", l, r);

  for(int i=l; i<=r; i++){
    bool ans = true;
    //printf("%d\n", i);
    for(ii p : v){
      //printf("%d: %d %d\n", p.f, (p.s - 1) * i + 1, p.s * i);
      ans = ans and (p.f <= p.s * i and p.f >= (p.s - 1) * i + 1); 
    }
    if(ans) /*printf("%d\n", i),*/ res.insert(n % i ? n/i + 1 : n/i);
  }

  printf("%d\n", res.size() > 1 ? -1 : *res.begin());

	return 0;
}

