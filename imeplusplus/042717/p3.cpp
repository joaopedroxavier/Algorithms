#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const ld EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

vi adj[N];
set<ll> occ[N];
map<ii, ll> wt;
ll dist[N];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;++i){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb(v), adj[v].pb(u);
		wt[mp(u,v)] = wt[mp(v,u)] = w;
	}
	for(int i=1;i<=n;++i){
		int s;
		cin >> s;
		for(int j=0;j<s;++j){
			int u;
			cin >> u;
			occ[i].insert(u);
		}
	}
	memset(dist, INF, sizeof(dist));
	priority_queue<ii> dij;
	dij.push(mp(0,1));
	while(!dij.empty()){
		int u = dij.top().second;
		int w = -dij.top().first;
		dij.pop();
		for(int v : adj[u]){
			while(occ[u].count(w)) w++;
			if(dist[v] > w + wt[mp(u,v)]){
				dist[v] = w + wt[mp(u,v)];
				dij.push(mp(-dist[v], v));
			}
		}
	}
	cout << ((dist[n] > INF) ? -1 : dist[n]) << endl;
	return 0;
}

