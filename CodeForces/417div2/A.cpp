//
//
//
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
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int adj[5][5], p[5];
int ord[4][3] = {{3, 2, 1},{0, 3, 2},{1, 0, 3},{2, 1, 0}};

int main(){
	ios_base::sync_with_stdio(false);
	bool ans=false;

	for(int i=0;i<4;++i){
		for(int j=0;j<3;++j) cin >> adj[i][ord[i][j]];
		cin >> p[i];
	}

	for(int i=0;i<4;++i) if(p[i]){
		for(int j=0;j<4;++j) if(adj[i][j]) ans=true;
		for(int j=0;j<4;++j) if(adj[j][i]) ans=true;
	}

	cout << ((ans) ? "YES" : "NO") << endl;
	return 0;
}

