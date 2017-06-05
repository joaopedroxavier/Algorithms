#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e5+5;
const int MOD=1e4;
const int INF=0x3f3f3f3f;

vector<vll> mult(vector<vll> a, vector<vll> b, int n){
	vector<ll> v(n, 0);
	vector<vll> ans(n, v);
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) for(int k=0;k<n;++k){
		ans[i][j] = (ans[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
	}
	return ans;
}

vector<vll> square(vector<vll> a, int n){
	return mult(a, a, n);
}

vector<vll> exp(vector<vll> a, ll ex, int n){
	vector<ll> v(n, 0);
	vector<vll> ans(n, v);
	for(int i=0;i<n;++i) ans[i][i] = 1;

	while(ex) {
		if(ex&1) ans = mult(ans, a, n);
		a = square(a, n);
		ex /= 2;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	while(1){
		ll n, l;
		cin >> n >> l;
		if(cin.eof()) break;

		int s, t;
		cin >> s >> t;
	
		vector<ll> v (n, 0);
		vector<vll> m (n, v);
	
		for(int i=0;i<n;++i){
			for(int j=0;j<4;++j){
				int p;
				cin >> p;
				m[i][p-1]++;
			}
		}
	
		cout << exp(m, l, n)[s-1][t-1] << endl;
	}
	return 0;
}

