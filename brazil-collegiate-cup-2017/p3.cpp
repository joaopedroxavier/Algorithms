//
//
//
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

ll b[N], s[N];
ll ans;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1;i<=n;++i) cin >> b[i];

	for(int i=1;i<=n;++i) s[i] = b[i]+s[i-1];


	for(int i=1;i<=n;++i) ans = max(ans, s[i]*(s[n]-s[i]));

	cout << ans << endl;

	return 0;
}

