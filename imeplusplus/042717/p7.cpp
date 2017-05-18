//
//
//
//
//
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
const int M=1e6+5;
const int MOD=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f;

ll adj[N][N], ans[M], o[M], d[M], t[M], ord[M];

int main(){
	ios_base::sync_with_stdio(false);
	ll n, m, c, inst = 0;
	while(1){
		inst++;
		cin >> n;
		if(cin.eof()) break;
		cout << "Instancia " << inst << endl;
		cin >> m;
		memset(adj, 63, sizeof(adj));
		for(int i=0;i<n;++i) adj[i][i] = 0;
		for(int i=0;i<m;++i){
			ll u, v, w;
			cin >> u >> v >> w;
			adj[u][v] = min(adj[u][v], w);
		}
		cin >> c;
		for(int i=0;i<c;++i){
			ll u, v, w;
			cin >> u >> v >> w;
			ord[i] = i;
			o[i] = u, d[i] = v, t[i] = w;
		}
		sort(ord, ord+c, [](int a, int b){return (t[a] < t[b]);});
		int k=1;
		for(int a=0;a<c;++a){
			int q = t[ord[a]];
			for(;k<=q;++k){
				for(int i=1;i<=n;++i){
					for(int j=1;j<=n;++j){
						adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
					}
				}
			}
			ans[ord[a]] = adj[o[ord[a]]][d[ord[a]]];
		}
		for(int i=0;i<c;++i){
			cout << ((ans[i] == INF) ? -1 : ans[i]) << endl;
		}
		cout << endl;
	}
	return 0;
}

