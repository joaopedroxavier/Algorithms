//
//	(A - Hongcow Learns the Cyclic Shift)
//	CodeForces Round #385 Div.2
//	source: http://codeforces.com/contest/745/problem/A
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

int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	vector<int> help;
	int n = (int)s.size();
	int ans = n;
	for(int i=1;i<=n;++i) if(n%i==0) help.pb(i);
	for(int i=0;i<(int)help.size();++i){
		bool sim = true;
		int l = n/help[i];
		string a = s.substr(0,l);
		for(int j=1;j<help[i];++j){
			string b = s.substr(j*l,l);
			if(b!=a) sim = false;
		}
		if(sim) ans = n/help[i];
	}
	cout << ans << endl;
	return 0;
}

