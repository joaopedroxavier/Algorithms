#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fst first
#define snd second

using namespace std;
vector<int> v, w;
int n, m;
bool ans;
map<vector<int>, int> vis;

vector<int> dobra(vector<int> vec, int t, int p){
	vector<int> r;
	if(p <= t/2){
		for(int i=t-1;i>2*p-1;--i) r.pb(vec[i]);
		for(int i=0;i<p;++i){
			r.pb(vec[p+i] + vec[p-i-1]);
		}
	}
	else{
		for(int i=0;i<p-(t-p);++i) r.pb(vec[i]);
		for(int i=t-1;i>=p;--i){
			r.pb(vec[i] + vec[i-2*(i-p)-1]);
		}
	}
	return r;
}

int main(){
	while(1){
		cin >> n;
		if(cin.eof()) break;
		v.clear();
		w.clear();
		vis.clear();
		for(int i=0;i<n;++i){
			int u;
			cin >> u;
			v.pb(u);
		}
		cin >> m;
		for(int i=0;i<m;++i){
			int u;
			cin >> u;
			w.pb(u);
		}
		queue<vector<int>> bfs;
		bfs.push(v);
		vis[v] = 1;
		ans = false;
		while(!bfs.empty()){
			vector<int> u = bfs.front();
			if(u == w){
				ans = true;
				break;
			}
			bfs.pop();
			int s = u.size();
			for(int i=0;i<s;++i){
				vector<int> nu = dobra(u, s, i);
				if(nu.size() < m or vis[nu]) continue;
				else{
					vis[nu] = 1;
					bfs.push(nu);
				}
			}
		}
		cout << ((ans) ? "S" : "N") << endl;
	}
	return 0;
}
