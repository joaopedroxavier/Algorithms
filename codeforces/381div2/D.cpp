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

int dad[N], a[N], l[N], depth[N], vis[N], ans[N], ancs[N];
vector<int> dads[N];

int gen_depth(int u){
	if(vis[u]==1){
		return depth[u];
	}
	else{
		depth[u] = l[u] + gen_depth(dad[u]);
		vis[u] = 1;
	}
	return depth[u];
}

void gen_dads(int u){
	if(vis[dad[u]]==1){
		dads[u] = dads[dad[u]];
		dads[u].pb(dad[u]);
		vis[u] = 1;
	}
	else{
		gen_dads(dad[u]);
		dads[u] = dads[dad[u]];
		dads[u].pb(dad[u]);
		vis[u] = 1;
	}
}

int bin_search(int p, int l, int r, int u){
	int m, aux;
	while(l<=r){
		m=(l+r)/2;
		//if(depth[dads[u].at(m)]==p) return m;
		if(depth[dads[u].at(m)]>=p){
			aux = m;
			l = m+1;
		}
		else r=m-1;
	}
	return ancs[u]-aux;
}

/*int check(int u){
	int l=0, r=dads[u].size(), m;
	if(vis[u]==0){
		ans[u] = bin_search(depth[u], 0, dads[u].size(), dads[u]);
		vis[u] = 1;
	}
}*/

int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i];
	for(int i=2;i<=n;++i){
		cin >> dad[i] >> l[i];
		ancs[i]++;
	}
	depth[1]=0;
	vis[1]=1;
	for(int i=2;i<=n;++i) cout << gen_depth(i) << ' ';
	cout << endl;
	for(int i=2;i<=n;++i) vis[i]=0;
	for(int i=1;i<=n;++i) if(!vis[i]) gen_dads(i);
	for(int i=1;i<=n;++i){
		for(unsigned j=0;j<dads[i].size();++j){
			cout << depth[dads[i].at(j)] << ' ';
		}
		cout << endl;
	}
	for(int i=1;i<=n;++i) vis[i]=0;
	for(int i=2;i<=n;++i){
		ans[i] = bin_search(depth[i]-a[i], 0, ancs[i]-1, i);
	}
	for(int i=1;i<=n;++i) cout << ans[i] << ' ';
	cout << endl;
	return 0;
}

