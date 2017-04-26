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
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int main(){
	ios_base::sync_with_stdio(false);
	int t, ans;
	cin >> t;
	for(int i=0;i<t;++i){
		int n, mx = 0;
		cin >> n;
		for(int j=0;j<n;++j){
			int u, v;
			cin >> u >> v;
			mx = max(mx, u+v);
		}
		ans = 240 - mx - 10;
		cout << max(ans, 0) << endl;
	}
	return 0;
}

