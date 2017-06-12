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
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int act[N], n, c;
int ans, m;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n >> c;
  for(int i=0;i<n;++i) cin >> act[i];

  for(int i=0;i<n;++i){
    m = act[i];
    for(int j=i+1;j<=n;++j){
      if(act[j] < act[i] or m - act[j] > c){
        ans += max(m-act[i]-c, 0);
        i = j-1;
        break;
      }
      m = max(m, act[j]);
    }
  }

  cout << ans << endl;

  return 0;
}

