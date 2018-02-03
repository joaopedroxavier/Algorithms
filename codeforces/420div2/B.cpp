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
const int N=1e4+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll m, b;
ll ans, cusum, tp, sum;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> m >> b;
  ll y=b;
  for(ll x=0; x<=m*b; x+=m){
    sum = y*(y+1)*(x+1)/2 + x*(x+1)*(y+1)/2;
    y--;
    ans = max(ans, sum);
  }
  cout << ans << endl;
	return 0;
}

