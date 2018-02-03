//
//	(Bathroom Stalls)
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

priority_queue<pair<ll,ll> > hand;
map<pair<ll,ll>, ll> how_many;
ll k, query;
pair<ll,ll> ans;

void prnt(pair<ll, ll> p){
	ll mi = min(p.first, p.second);
	ll mx = max(p.first, p.second);
	cout << "Case #" << query << ": " << mx _ mi << endl;
}

void count(ll n, pair<ll,ll> p1){
		if(n%2 == 0){
			pair<ll,ll> p = mp(n/2-1, n/2), q = mp(0,0);
			if(p >= q){
				if(!how_many[p]) hand.push(p);
				how_many[p] += how_many[p1];
			}
		}
		else{
			pair<ll,ll> p = mp(n/2, n/2), q = mp(0,0);
			if(p >= q){
				if(!how_many[p]) hand.push(p);
				how_many[p] += how_many[p1];
			}
		}
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for(query=1;query<=t;++query){
		ll n;
		cin >> n >> k;
		while(!hand.empty()) hand.pop();
		how_many.clear();
		if(n%2 == 0){
			pair<ll,ll> p = mp(n/2-1, n/2);
			hand.push(p);
			how_many[p] = 1;
		}
		else{
			pair<ll,ll> p = mp(n/2, n/2);
			hand.push(p);
			how_many[p] = 1;
		}
		while(k>0){
			pair<ll,ll> p = hand.top();
			ans = p;
			hand.pop();
			count(p.first, p);
			count(p.second, p);
			k -= how_many[p];
		}
		prnt(ans);
	}
	return 0;
}

