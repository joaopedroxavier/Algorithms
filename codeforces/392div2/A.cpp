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

int welf[N];

int main(){
	ios_base::sync_with_stdio(false);
	int n, ans=0, m=0;
	cin >> n;
	for(int i=0;i<n;++i) cin >> welf[i];
	for(int i=0;i<n;++i) m = max(m, welf[i]);
	for(int i=0;i<n;++i) ans += m-welf[i];

	cout << ans << endl;
	return 0;
}

