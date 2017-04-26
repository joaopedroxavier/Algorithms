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

int grid[N][N], vis[N][N];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool go(int x, int y, int poi){
	if(grid[x][y] == poi) return true;
	for(int i=0;i<4;++i){
		if((grid[x+dx[i]][y+dy[i]] == (grid[x][y] + 1)) and !vis[x][y]) return go(x+dx[i], y+dy[i], poi);
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int k=0;k<t;++k){
		memset(grid, 0, sizeof(grid));
		int m, n, pi, ans = false;
		cin >> pi >> m >> n;
		for(int i=0;i<n+2;++i) vis[0][i] = 1, vis[m+1][i] = 1;
		for(int i=0;i<m+2;++i) vis[i][0] = 1, vis[i][n+1] = 1;
		for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) vis[i][j] = 0;
		for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) cin >> grid[i][j];
		for(int i=1;i<=m;++i) for(int j=1;j<=n;++j) if(grid[i][j] == 1) ans = go(i,j, pi);
		cout << ((ans) ? "true" : "false") << endl;
	}
	return 0;
}

