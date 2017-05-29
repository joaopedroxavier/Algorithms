//
// B - Santa Claus and Keyboard Check
// CodeForces Round #389 Div.2
// Source: http://codeforces.com/contest/752
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

map<char, char> m;
map<char, int> vis;
int cont;

int main(){
	ios::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	int n = a.size();
	for(int i=0;i<n;++i){
		if(m.count(a[i]) and m[b[i]] != a[i]){ cout << -1 << endl; return 0; }
		if(m.count(b[i]) and m[a[i]] != b[i]){ cout << -1 << endl; return 0; }
		if(a[i]!=b[i] and !m.count(a[i])) cont++;
		m[a[i]] = b[i], m[b[i]] = a[i];
	}
	cout << cont << endl;
	for(auto it=m.begin();it!=m.end();++it){
		char u = it->first, v = it->second;
		if(!vis[u] and u!=v){ cout << u _ v << endl; vis[u] = vis[v] = 1; }
	}
	return 0;
}

