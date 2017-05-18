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
const int N=3e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

vi adj[N];
ll dist[N], last[N], edg[N], sum;
map<ii,ll> wt, idx;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, vert;
	cin >> n >> m;
	memset(dist, INF, sizeof(dist));
	memset(last, INF, sizeof(last));
	for(int i=0;i<m;++i){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb(v), adj[v].pb(u);
		wt[mp(u,v)] = wt[mp(v,u)] = w;
		idx[mp(u,v)] = idx[mp(v,u)] = i+1;
	}
	cin >> vert;
	priority_queue<pair<ll,ll> > dij;
	dij.push(mp(0,vert));
	dist[vert] = 0;
	while(!dij.empty()){
		ll u = dij.top().second;
		ll w = -dij.top().first;
		dij.pop();
		for(int v : adj[u]){
			if(dist[v] > w + wt[mp(u,v)]){
				dist[v] = w + wt[mp(u,v)];
				dij.push(mp(-dist[v], v));
				last[v] = wt[mp(u,v)], edg[v] = idx[mp(u,v)];
			}
			else if(dist[v] == w + wt[mp(u,v)]){
				if(last[v] > wt[mp(u,v)]) last[v] = wt[mp(u,v)], edg[v] = idx[mp(u,v)];
			}
		}
	}
	for(int i=1;i<=n;++i)	if(i != vert) sum += last[i];
	cout << sum << endl;
	for(int i=1;i<=n;++i) if(i != vert) cout << edg[i] << " ";
	cout << endl;
	return 0;
}

