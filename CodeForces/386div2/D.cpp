//
//	(D - Green and Black Tea)
//	CodeForces Round #386 Div.2
//	source: http://codeforces.com/contest/746/problem/D
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

char tea[] = {'G', 'B'};
int main(){
	ios::sync_with_stdio(false);
	ll n, k, a, b;
	cin >> n >> k >> a >> b;
	if(a>(b+1)*k or b>(a+1)*k) cout << "NO" << endl;
	else{
		if(a>b) swap(a,b), tea[0] = 'B', tea[1] = 'G';
		while(a<b and a and b){
			for(ll i=0;i<min(k,b-a+1);++i) cout << tea[1];
			for(ll i=0;i<min(a,(ll)1);++i) cout << tea[0];
			b-=min(k,b-a+1);
			a--;
		}
		while(b or a){
			if(b>0 and a>0){
				cout << tea[1] << tea[0];
				b--, a--;
			}
			else if(b>0){
				cout << tea[1];
				b--;
			}
			else{
				cout << tea[0];
				a--;
			}
		}
		cout << endl;
	}
	return 0;
}

