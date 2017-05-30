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

ll grid[N][N], aux[N][N], w, h, b, answ;
int dx[] = {0,0,0,1,1,1,-1,-1,-1};
int dy[] = {1,0,-1,1,0,-1,1,0,-1};
set<ll> diff;

ll ans(int x, int y){
	ll sum = 0;
	for(int i=0;i<9;++i){
		int a = (x+dx[i]+h)%h, b = (y+dy[i]+w)%w;
		sum += grid[a][b];
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> w >> h >> b;
	for(int i=0;i<h;++i) for(int j=0;j<w;++j) cin >> grid[i][j];
	for(int k=0;k<b;++k){
		memset(aux,0,sizeof(aux));
		for(int i=0;i<h;++i) for(int j=0;j<w;++j) aux[i][j] = ans(i, j);
		for(int i=0;i<h;++i) for(int j=0;j<w;++j) grid[i][j] = aux[i][j];
	}
	for(int i=0;i<h;++i){
		for(int j=0;j<w;++j){
			diff.insert(grid[i][j]);
		}
	}
	cout << diff.size() << endl;
	return 0;
}

