#include <bits/stdc++.h>

#define pb push_back

using namespace std;
const int N = 5e2+5;

set<int> ger[N];
int n, m, t, younger = 1e9;
int age[N], vis[N];

void check_younger(int u){
	vis[u] = 1;
	for(auto it = ger[u].begin(); it != ger[u].end(); ++it){
		int v = *it;
		if(!vis[v]){
			younger = min(younger,age[v]);
			check_younger(v);
		}
	}
}

void swp(int u, int v){
	vector<int> add1, add2;
	if(ger[u].count(v)) ger[u].erase(v), ger[u].insert(u);
	else if(ger[v].count(u)) ger[v].erase(u), ger[v].insert(v);
	set<int> aux;
	aux = ger[v];
	ger[v] = ger[u];
	ger[u] = aux;
	for(int i=1;i<=n;++i){
		if(i == u or i == v) continue;
		if(ger[i].count(v)){
			ger[i].erase(v);
			add1.pb(i);
		}
		if(ger[i].count(u)){
			ger[i].erase(u);
			add2.pb(i);
		}
	}
	for(int i : add1) ger[i].insert(u);
	for(int i : add2) ger[i].insert(v);
}

int main(){
	while(1){
		cin >> n >> m >> t;
		if(cin.eof()) break;
		for(int i=0;i<=n;++i) ger[i].clear();
		for(int i=1;i<=n;++i) cin >> age[i];
		for(int i=0;i<m;++i){
			int u, v;
			cin >> u >> v;
			ger[v].insert(u);
		}
		for(int i=0;i<t;++i){
			char c;
			cin >> c;
			if(c == 'T'){
				int ord1, ord2;
				cin >> ord1 >> ord2;
				swp(ord1, ord2);
			}			
			if(c == 'P'){
				int ord;
				cin >> ord;
				memset(vis, 0, sizeof(vis));
				younger = 1e9;
				check_younger(ord);
				if(younger == 1e9) cout << "*" << endl;
				else cout << younger << endl;
			}	
		}
	}	
	return 0;
}	
