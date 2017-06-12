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
const int N=1e2+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int buil[N][N];
int l[N], r[N], walkl[N], walkr[N];
int lastf;

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	m+=2;

	for(int i=n;i>=1;--i){
		for(int j=0;j<m;++j){
			char c;
			cin >> c;
			buil[i][j] = c - '0';
			if(buil[i][j]){
				if(!l[i]) l[i] = j;
				r[i] = j;
				lastf = max(lastf, i);
			}
		}
		if(!l[i]) l[i] = m-1, r[i] = 0;
	}

	walkl[1] = 2*r[1] + 1;
	walkr[1] = m;

	for(int i=2;i<lastf;++i){
		walkl[i] = 1 + min(walkl[i-1] + 2*r[i], walkr[i-1] + m-1);
		walkr[i] = 1 + min(walkl[i-1] + m-1, walkr[i-1] + 2*(m-1-l[i]));
	}
	
	walkr[0] = m;

	cout << min(walkl[lastf-1] + r[lastf], walkr[lastf-1] + m-1-l[lastf]) << endl;

	return 0;
}

