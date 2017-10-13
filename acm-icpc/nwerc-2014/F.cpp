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

ll n, p, x[N], y[N];
vi v;

bool colinear(int i, int j, int k){
  return !( x[i]*y[j] + x[j]*y[k] + x[k]*y[i] - y[i]*x[j] - y[j]*x[k] - y[k]*x[i]);
}

int get_num(int i, int j){
  int ans = 0;
  for(int k=0;k<n;k++){
    if(colinear(i, j, k)) ans++;
  }
  return ans;
}

int main(){
  srand(time(0));
  scanf("%lld %lld", &n, &p);
  if(n == 1) return printf("possible\n"), 0;

  for(int i=0;i<n;i++) scanf("%lld %lld", &x[i], &y[i]), v.pb(i);
  random_shuffle(v.begin(), v.end());

  if(n < 100){
    int ans = 0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(j!=i){
      ans = max(ans, get_num(i,j));
    }
    return printf("%s\n", (ans >= (n * p + 99) / 100) ? "possible" : "impossible"), 0;
  }
  else{
    int ans = 0;
    for(int i=0;i<50;i++) for(int j=0;j<50;j++) ans = max(ans, get_num(v[i], v[50+j]));
    return printf("%s\n", (ans >= (n * p + 99) / 100) ? "possible" : "impossible"), 0;
  }
}

