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

const int N=1e6+9;

int vis[N];
vi adj[N];

void dfs(int u){
	vis[u] = 1;
	for(int v : adj[u]){
		if(!vis[v]) dfs(v);
	}
}

int main(){
	int t,n,m,ans;
	cin >> t;
	for(int k=0;k<t;++k){
		ans = 0;
		memset(vis,0,sizeof(vis));
		cin >> n >> m;
		for(int i=0;i<n;++i) adj[i].clear();
		for(int i=0;i<m;++i){
			int u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		for(int i=0;i<n;++i){
			if(!vis[i]) ans++, dfs(i);
		}
		cout << ans << endl;
	}
}

