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
const int N=1e4+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int p[N], s[N];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;++i) cin >> p[i];
	for(int i=0;i<m;++i){
		int l, r, x, sl=0, sr=0;
		cin >> l >> r >> x;
		for(int j=l;j<=r;++j) sl += (p[j] < p[x]), sr += (p[j] > p[x]);
		cout << ((sl == x - l and sr == r - x) ? "Yes" : "No") << endl;
	}
	return 0;
}

