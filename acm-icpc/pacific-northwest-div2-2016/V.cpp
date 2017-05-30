//
//	Problem V - Postman
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

pair<ll,ll> post[N];
vector<pair<ll,ll> > path1, path2;
queue<pair<ll,ll> > q1, q2;
int main(){
	ios::sync_with_stdio(false);
	int n, k;
	ll t=0;
	cin >> n >> k;
	for(int i=0;i<n;++i) cin >> post[i].first >> post[i].second;
	sort(post,post+n);
	for(int i=0;i<n;++i){
		if(post[i].first < 0) path1.pb(mp(post[i].first, post[i].second));
		else path2.pb(mp(-post[i].first, post[i].second));
	}
	sort(path1.begin(),path1.end());
	sort(path2.begin(),path2.end());
	for(int i=0;i<(int)path1.size();++i) q1.push(mp(-path1[i].first, path1[i].second));
	for(int i=0;i<(int)path2.size();++i) q2.push(mp(-path2[i].first, path2[i].second));
	while(!q1.empty()){
		ll cap = k;
		ll t1 = (q1.front()).first;
		if(cap < (q1.front()).second){
			ll r = (q1.front()).second / cap;
			(q1.front()).second -= cap*r;
			t += 2*r*t1;
		}
		if(q2.front().second == 0) q2.pop();
		else{
			while(cap>0 and !q1.empty()){
				ll aux = cap;
				cap -= min(cap,(q1.front()).second);
				if(cap>0) q1.pop();
				else (q1.front()).second -= aux;
			}
			t+=2*t1;
		}
	}
	while(!q2.empty()){
		ll cap = k;
		ll t1 = (q2.front()).first;
		if(cap < (q2.front()).second){
			ll r = (q2.front()).second / cap;
			(q2.front()).second -= cap*r;
			t += 2*r*t1;
		}
		if(q2.front().second == 0) q2.pop();
		else{
			while(cap>0 and !q2.empty()){
				ll aux = cap;
				cap -= min(cap,(q2.front()).second);
				if(cap>0) q2.pop();
				else (q2.front()).second -= aux;
			}
			t += 2*t1;
		}
	}
	cout << t << endl;
	return 0;
}

