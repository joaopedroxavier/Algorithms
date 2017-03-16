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

const int N=2e5+9;

map<ii,int> e;
vi adj[N];
int ans=1, vis[N];

void dfs(int u, int v){
	vis[v] = 1;
	for(int w : adj[v]){
		if(vis[w] and w!= u){
			ans = 0;
		}
		else if(!vis[w]) dfs(v, w);
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;++i){
		int u, v;
		cin >> u >> v;
		if(!e[mp(u,v)]){
			adj[u].pb(v);
			adj[v].pb(u);
			e[mp(u,v)]=1;
			e[mp(v,u)]=1;
		}
	}
	adj[0].pb(1);
	dfs(0,1);	for(int i=1;i<=n;++i)	if(!vis[i]) ans = 0;
	cout << ((ans) ? "YES" : "NO") << endl;
	return 0;
}

