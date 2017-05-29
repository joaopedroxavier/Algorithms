#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=2e2+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int dx[] = {-1, 1, 0 , 0};
int dy[] = {0, 0, 1 , -1};
int grid[N][N], vis[N][N];
int ans=INF, sum;

void dfs(int x, int y){
	if(vis[x][y]) return;
	vis[x][y] = 1;
	sum++;
	for(int i=0;i<4;++i) if(grid[x][y] == grid[x+dx[i]][y+dy[i]] and !vis[x+dx[i]][y+dy[i]]) dfs(x+dx[i], y+dy[i]);
}

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin >> grid[i][j];
	for(int i=0;i<m+2;++i) vis[0][i] = vis[n+1][i] = 1;
	for(int i=0;i<n+2;++i) vis[i][0] = vis[i][m+1] = 1;

	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(!vis[i][j]) sum=0, dfs(i, j), ans = min(ans, sum);
	cout << ans << endl;
	return 0;
}

