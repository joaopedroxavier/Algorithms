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

int adj[N][N], vis[N], sz;
set<pair<string, string> > author;
map<pair<string, string>, int> idx;

int get_dist(int n){
	queue<int> bfs;
	bfs.push(idx[mp("Erdos", "P.")]);
	while(!bfs.empty()){
		int u = bfs.front();
		bfs.pop();
		for(int i=0;i<sz;++i){
			if(adj[u][i]!=INF and !vis[i]) bfs.push(i), vis[i] = vis[u]+1;
		}
	}
	return vis[n];
}

int main(){
	ios_base::sync_with_stdio(false);
	int a, test=0;
	while(1){
		test++;
		cin >> a;
		if(a == 0) break;
		int cont=1;
		string s;
		author.clear();
		author.insert(mp("Erdos", "P."));
		memset(adj, INF, sizeof(adj));
		memset(vis, 0, sizeof(vis));
		getline(cin, s);
		for(int i=0;i<a;++i){
			set<pair<string, string> > aut;
			int last=0;
			getline(cin, s);
			for(int j=0;j<(int)s.size();++j){
				if(s[j] == ',' or j == (int)s.size() - 1){
					string a, b;
					a = s.substr(last, 2);
					b = s.substr(last+3, j-last-3);
					aut.insert(mp(b,a));
					if(!author.count(mp(b,a))) idx[mp(b,a)] = cont, cont++;
					last = j+2;
				}
			}
			for(auto it=aut.begin(); it!=aut.end(); ++it){
				for(auto jt=aut.begin(); jt!=aut.end();++jt){
					if(*it != *jt) adj[idx[*it]][idx[*jt]] = 1;
				}
				author.insert(*it);
			}
		}
		sz = (int)author.size();
		cont = get_dist(sz-1); //whatever
		cout << "Teste " << test << endl;
		for(auto it=author.begin();it!=author.end();++it)	if(idx[*it]){
				cout << (*it).second _ (*it).first << ": ";
				if(vis[idx[*it]]) cout << vis[idx[*it]] << endl;
				else cout << "infinito" << endl;
		}
	}
	return 0;
}

