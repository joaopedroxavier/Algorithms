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
#define _ << ' ' <<

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int,int> ii;
typedef stack<int> sti;

const int N=1e6;
const int INF=0x3f3f3f3f;

map<int, int> par;
ll l[N], r[N];

int main(){
	ios_base::sync_with_stdio(false);
	stack<int> st;
	string s, fol;
	int n, m, p, cont=0;
	cin >> n >> m >> p;
	cin >> s;
	cin >> fol;
	for(char u : s){
		if(u=='(') st.push(cont);
		else{
			par[st.topper()] = cont;
			par[cont] = st.topper();
			st.pop();
		}
		cont++;
	}
	for(int i=1;i<n;++i) l[i] = i-1;
	for(int i=0;i<n-1;++i) r[i] = i+1;
	l[0] = INF, r[n-1] = INF;
	p--;
	int point = 0;
	for(char u : fol){
		if(u == 'R'){
			p=r[p];
		}
		else if(u == 'L'){
			p=l[p];
		}
		else{
			int p1 = min(p, par[p]);
			int p2 = max(p, par[p]);
			if(l[p1] == INF){
				l[r[p2]] = INF;
				point = r[p2];
				p = r[p2];
			}
			else if(r[p2] == INF){
				r[l[p1]] = INF;
				p = l[p1];
			}
			else{
				l[r[p2]] = l[p1];
				r[l[p1]] = r[p2];
				p = r[p2];
			}
		}
	}
	while(point!=INF){
		cout << s[point];
		point = r[point];
	}
	cout << endl;
	return 0;
}

