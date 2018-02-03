//
//	(C - Hongcow Builds A Nation)
//	CodeForces Round #385 Div.2
//	source: http://codeforces.com/contest/745/problem/C
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define _ << ' ' <<

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e4;
const int INF=0x3f3f3f3f;

int home[N], vis[N];
vi adj[N];

ll clique(ll n){
	return ((n%2==0) ? (n/2)*(n-1) : ((n-1)/2)*(n));
}
int dfs1(int u){
	vis[u] = 1;
	int sz = 1;
	for(int v : adj[u]) if(vis[v]!=1) sz+=dfs1(v);
	return sz;
}

int dfs2(int u){
	vis[u] = 2;
	int sz = adj[u].size();
	for(int v : adj[u]) if(vis[v]!=2) sz+=dfs2(v);
	return sz;
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, k;
	ll cont1=0, cont2=0, maxm1=0, maxm2=0, ans=0;
	cin >> n >> m >> k;
	for(int i=0;i<k;++i){
		int u;
		cin >> u;
		home[u] = 1;
	}
	for(int i=1;i<=m;++i){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i=1;i<=n;++i){
		if(home[i]){
				cont1=dfs1(i);
				cont2=dfs2(i)/2;
			if(maxm1 == 0) maxm1 = cont1, maxm2 = cont2;
			else if(maxm1 < cont1){
				ans+=(clique(maxm1)-maxm2);
				maxm1 = cont1;
				maxm2 = cont2;
			}
			else ans+=(clique(cont1)-cont2);
		}
	}
	for(int i=1;i<=n;++i){
		if(vis[i]!=2){
			maxm1+=dfs1(i);
			maxm2+=dfs2(i)/2;
		}
	}
	ans+=clique(maxm1) - maxm2;
	cout << ans << endl;
	return 0;
}

