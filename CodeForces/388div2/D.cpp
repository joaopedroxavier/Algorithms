//
//	(D - Leaving Auction)
//	CodeForces Round #388 Div.2
//	source: http://codeforces.com/contest/749/problem/D
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
const int N=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

set<ii> best_offer;
vi offers[N];;
vi v;
int main(){
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n;
	for(int i=0;i<n;++i){
		int u, v;
		cin >> u >> v;
		offers[u].pb(v);
	}
	for(int i=1;i<=n;++i){
		if(!offers[i].empty()) best_offer.insert(mp(offers[i][offers[i].size()-1], i));
	}
	cin >> q;
	for(int i=0;i<q;++i){
		int u;
		cin >> u;
		v.clear();
		for(int j=0;j<u;++j){
			int w;
			cin >> w;
			if(!offers[w].empty()) v.pb(w);
		}
		for(int j=0;j<(int)v.size();++j){
			best_offer.erase(mp(offers[v[j]][offers[v[j]].size()-1], v[j]));
		}
		ll ansp = 0;
		ll ansb = 0;
		if(!best_offer.empty()){
			auto it = prev(best_offer.end());
			ansp = (*it).second;
			ansb = offers[ansp][0];
		}
		if(best_offer.size()>1){
			auto it = prev(best_offer.end());
			ansb = *(upper_bound(offers[ansp].begin(), offers[ansp].end(), ((*prev(it)).first))); //o shit
		}
		for(int j=0;j<(int)v.size();++j){
			best_offer.insert(mp(offers[v[j]][offers[v[j]].size()-1], v[j]));
		}
		cout << ansp << " " << ansb << endl;
	}
	return 0;
}

