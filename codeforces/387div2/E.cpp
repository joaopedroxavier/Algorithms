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
const int N=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

string s;
vi ans[N];
vs aux;
int p, cont, p1, vis[N], p2;
vi comm, dg;
void gen(int d){
	ans[d].pb(p1);
	vis[p1]=1;
	p2 = max(p2, d);
	int sons = dg[p1];
	p1++;
	for(int i=1;i<=sons;++i) gen(d+1);
}

int main(){
	ios::sync_with_stdio(false);
	cin >> s;
	for(int i=0;i<(int)s.size();++i){
		if(s[i] == ','){
			cont++;
			if(!(cont%2))comm.pb(i);
		}
	}
	for(int i : comm) aux.pb(s.substr(p,i-p)), p=i+1;
	aux.pb(s.substr(p, s.size()-p));
	for(int i=0;i<(int)aux.size();++i) dg.pb((int)(aux[i].at((aux[i].size())-1)-'0'));
	for(int i=0;i<(int)aux.size();++i) aux[i] = aux[i].substr(0,aux[i].size()-2);;
//	for(string a : aux) cout << a << endl;
	for(int i=0;i<(int)aux.size();++i) if(!vis[i]) gen(0);
	cout << p2+1 << endl;
	for(int i=0;i<p2+1;++i){
		cout << aux[ans[i][0]];
		for(int j=1;j<(int)ans[i].size();++j) cout << " " << aux[ans[i][j]];
		cout << endl;
	}
	return 0;
}

