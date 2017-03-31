//
//	(B - Hongcow Solves A Puzzle)
//	CodeForces Round #385 Div.2
//	source: http://codeforces.com/contest/745/problem/B
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

char grid[N][N];

int main(){
	ios::sync_with_stdio(false);
	int n, m, xfirst=INF, yfirst=INF, xlast=0, ylast=0;
	bool ans = true;
	cin >> n >> m;
	for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin >> grid[i][j];
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(grid[i][j] == 'X'){
				xfirst = min(xfirst, j);
				yfirst = min(yfirst, i);
				xlast = max(xlast, j);
				ylast = max(ylast, i);
			}
		}
	}
	for(int i=yfirst; i<=ylast;++i) for(int j = xfirst; j<=xlast; ++j) if(grid[i][j] == '.') ans = false;

	cout << ((ans) ? "YES" : "NO") << endl;
	return 0;
}

