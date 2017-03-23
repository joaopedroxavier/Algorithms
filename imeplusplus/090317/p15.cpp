//
//	P15 - Anton and Tree
//	Judge: CodeForces
//	source: http://codeforces.com/problemset/problem/734/E'
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=2e5+9;

vi adj[N];
int vis[N], color[N];

int find_longest(int u){
	int ans;
	queue<int> bfs;
	bfs.push(u);
	int m=0;
	vis[u] = 1;
	while(!bfs.empty()){
		int v = bfs.front();
		for(int w : adj[v]){
			if(!vis[w]){
				if(color[w] != color[v]){
					vis[w] = 1+vis[v];
					if(vis[w]>m) ans = w, m = vis[w];
				}
				else vis[w] = vis[v];
				bfs.push(w);
			}
		}
		bfs.pop();
	}
	return ans;
}

int main(){
	int n;
	bool std = true;
	cin >> n;
	for(int i=1;i<=n;++i) cin >> color[i];
	for(int i=1;i<=n-1;++i){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
		if(color[u]!=color[v]) std = false;
	}
	if(std) cout << 0 << endl;
	else{
	int u = find_longest(1);
	memset(vis,0,sizeof(vis));
	int v = find_longest(u);
	cout << vis[v]/2 << endl;
	}
	return 0;
}

