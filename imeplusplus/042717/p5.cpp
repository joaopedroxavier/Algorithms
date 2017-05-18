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
const int N=1e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll dist[N], wt[N][N];
vi adj[N];

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int q=0;q<t;++q){
		int n, m;
		cin >> n >> m;
		bool check = false;
		memset(wt, INF, sizeof(wt));
		memset(dist, INF, sizeof(dist));
		for(int i=0;i<n;++i) adj[i].clear();
		for(int i=0;i<m;++i){
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].pb(v);
			wt[u][v] = w;
		}
		dist[0] = 0;
		for(int u=0;u<n;++u){
			for(int v : adj[u]){
				dist[v] = min(dist[v], dist[u] + wt[u][v]);
			}
		}
		for(int u=0;u<n;++u){
			for(int v : adj[u]){
				if(dist[v] > dist[u] + wt[u][v]){
					check = true;
				}
			}
		}
		cout << ((check) ? "possible" : "not possible") << endl;
	}
	return 0;
}

