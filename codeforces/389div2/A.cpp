//
// A - Santa Claus and a Place in a Class
// CodeForces Round #389 div.2
// Source: http://codeforces.com/contest/752
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

int main(){
	ios::sync_with_stdio(false);
	ll n, m, k, cont=1;
	cin >> m >> n >> k;
	for(int i=1;i<=m;++i){
		bool cond = false;
		for(int j=1;j<=n;++j){
			if((k+1)/2 == cont){
				cout << i _ j << ' ';
				cout << ((k%2) ? 'L' : 'R') << endl;
				cond = true;
				break;
			}
			else cont++;
		}
		if(cond) break;
	}
	return 0;
}

