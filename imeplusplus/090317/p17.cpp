//
//	P17 - Chloe and pleasant prizes
//	Judge: CodeForces
//	source: http://codeforces.com/problemset/problem/743/D
//
//	(Okay, this problem is the same as the #384 Div.2 Problem D, but I'll put the code here as 
//	well just to organize stuff XD)
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

const int N=1e6;
const ll INF=0x3f3f3f3f3f3f3f3f;

vi adj[N];
int vis[N];
ll p[N], pleasure[N];
ll ans=-INF;

ll maxm(ll a, ll b, ll c){
	return max(max(a,b),c);
}

ll dfs(int u){
	vis[u]=1;
	pleasure[u]+=p[u];
	for(int v : adj[u]){
		if(!vis[v]) pleasure[u]+=dfs(v);
	}
	return pleasure[u];
}

ll best(int u){
	ll max1=-INF, max2=-INF;
	vis[u]=2;
	if(adj[u].size() == 2 and u!=1){
		for(int v : adj[u]) if(vis[v]!=2) return max(best(v),pleasure[u]);
	}
	else if(adj[u].size() == 1){
			if(u != 1) return pleasure[u];
			else return best(adj[1][0]);
	}
	for(int v : adj[u]){
		if(vis[v]!=2){
			ll best_one = best(v);
			if(best_one > max1) max2 = max1, max1 = best_one;
			else if(best_one > max2) max2 = best_one;
		}
	}
	ans = max(max1+max2, ans);
	return maxm(max1,max2,pleasure[u]);
}

int main(){
	int n;
	bool possible = false;
	cin >> n;
	for(int i=1;i<=n;++i) cin >> p[i];
	for(int i=0;i<n-1;++i){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	if(adj[1].size() >= 2) possible = true;
	for(int i=2;i<=n;++i) if(adj[i].size() > 2) possible = true;
	ll a = dfs(1);
	ll help = best(1);
	if(possible) cout << ans << endl;
	else cout << "Impossible" << endl;
	return 0;
}
