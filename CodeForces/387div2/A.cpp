//
//	(A - Display Size)
//	CodeForces Round #387 Div.2
//	source: http://codeforces.com/contest/747/problem/A
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
	int n, ans;
	cin >> n;
	for(int i=1;i*i<=n;++i) if (n%i == 0) ans = i;
	cout << ans _ n/ans << endl;
	return 0;
}

