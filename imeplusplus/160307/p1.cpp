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

const int N=1e5+9;

vi adj[N];
int vis[N];
map<ii,int> e;

int find_longest(int u){
	int ans;
	queue<int> bfs;
	bfs.push(u);
	while(!bfs.empty()){
		int v = bfs.front();
		for(int w : adj[v]){
			if(!vis[w]) bfs.push(w);
		}
		vis[v] = 1;
		ans = bfs.back();
		bfs.pop();
	}
	return ans;
}
int main(){
	int n, u, v;
	queue<int> bfs;
	cin >> n;
	for(int i=0;i<n-1;++i){
		cin >> u >> v;
		if(!e[mp(u,v)]){
			adj[u].pb(v);
			adj[v].pb(u);
			e[mp(u,v)] = 1;
			e[mp(v,u)] = 1;
		}
	}/*
	for(int i=1;i<=n; ++i){
		cout << i << ": ";
		for(int j : adj[i]) cout << j << ' ';
		cout << endl;
	}*/
	u = find_longest(1);
	memset(vis,0,sizeof(vis));
	v = find_longest(u);
	memset(vis,0,sizeof(vis));
	//cout << u << ' ' << v << endl;
	bfs.push(v);
	vis[v]=1;
	while(!bfs.empty()){
		int x = bfs.front();
		for(int y : adj[x]){
			if(!vis[y]){
				vis[y] = vis[x]+1;
				bfs.push(y);
			}
		}
		bfs.pop();
	}
	cout << vis[u]-1 << endl;
}

