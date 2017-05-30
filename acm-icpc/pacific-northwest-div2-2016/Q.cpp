//
//	Problem Q	- Contest Score
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

unsigned minm(unsigned a, unsigned b){
	return ((a < b) ? a : b);
}

vector<ll> t, ans;
int main(){
	unsigned n, k, p;
	ll m=INF, sum=0;
	cin >> n >> k;
	for(unsigned i=0;i<n;++i){
		ll u;
		cin >> u;
		t.pb(u);
	}
	ans.pb(0);
	while(!t.empty()){
		m = INF;
		for(unsigned i=0; i<minm(k,t.size());++i){
			if(t[i]<m){
				m = t[i];
				p = i;
			}
		}
		t.erase(t.begin()+p);
		m = m + ans.back();
		ans.pb(m);
	}
	for(unsigned i=0;i<ans.size();++i) sum += ans[i];
	cout << sum << endl;
}

