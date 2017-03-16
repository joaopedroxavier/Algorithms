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

const int N=1e3+9;

int vis[N][N], lab[N][N], cont=0;
int dx[] = {-1,0,0,1};
int dy[] = {0,1,-1,0};
ii find_longest(int x, int y){
	ii ans;
	queue<ii> bfs;
	bfs.push(mp(x,y));
	while(!bfs.empty()){
		ii u = bfs.front();
		for(int i=0;i<4;++i){
			if(!vis[u.first+dx[i]][u.second+dy[i]] and !lab[u.first+dx[i]][u.second+dy[i]]){
				bfs.push(mp(u.first+dx[i],u.second+dy[i]));
			}
		}
		vis[u.first][u.second] = 1;
		ans = bfs.back();
		bfs.pop();
	}
	return ans;
}

int main(){
	int t, c, r;
	string m;
	cin >> t;
	for(int k=0;k<t;++k){
		cin >> c >> r;
		for(int i=0;i<=c+1;++i) lab[0][i] = 1, lab[r+1][i] = 1;
		for(int i=0;i<=r+1;++i) lab[i][0] = 1, lab[i][c+1] = 1;
		for(int i=1;i<=r;++i){
			cin >> m;
			for(unsigned j=0;j<m.size();++j) if(m[j] == '#') lab[i][j+1] = 1;
		}/*
		for(int i=0;i<r+2;++i){
			for(int j=0;j<c+2;++j) cout << lab[i][j];
			cout << endl;
		}*/
		ii w;
		for(int i=1;i<=r;++i) for(int j=1;j<=c;++j) if(!lab[i][j]) w = mp(i,j);
		ii u = find_longest(w.first,w.second);
		memset(vis,0,sizeof(vis));
		ii v = find_longest(u.first, u.second);
		memset(vis,0,sizeof(vis));
		queue<ii> bfs;
		bfs.push(v);
		vis[v.first][v.second]=1;
		while(!bfs.empty()){
			ii p = bfs.front();
			bfs.pop();
			for(int i=0;i<4;++i){
				if(!vis[p.first+dx[i]][p.second+dy[i]] and !lab[p.first+dx[i]][p.second+dy[i]]){
					vis[p.first+dx[i]][p.second+dy[i]] = 1+vis[p.first][p.second];
					bfs.push(mp(p.first+dx[i],p.second+dy[i]));
				}
			}
		}
		cout << "Maximum rope length is " << vis[u.first][u.second]-1 << "." << endl;
		memset(vis,0,sizeof(vis));
		memset(lab,0,sizeof(lab));
	}
	return 0;
}

