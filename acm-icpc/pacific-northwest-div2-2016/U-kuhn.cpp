//
//	This code solves problem U - Mismatched Socks using Kuhn's algorithm.
//	However, it doesn't solve for all the cases. Because of the size of the inputs,
//	we cannot construct a whole graph to represent all the socks combinations and solve by
//	finding the maximum matching. It's a good idea and I tought it would be nice to code it.
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

const int N=1e5;
const int INF=0x3f3f3f3f;

int vis[N], par[N], x, v[N];
vi adj[N];
bool match(int v){
	if(vis[v] == x) return false;
	vis[v] = x;
	for(int u : adj[v]){
		if(!par[u] || match(par[u])) return (par[u] = v);
	}
	return false;
}

int main(){
	int n, ans=0, cont=0;
	cin >> n;
	for(int i=1;i<=n;++i){
		int u;
		cin >> u;
		for(int j=1;j<=u;++j){
			v[cont+j]=i;
		}
		cont+=u;
	}
	for(int i=1;i<=cont;++i){
		for(int j=i+1;j<=cont;++j){
			if(v[i]!=v[j]){
				adj[i].pb(j+cont);
				adj[i+cont].pb(j);
				adj[j].pb(i+cont);
				adj[j+cont].pb(i);
			}
		}
	}
	for(int i=1; i<=cont; i++) ++x, ans += match(i); 
	cout << ans/2 << endl;
	return 0;
}
