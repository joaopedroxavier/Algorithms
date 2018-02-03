//
//	(Overside Pancake Flipper)
//	Google Code Jam 2017 - Qualification Round
//	source: https://code.google.com/codejam/contest/3264486/dashboard
//
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

int inverse(int i){
	return ((i+1)%2);
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int q=1;q<=t;++q){
		string a;
		vi b;
		int k, nplus=0, nminus=0, ans=0;
		cin >> a >> k;
		for(int i=0; i<(int)a.size(); ++i){
			if(a[i] == '+') nplus++, b.pb(1);
			else nminus++, b.pb(0);
		}
		cout << "Case #" << q <<": ";
		for(int i=0; i<=((int)b.size()-k);++i){
			if(b[i] == 0){
				ans++;
				for(int j=0;j<k;++j) b[i+j] = inverse(b[i+j]);
			}
		}
		bool is_possible = true;
		for(int i=1;i<=k;++i){
			if(b[b.size()-i] == 0) is_possible = false;
		}
		if(is_possible) cout << ans << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}

