//	The REAL solution to problem (U) - Mismatched Socks.
//
//	Problem U - Mismatched Socks
//	Pacific Northwest Region Programming Contest
//	Division 2
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

ll v[N];
int main(){
	int n;
	ll t=0, ans;
	cin >> n;
	for(int i=0;i<n;++i){
		cin >> v[i];
		t+=v[i];
	}
	sort(v,v+n);
	(v[n-1]>t/2) ? ans = t - v[n-1] : ans = t/2;
	cout << ans << endl;
	return 0;
}

