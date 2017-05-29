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
const int N=5e2+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int w[N][N], b[N][N], n, p;
int answ, ansb;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> p;
	for(int i=0;i<p;++i){
		int x, y;
		cin >> x >> y;
		b[x][y] = 1;
	}
	for(int i=0;i<p;++i){
		int x, y;
		cin >> x >> y;
		w[x][y] = 1;
	}

	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j){
		w[i][j] += w[i-1][j] + w[i][j-1] - w[i-1][j-1];
		b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
	}

	for(int k=1;k<=n;++k){
		for(int i=k;i<=n;++i) for(int j=k;j<=n;++j){
			int qw = w[i][j] - w[i-k][j] - w[i][j-k] + w[i-k][j-k];
			int qb = b[i][j] - b[i-k][j] - b[i][j-k] + b[i-k][j-k];
			answ += (qw != 0 and qb == 0);
			ansb += (qb != 0 and qw == 0);
		}
	}
	cout << ansb _ answ << endl;

	return 0;
}

