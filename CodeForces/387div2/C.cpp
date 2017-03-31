//
//	(C - Servers)
//	CodeForces Round #387 Div.2
//	source: http://codeforces.com/contest/747/problem/C
//
#include <bits/stdc++.h>

using namespace std;

#define topper top //WE ARE TOPPER

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << ",  " <<

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

int server[N];
int main(){
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i=0;i<q;++i){
		int t, k, d;
		ll sum = 0, cont=0;
		cin >> t >> k >> d;
		for(int j=1;j<=n;++j) if(server[j]<t) cont++;
		if(cont<k) cout << -1 << endl;
		else{
			cont = 0;
			for(int j=1;j<=n;++j) if(server[j]<t and cont<k) server[j]=t+d-1, sum+=j, cont++;
			cout << sum << endl;
		}
	}
	return 0;
}

