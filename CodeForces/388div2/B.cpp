//
//	(B - Parallelogram is Back)
//	CodeForces Round #388 Div.2
//	source: http://codeforces.com/contest/749/problem/B
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

ii pt[3];
void cycle(){
	swap(pt[0],pt[1]);
	swap(pt[1],pt[2]);
}

ii next(){
	ii p = mp(pt[2].first - pt[1].first, pt[2].second - pt[1].second);
	return mp(pt[0].first + p.first, pt[0].second + p.second);
}

int main(){
	ios_base::sync_with_stdio(false);
	for(int i=0;i<3;++i) cin >> pt[i].first >> pt[i].second;
	cout << 3 << endl;
	for(int i=0;i<3;++i){
		cout << next().first _ next().second << endl;
		cycle();
	}
	return 0;
}

