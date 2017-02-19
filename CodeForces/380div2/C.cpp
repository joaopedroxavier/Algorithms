//
//	(C - Road to Cinema)
//	CodeForces Round #380 Div.2 (Based on Technocup 2017 - Elimination Round 2)
//	source: http://codeforces.com/contest/738/problem/C
//
#include <bits/stdc++.h>

using namespace std;

#define make_pair mp
#define push_back pb

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e6;

bool has_time(ll tank, ll length[], ll p, ll nec_time){
	ll cost=0;
	for(int i=0;i<p;++i){
		if(length[i]>tank) return false;
		else if (2*length[i]<=tank) cost+=length[i];
		else cost+=(3*length[i]-tank);
	}
	if(cost>nec_time) return false;
	else return true;
}

pair<ll,ll> car[N];
ll gas[N], dist[N];
ll n, k, s, t;
int main(){
	//code here
	ll p1, p2, m, aux;
	ll minm;
	scanf("%lli %lli %lli %lli", &n, &k, &s, &t);
	p1 = 0, p2 = n-1;
	for(int i=0;i<n;++i) scanf("%lli %lli", &car[i].second, &car[i].first);
	for(int i=0;i<k;++i) scanf("%lli", &gas[i]);
	sort(gas,gas+k);
	sort(car,car+n);
	dist[0] = gas[0];
	for(int i=1;i<k;++i) dist[i] = gas[i] - gas[i-1];
	dist[k] = s - gas[k-1];
	if(has_time(car[n-1].first, dist, k+1, t)) aux = car[n-1].first;
	else{
		printf("-1\n");
		return 0;
	}
	while(p1<=p2){
		m = (p1+p2)/2;
		(has_time(car[m].first, dist, k+1, t)) ? (p2 = m-1 , aux = m) : p1=m+1;
	}
	m = aux;
	minm = car[n-1].second;
	for(int i=m;i<n;++i)	if(car[i].second<minm) minm=car[i].second;
	printf("%lli\n", minm);
	return 0;
}

