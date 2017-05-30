//
// E - Dasha and Puzzle
// CodeForces Round #394 Div.2
// Source: http://codeforces.com/contest/761
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

vi adj[N];
ll dx[] = {1, 0, 0, -1};
ll dy[] = {0, 1, -1, 0};
ll bad[] = {3, 2, 1, 0, 6};
int vis[N];
pair<ll,ll> pos[31];

void dfs(int u, ll xp, ll yp, int p, ll e){
	if(vis[u]) return;
	vis[u] = 1;
	pos[u] = mp(xp, yp);
	int j=0;
	for(int v : adj[u]){
		if(!vis[v]){
			if(j == bad[p]) j++;
			ll xpv = xp + dx[j]*(e/2), ypv = yp + dy[j]*(e/2);
			dfs(v, xpv, ypv, j, e/2);
			j++;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	for(int i=0;i<n-1;++i){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v),	adj[v].pb(u);
	}
	for(int i=1;i<=n;++i) if(adj[i].size() > 4){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	dfs(1, 0, 0, 4, (ll)(1<<31));
	for(int i=1;i<=n;++i) cout << pos[i].first _ pos[i].second << endl;
	return 0;
}

