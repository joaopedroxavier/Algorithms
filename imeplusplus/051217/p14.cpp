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

int sieve[N], good[N], last[N], dp[N];
vi pf[N];

int main(){
	ios_base::sync_with_stdio(false);
	for(int i=2;i<N;++i){
		if(!sieve[i]){
			pf[i].pb(i);
			for(int j=2*i;j<N;j+=i) sieve[j] = 1, pf[j].pb(i);
		}
	}
	int n, ans=0;
	cin >> n;
	for(int i=1;i<=n;++i) cin >> good[i];
	for(int i=1;i<=n;++i){
		for(int j : pf[good[i]]){
			dp[i] = max(dp[i], dp[last[j]] + 1);
			last[j] = i;
		}
	}
	for(int i=1;i<=n;++i) ans = max(ans, dp[i]);
	cout << ((n == 1) ? 1 : ans) << endl;
	return 0;
}
