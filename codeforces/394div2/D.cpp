//
// D - Dasha and Very Difficult Problem
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

int a[N], b[N], comp[N], ord[N], c[N], n, l, r, ans=1;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> l >> r;
	for(int i=0;i<n;++i) cin >> a[i];

	for(int i=0;i<n;++i) cin >> comp[i];

	for(int i=0;i<n;++i) ord[i] = i;

	sort(ord, ord+n, [](int a, int b){ return (comp[a] < comp[b]); } );

	for(int i=0;i<n;++i) b[i] = l;

	c[ord[0]] = b[ord[0]] - a[ord[0]];

	for(int i=1;i<n;++i){
		c[ord[i]] = b[ord[i]] - a[ord[i]];
		if(c[ord[i]] <= c[ord[i-1]]) b[ord[i]] += c[ord[i-1]] - c[ord[i]] + 1,	c[ord[i]] = c[ord[i-1]] + 1; 
		if(b[ord[i]] > r){ ans = 0; break; }
	}

	if(ans) for(int i=0;i<n;++i) cout << b[i] << ' ';
	else cout << -1;
	cout << endl;
	return 0;

}

