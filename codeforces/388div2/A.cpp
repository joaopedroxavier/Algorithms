//
//	(A - Bachgold Problem)
//	CodeForces Round #388 Div.2
//	source:	http://codeforces.com/contest/749/problem/A
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

vi ans;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	while(n){
		if(n==3){
			ans.pb(3);
			n-=3;
		}
		else{
			ans.pb(2);
			n-=2;
		}
	}
	cout << ans.size() << endl;
	cout << ans[0];
	for(int i=1;i<(int)ans.size();++i) cout << " " << ans[i];
	cout << endl;
	return 0;
}

