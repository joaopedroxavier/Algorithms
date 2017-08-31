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
  ll l, r, x, y, k;
  cin >> l >> r >> x >> y >> k;
  for(ll i=x;i<=y;i++) if(i*k >= l and i*k <= r) return cout << "YES" << endl, 0;
  cout << "NO" << endl;
	return 0;
}

