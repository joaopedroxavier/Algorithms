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

const int N=1e2+9;
const int INF=1e9+1;

int c[N], dist[N], w[N][N];
vi adj[N];
int sh_path(int u, int v){
	memset(dist, INF, sizeof(dist));
	priority_queue<ii> pq;
	pq.push(mp(0,u));
	dist[u] = 0;
	while(!pq.empty()){
		ii y = pq.top();
		pq.pop();
		for(int x : adj[y.second]){
			if(dist[x]>y.first+w[y.second][x]){
				dist[x] = dist[y.second]+w[y.second][x];
				pq.push(mp(dist[x],x));
			}
		}
	}
	return dist[v];
}

int main(){
	int n, e, t, m, ans=0;
	cin >> n >> e >> t >> m;
	memset(w,INF,sizeof(w));
	for(int i=0;i<m;++i){
		int u, v, wt;
		cin >> u >> v >> wt;
		adj[u].pb(v);
		w[u][v] = wt;
	}
	for(int i=1;i<=n;++i)  if(sh_path(i,e)<=t) ans++;
	cout << ans << endl;
}


