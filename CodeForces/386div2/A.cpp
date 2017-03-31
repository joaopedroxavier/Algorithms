//
//	(A - Compote)
//	CodeForces Round #386 Div.2
//	source: http://codeforces.com/contest/746/problem/A
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define _ << ' ' <<

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e5;
const int INF=0x3f3f3f3f;

int main(){
	ios::sync_with_stdio(false);
	ll a, b, c, ans=0;
	cin >> a >> b >> c;
	while(a>=1 and b>=2 and c>=4){
		ans+=7;
		a-=1;
		b-=2;
		c-=4;
	}
	cout << ans << endl;
	return 0;
}

