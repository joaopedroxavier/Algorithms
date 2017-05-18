//
//	P2 - Making Jumps
//	Judge: SPOJ
//	source: http://www.spoj.com/problems/MKJUMPS/
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
const int INF = 1e9;

int table[N][N];
int vis[N][N];
int m=INF, cont;
int dx[] = {1,1,-1,-1,2,2,-2,-2};
int dy[] = {2,-2,2,-2,1,-1,1,-1};
void dfs(int x, int y){
	if(table[x][y] == 1) return;
	if(vis[x][y] == 1) return;
	vis[x][y] = 1;
	cont --;
	m = min(m,cont);
	for(int i=0;i<8;++i){
		dfs(x+dx[i],y+dy[i]);
	}
	vis[x][y] = 0;
	cont++;
}
int main(){
	int n, l1, l2, p=1;
	while(1){
		cin >> n;
		if(n==0) break;
		cont = 0;
		m = INF;
		memset(table, 0, sizeof(table));
		memset(vis, 0, sizeof(vis));
		for(int i=2;i<n+2;++i){
			cin >> l1 >> l2;
			cont+=l2;
			for(int j=2;j<l1+2;++j) table[i][j] = 1;
			for(int j=l1+l2+2;j<12;++j) table[i][j] = 1;
		}
		for(int i=n+2;i<12;++i) for(int j=2;j<12;++j)	table[i][j] = 1;
		for(int i=0;i<2;++i)	for(int j=0;j<14;++j)	table[i][j] = 1;
		for(int i=0;i<2;++i)	for(int j=0;j<14;++j)	table[j][i] = 1;
		for(int i=12;i<14;++i)	for(int j=0;j<14;++j)	table[i][j] = 1;
		for(int i=12;i<14;++i)	for(int j=0;j<14;++j)	table[j][i] = 1;
		dfs(2,2);
		if(m==1) cout << "Case " << p << ", " <<  m << " square can not be reached."<< endl;
		else cout << "Case " << p << ", " <<  m << " squares can not be reached."<< endl;
		p++;
	}
	return 0;
}

