//
// C - Dasha and Password
// CodeForces Round #394 Div.2
// Source: http://codeforces.com/contest/761
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

string key[N];
int n, m; 
ll ans = INF;
ll numb[N], cha[N], spec[N];

void calc(int i){
	int minn=INF, minl=INF, mins=INF;
	for(int j=0;j<m;++j){
		if(key[i][j] <= '9' and key[i][j] >= '0') minn = min(min(minn, j), m-j);
		else if (key[i][j] <= 'z' and key[i][j] >= 'a') minl = min(min(minl, j), m-j);
		else mins = min(min(mins, j), m-j);
	}
	numb[i] = minn, cha[i] = minl, spec[i] = mins;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=0;i<n;++i) cin >> key[i];
	for(int i=0;i<n;++i) calc(i);
	for(int i=0;i<n;++i) for(int j=0;j<n;++j) for(int k=0;k<n;++k){
		if(i!=j and i!=k and j!=k) ans = min(ans, numb[i]+cha[j]+spec[k]);
	}
	cout << ans << endl;
	return 0;
}

