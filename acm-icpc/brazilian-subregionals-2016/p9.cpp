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

int grid[N], l[N], r[N], n, ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;++i)	cin >> grid[i];
	for(int i=1;i<=n;++i){
		l[i] = min(l[i-1]+1, grid[i]);
		r[n-i+1] = min(r[n-i+2]+1, grid[n-i+1]);
	}
	for(int i=1;i<=n;++i) ans = max(ans, min(l[i], r[i]));
	cout << ans << endl;
	return 0;
}

