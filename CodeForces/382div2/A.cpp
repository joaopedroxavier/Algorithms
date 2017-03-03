//
//	(A - Ostap and Grasshopper)
//	CodeForces Round #382 Div.2
//	source: http://codeforces.com/contest/735/problem/A
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e6;

int main(){
	int n, p, f, l;
	char t = 'T';
	bool found = false;
	string s;
	cin >> n >> p >> s;
	f = min(s.find("G"), s.find("T"));
	l = max(s.find("G"), s.find("T"));
	if(s.find("G")>s.find("T")) t = 'G';
	for(unsigned i=f; i<=l; i+=p){
		if(s[i]=='#'){
			cout << "NO" << endl;
			found = true;
			break;
		}
		else if(s[i]==t){
			cout << "YES" << endl;
			found = true;
			break;
		}
	}
	if(!found) cout << "NO" << endl;
	return 0;
}




