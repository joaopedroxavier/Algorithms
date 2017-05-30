//
// B - Dasha and Friends
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
const int N=1e2+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

vector<int> k, s;

int main(){
	ios_base::sync_with_stdio(false);
	int n, l;
	cin >> n >> l;
	vi kefa(n), sasha(n);
	for(int i=0;i<n;++i) cin >> kefa[i];
	for(int i=0;i<n;++i) cin >> sasha[i];

	for(int i=0;i<n-1;++i){
		k.pb(kefa[i+1]-kefa[i]);
		s.pb(sasha[i+1]-sasha[i]);
	}

	k.pb(l - kefa[n-1] + kefa[0]);
	s.pb(l - sasha[n-1] + sasha[0]);

	bool ans = false;
	for(int i=0;i<n;++i){
		bool ans2 = true;
		for(int j=0;j<n;++j)	if(k[j] != s[(i+j)%n])	ans2 = false;
		if(ans2) ans = true;
	}

	cout << ((ans) ? "YES" : "NO") << endl;
	return 0;
}

