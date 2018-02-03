//
// C - Pavel and Barbecue
// CodeForces Round #393 Div.2
// Source: http://codeforces.com/contest/760
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
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int p[N], b[N], vis[N];

void dfs(int u){
	if(vis[u]) return;
	vis[u] = 1;
	dfs(p[u]);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, ans=0, sum=0;
	cin >> n;

	for(int i=1;i<=n;++i) cin >> p[i];
	for(int i=1;i<=n;++i){
		int u;
		cin >> u;
		ans = (ans+u)%2;
	}
	ans = !ans;
	for(int i=1;i<=n;++i) if(!vis[i]) sum++, dfs(i);
	if(sum == 1) sum = 0;
	cout << sum + ans << endl;

	return 0;
}

