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

int main(){
	ios_base::sync_with_stdio(false);
  int c, v0, v1, a, l;
  cin >> c >> v0 >> v1 >> a >> l;
  int ans = 0, p = 0;
  while(p < c){
    ans++;
    if(ans > 1) p -= l;
    p += min(v0, v1);
    v0 += a;
  }
  cout << ans << endl;
	return 0;
}

