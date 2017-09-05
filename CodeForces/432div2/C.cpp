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

ll a[N], b[N], c[N], d[N], e[N];
int bad[N];
int n;
vi ans;

ll ps(int i, int j){
  return a[i]*a[j] + b[i]*b[j] + c[i]*c[j] + d[i]*d[j] + e[i]*e[j];
}

int main(){
  scanf("%d", &n);
  for(int i=0;i<n;i++){
    scanf("%lld %lld %lld %lld %lld", &a[i], &b[i], &c[i], &d[i], &e[i]);
  }
  for(int i=0;i<n;i++){
    if(!bad[i])
    for(int j=0;j<n;j++){
      if(j == i) continue;
      for(int k=j+1;k<n;k++){
        if(k == i) continue;
        a[k] -= a[i], a[j] -= a[i];
        b[k] -= b[i], b[j] -= b[i];
        c[k] -= c[i], c[j] -= c[i];
        d[k] -= d[i], d[j] -= d[i];
        e[k] -= e[i], e[j] -= e[i];
        if(ps(k,j) <= 0) bad[k] = bad[j] = 1;
        else bad[i] = 1;
        a[k] += a[i], a[j] += a[i];
        b[k] += b[i], b[j] += b[i];
        c[k] += c[i], c[j] += c[i];
        d[k] += d[i], d[j] += d[i];
        e[k] += e[i], e[j] += e[i];
      }
    }
  }
  for(int i=0;i<n;i++) if(!bad[i]) ans.pb(i);
  printf("%d\n", (int)ans.size());
  for(int i : ans) printf("%d\n", i+1);
	return 0;
}

