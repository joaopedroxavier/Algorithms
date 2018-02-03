//
//
//
//
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

priority_queue<ll> type;
int main(){
	ios::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	for(int i=0; i<n;++i){
		int u;
		cin >> u;
		type.push(u);
	}
	int cont = 0;
	while(!type.empty()){
		cont++;
		ll a = type.top();
		type.pop();
		if(a > 2*k) type.push((a-2*k));
		else{
			if(a > k)	type.push(a-k);
			if(!type.empty()){
				int b = type.top();
				type.pop();
				if(b > k) type.push(b-k);
			}
		}
	}
	cout << cont << endl;
	return 0;
}

