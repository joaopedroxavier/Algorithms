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
const int N=1e2+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int n, a, b;

bool fit(int x1, int y1, int x2, int y2){
  return (x1+x2 <= a and max(y1,y2) <= b) or (y1+y2 <= b and max(x1,x2) <= a);
}

int x[N], y[N];
int ans = 0;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n >> a >> b;
  for(int i=0;i<n;++i) cin >> x[i] >> y[i];
  for(int i=0;i<n;++i) for(int j=0;j<n;++j){
    if(j == i) continue;
    else{
      if(fit(x[i], y[i], x[j], y[j]) or
         fit(y[i], x[i], x[j], y[j]) or
         fit(y[i], x[i], y[j], x[j]) or
         fit(x[i], y[i], y[j], x[j])  ) ans = max(ans, x[i]*y[i] + x[j]*y[j]);
    }
  }
  cout << ans << endl;
	return 0;
}

