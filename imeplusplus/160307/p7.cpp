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

const int N=1e3;
const int INF = 0x3f3f3f3f;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int ans=0, vis[N][N], m[N][N];
void dfs(int x, int y){
	vis[x][y] = 1;
	ans++;
	for(int i=0;i<4;++i){
	if(!vis[x+dx[i]][y+dy[i]] and m[x][y]==m[x+dx[i]][y+dy[i]])
		dfs(x+dx[i],y+dy[i]);
	}
}

int main(){
	int l, c, cont=INF;
	cin >> l >> c;
	for(int i=0;i<=c+1;++i) vis[0][i] = 1, vis[l+1][i] = 1;
	for(int i=0;i<=l+1;++i) vis[i][0] = 1, vis[i][c+1] = 1;
	for(int i=1;i<=l;++i){
		for(int j=1;j<=c;++j){
			cin >> m[i][j];
		}
	}
	for(int i=1;i<=l;++i){
		for(int j=1;j<=c;++j){
			if(!vis[i][j]){
				ans = 0;
				dfs(i,j);
				cont = min(cont, ans);
			}
		}
	}
	cout << cont << endl;
}

