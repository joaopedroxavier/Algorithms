//
//	(C - Alyona and mex)
//	Codeforces Round #381 Div.2
//	source: http://codeforces.com/contest/740/problem/C
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e6;

int main(){
	int n, m, l, r, ans=N;
	cin >> n >> m;
	for(int i=0;i<m;++i){
		cin >> l >> r;
		ans = min(ans, r-l+1);
	}
	cout << ans << endl;
	for(int i=0;i<n;++i)	cout << i%ans << ' ';
	cout << endl;
	return 0;
}

