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
#define _ << ' ' <<

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e3;
const int INF=0x3f3f3f3f;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int vis[N][N];
string grid[N];
int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> m >> n;
	for(int i=0;i<m;++i) cin >> grid[i];
	queue<ii> bfs;
	bfs.push(mp(0,0));
	vis[0][0] = 1;
	while(!bfs.empty()){
		int x = bfs.front().first;
		int y = bfs.front().second;
		bfs.pop();
		for(int i=0;i<4;++i){
			int a = x+dx[i]*(grid[x][y]-'0');
			int b = y+dy[i]*(grid[x][y]-'0');
			if(a < 0 or b < 0) continue;
			else if(a > m-1 or b > n-1) continue;
			else if(!vis[a][b]) vis[a][b] = vis[x][y] + 1, bfs.push(mp(a,b));
		}
	}
	if(vis[m-1][n-1]) cout << vis[m-1][n-1] - 1 << endl;
	else cout << "IMPOSSIBLE" << endl;
	return 0;
}

