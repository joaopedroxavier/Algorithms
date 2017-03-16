//
//
//
//
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=2e3+9;

int vis[N], ans=1, e[N][N];
vi adj[N];
void dfs(int u, int c1){
	vis[u] = c1;
	for(int v : adj[u]){
		if(vis[v]==vis[u]){
			ans = 0;
		}
		else if(!vis[v]) dfs(v, (c1%2)+1);
	}
}
int main(){
	int t, n, m, u, v;
	cin >> t;
	for(int k=0;k<t;++k){
		cin >> n >> m;
		ans = 1;
		for(int i=1;i<=n;++i) adj[i].clear();
		memset(e,0,sizeof(e));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=m;++i){
			cin >> u >> v;
			if(!e[u][v]){
				adj[u].pb(v);
				adj[v].pb(u);
//				cout << u << ' ' << v << endl;
				e[u][v] = 1;
				e[v][u] = 1;
			}
		}/*
		for(int i=1;i<=n;++i){
			cout << i << ": " ;
			for(int v : adj[i]) cout << v << ' ';
			cout << endl;
		}*/
		for(int i=1;i<=n;++i) if(!vis[i]) dfs(i,1);
//		for(int i=1;i<=n;++i) cout << vis[i] << ' ';
		cout << "Scenario #" << k+1 << ":" << endl << ((ans) ? "No suspicious bugs found!" : "Suspicious bugs found!") << endl;
	}
	return 0;

}

