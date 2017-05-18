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

const int N=1e6;

int vis[N];
vi adj[N];

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
	int t, n;
	queue<int> bfs;
	cin >> t;
	for(int k=0;k<t;++k){
		cin >> n;
		for(int i=0;i<n;++i) adj[i].clear();
		for(int i=0;i<n-1;++i){
			int u, v;
			cin >> u >> v;
			adj[v].pb(u);
			adj[u].pb(v);
		}
		int u = find_longest(0);
		memset(vis,0,sizeof(vis));
		int v = find_longest(u);
		memset(vis,0,sizeof(vis));
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
		cout << vis[u]/2 << endl;
		memset(vis,0,sizeof(vis));
	}
	return 0;
}

